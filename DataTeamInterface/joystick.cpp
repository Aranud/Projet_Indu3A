#include "joystick.h"

/**
 * @brief Joystick::Joystick
 * @param parent
 */
Joystick::Joystick(QObject *parent) :
    QObject(parent)
{
    m_pController = new SimpleXbox360Controller(0); // Instanciation

    m_fOldLeftStickValueY = 0;
    m_fOldLeftStickValueX = 0;
    m_fOldRightStickValueY = 0;
    m_fOldRightStickValueX = 0;

    m_pController->startAutoPolling(AUTO_POLLING_TIME_ELASPE); // Update appelé toutes les 20 milisecondes

    connect(m_pController, SIGNAL(controllerConnected(uint)), this, SLOT(slotOnControllerConntected(uint)));
    connect(m_pController, SIGNAL(controllerDisconnected(uint)), this, SLOT(slotOnControllerDisconntected(uint)));
    connect(m_pController, SIGNAL(controllerNewState(SimpleXbox360Controller::InputState)), this, SLOT(slotOnEvent(SimpleXbox360Controller::InputState)));
}

/*******************************************************************************/
/*********************************** SLOT **************************************/
/*******************************************************************************/

/**
 * @brief Joystick::slotOnControllerConntected
 * @param p_iControllerNum
 */
void Joystick::slotOnControllerConntected(unsigned int p_iControllerNum)
{
    qDebug() << "Joystick ID : " << p_iControllerNum << "Connected";
}

/**
 * @brief Joystick::slotOnControllerDisconntected
 * @param p_iControllerNum
 */
void Joystick::slotOnControllerDisconntected(unsigned int p_iControllerNum)
{
    qDebug() << "Joystick ID : " << p_iControllerNum << "Disconnected";
}

/**
 * @brief Joystick::slotOnEvent - On Input Channge from Joystick, catch here and emit state formatted
 * @param p_InputState - New stat from Joystick
 * @return Void
 */
void Joystick::slotOnEvent(SimpleXbox360Controller::InputState p_InputState)
{
    qDebug() << "Enter here";
    qDebug() << "****** --> " << p_InputState.buttons;

    QByteArray baValue;
    baValue.append(((p_InputState.leftThumbX + 1)/2) * 255);
    baValue.append(((p_InputState.leftThumbY + 1)/2) * 255);
    baValue.append(((p_InputState.rightThumbY + 1)/2) * 255);
    baValue.append(((p_InputState.rightThumbY + 1)/2) * 255);

    int iButton = 0b00000000;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_DPAD_RIGHT))
        iButton += 0b00000001;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_DPAD_DOWN))
        iButton += 0b00000010;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_DPAD_LEFT))
        iButton += 0b00000100;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_DPAD_UP))
        iButton += 0b00001000;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_X))
        iButton += 0b00010000;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_A))
        iButton += 0b00100000;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_B))
        iButton += 0b01000000;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_Y))
        iButton += 0b10000000;

    baValue.append(iButton);

    iButton = 0b00000000;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_LEFT_SHOULDER))
        iButton += 0b00000001;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_LEFT_THUMB))
        iButton += 0b00000010;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_RIGHT_SHOULDER))
        iButton += 0b00000100;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_RIGHT_THUMB))
        iButton += 0b00001000;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_START))
        iButton += 0b00010000;
    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_BACK))
        iButton += 0b00100000;
//    if(p_InputState.isButtonPressed(XINPUT_)) // Boutton PS
//        baButton += 0b01000000;
//    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_Y))    // boutton USB
//        baButton += 0b10000000;

    baValue.append(iButton);

    baValue.append(p_InputState.leftTrigger * 255);
    baValue.append(p_InputState.rightTrigger * 255);

    baValue.append(0x7F);   //AccelX
    baValue.append(0x7F);   //AccelY
    baValue.append(0x7F);   //AccelZ

    baValue.append(0x7F);   //GyroX
    baValue.append(0x7F);   //GyroY
    baValue.append(0x7F);   //GyroZ

    qDebug() << "Data Emit From Joystick Event : " << baValue.toHex();
    emit dataReceivedFromStick(baValue);
}

