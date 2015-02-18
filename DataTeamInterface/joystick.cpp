#include "joystick.h"

Joystick::Joystick(QObject *parent) :
    QObject(parent)
{
    m_pController = new SimpleXbox360Controller(0); // Instaciation

    m_fOldStickValue = 0;

    m_pController->startAutoPolling(20); // Update appelé toutes les 20 milisecondes

    connect(m_pController, SIGNAL(controllerConnected(uint)), this, SLOT(slotOnControllerConntected(uint)));
    connect(m_pController, SIGNAL(controllerDisconnected(uint)), this, SLOT(slotOnControllerDisconntected(uint)));
    connect(m_pController, SIGNAL(controllerNewState(SimpleXbox360Controller::InputState), this, SLOT(SimpleXbox360Controller::InputState))



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
    if(p_InputState.leftThumbY != m_fOldStickValue)
    {
        QByteArray baValue;


        m_fOldStickValue = p_InputState.leftThumbY;
        float Datasend = m_fOldStickValue * 255;
        baValue[0] = Datasend;
        baValue[1] = Datasend;


        emit baValue;
    }

}
