#include "joystick.h"

Joystick::Joystick(QObject *parent) :
    QObject(parent)
{
    m_pController = new SimpleXbox360Controller(0); // Instaciation

    m_fOldStickValue = 0;

    m_pController->startAutoPolling(20); // Update appelé toutes les 20 milisecondes

    qDebug() << "Construit";

    connect(m_pController, SIGNAL(controllerConnected(uint)), this, SLOT(slotOnControllerConntected(uint)));
    connect(m_pController, SIGNAL(controllerDisconnected(uint)), this, SLOT(slotOnControllerDisconntected(uint)));
    connect(m_pController, SIGNAL(controllerNewState(SimpleXbox360Controller::InputState)), this, SLOT(slotOnEvent(SimpleXbox360Controller::InputState)));
}

void Joystick::slotOnControllerConntected(unsigned int p_iControllerNum)
{
    qDebug() << "Joystick ID : " << p_iControllerNum << "Connected";
}

void Joystick::slotOnControllerDisconntected(unsigned int p_iControllerNum)
{
    qDebug() << "Joystick ID : " << p_iControllerNum << "Disconnected";
}

void Joystick::slotOnEvent(SimpleXbox360Controller::InputState p_InputState)
{
    qDebug() << "Enter here";

    qDebug() << "****** --> " << p_InputState.buttons;

    if(p_InputState.leftThumbY != m_fOldStickValue)
    //if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_LEFT_THUMB))
    {
        QByteArray baValue;

        m_fOldStickValue = p_InputState.leftThumbY;


        if(p_InputState.leftThumbX > 0)
        {
            float DatasendToMotorRight = m_fOldStickValue * 127 * (1-((p_InputState.leftThumbX + 1)/2));
            baValue[1] = DatasendToMotorRight;
            float DatasendToMotorLeft = m_fOldStickValue * 127 * ((p_InputState.leftThumbX + 1)/2);
            baValue[0] = DatasendToMotorLeft;
            qDebug() << QString::number(baValue[0]).toInt();
            qDebug() << QString::number(baValue[1]).toInt();
        }
        else
        {
            float DatasendToMotorLeft = m_fOldStickValue * 127 * (1+((p_InputState.leftThumbX - 1)/2));
            baValue[0] = DatasendToMotorLeft;
            float DatasendToMotorRight = m_fOldStickValue * 127 * (-(p_InputState.leftThumbX - 1)/2);
            baValue[1] = DatasendToMotorRight;
            qDebug() << QString::number(baValue[0]).toInt();
            qDebug() << QString::number(baValue[1]).toInt();
        }








        emit dataReceivedFromStick(baValue);
    }
}