/**
 * @brief Joystick::slotOnEvent - Deprecate
 * @param p_InputState
 */
//void Joystick::slotOnEvent(SimpleXbox360Controller::InputState p_InputState)
//{

//    if(p_InputState.leftThumbY != m_fOldLeftStickValueY || p_InputState.leftThumbX != m_fOldLeftStickValueX)
//    {
//        m_fOldLeftStickValueY = p_InputState.leftThumbY;
//        m_fOldLeftStickValueX = p_InputState.leftThumbX;

//        if(p_InputState.leftThumbY != 0)
//        {
//            if(p_InputState.leftThumbX > 0)
//            {
//                float DatasendToMotorRight = p_InputState.leftThumbY * 127 * (1-((p_InputState.leftThumbX + 1)/2));
//                baValue[1] = DatasendToMotorRight;
//                float DatasendToMotorLeft = p_InputState.leftThumbY * 127 * ((p_InputState.leftThumbX + 1)/2);
//                baValue[0] = DatasendToMotorLeft;
//                qDebug() << QString::number(baValue[0]).toInt();
//                qDebug() << QString::number(baValue[1]).toInt();

//            }
//            else if(p_InputState.leftThumbX < 0)
//            {
//                float DatasendToMotorLeft = m_fOldLeftStickValueY * 127 * (1+((p_InputState.leftThumbX - 1)/2));
//                baValue[0] = DatasendToMotorLeft;
//                float DatasendToMotorRight = m_fOldLeftStickValueY * 127 * (-(p_InputState.leftThumbX - 1)/2);
//                baValue[1] = DatasendToMotorRight;
//                qDebug() << QString::number(baValue[0]).toInt();
//                qDebug() << QString::number(baValue[1]).toInt();
//            }
//        }
//    }

//    if(p_InputState.rightThumbY != m_fOldRightStickValueY || p_InputState.rightThumbX != m_fOldRightStickValueX)
//    {
//        m_fOldRightStickValueY = p_InputState.leftThumbY;
//        m_fOldRightStickValueX = p_InputState.leftThumbX;

//        if(p_InputState.rightThumbY != 0)
//        {
//            if(p_InputState.rightThumbX > 0)
//            {
//                float DatasendToMotorRight = p_InputState.rightThumbY * 127 * (1-((p_InputState.rightThumbX + 1)/2));
//                baValue[1] = DatasendToMotorRight;
//                float DatasendToMotorLeft = p_InputState.rightThumbY * 127 * ((p_InputState.rightThumbX + 1)/2);
//                baValue[0] = DatasendToMotorLeft;
//                qDebug() << QString::number(baValue[0]).toInt();
//                qDebug() << QString::number(baValue[1]).toInt();
//            }
//            else if(p_InputState.leftThumbX < 0)
//            {
//                float DatasendToMotorLeft = p_InputState.rightThumbY * 127 * (1+((p_InputState.rightThumbX - 1)/2));
//                baValue[0] = DatasendToMotorLeft;
//                float DatasendToMotorRight = m_fOldStickValue * 127 * (-(p_InputState.rightThumbX - 1)/2);
//                baValue[1] = DatasendToMotorRight;
//                qDebug() << QString::number(baValue[0]).toInt();
//                qDebug() << QString::number(baValue[1]).toInt();
//            }
//        }
//    }


//    if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_DPAD_LEFT))
//    {
//           baValue[0]=0;
//           baValue[1]=127;

//    }else if(p_InputState.isButtonPressed(XINPUT_GAMEPAD_DPAD_RIGHT))
//    {
//           baValue[0]=127;
//           baValue[1]=0;
//    }
//}
