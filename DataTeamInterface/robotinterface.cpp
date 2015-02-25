#include "robotinterface.h"

/**
 * @brief RobotInterface::RobotInterface
 * @param ui
 */
RobotInterface::RobotInterface(Ui::MainWindow* ui)
{
    m_pUi = ui;
    m_pProtocole = new Protocole();
    m_pGps = new GPS(m_pProtocole);
    m_pGyro = new Gyro(m_pProtocole);
    m_pJoystick = new Joystick(m_pProtocole);
    m_pActuator = new Actuator(m_pProtocole);
    m_pAccelero = new Accelero(m_pProtocole);
    m_pLidar = new Lidar(m_pProtocole);
    //m_pMagneto = new Magneto(m_pProtocole);
    m_pOdo = new Odo(m_pProtocole);
    m_pMotor = new Motor(m_pProtocole);
    //m_pRemote = new Remote(m_pProtocole);
    m_pMagneto = new Magneto(m_pProtocole);

    connect(m_pGps, SIGNAL(emitDataAvailable()), this, SLOT(slotOnGpsDataAvailable()));
    connect(m_pGyro, SIGNAL(emitDataAvailable()), this, SLOT(slotOnGyroDataAvailable()));
    connect(m_pActuator, SIGNAL(emitDataAvailable()), this, SLOT(slotOnActuatorDataAvailable()));
    connect(m_pAccelero, SIGNAL(emitDataAvailable()), this, SLOT(slotOnAcceleroDataAvailable()));
    connect(m_pLidar, SIGNAL(emitDataAvailable()), this, SLOT(slotOnLidarDataAvailable()));
//    connect(m_pMagneto, SIGNAL(emitDataAvailable()), this, SLOT(slotOnMagnetoDataAvailable());
    connect(m_pOdo, SIGNAL(emitDataAvailable()), this, SLOT(slotOnOdoDataAvailable()));
//    connect(m_pRemote, SIGNAL(emitDataAvailable()), this, SLOT(slotOnRemoteDataAvailable()));
    connect(m_pMagneto, SIGNAL(emitDataAvailable()), this, SLOT(slotOnMagnetoDataAvailable()));
}

/**
 * @brief RobotInterface::~RobotInterface
 */
RobotInterface::~RobotInterface()
{

}

/*******************************************************************************/
/********************************** METHOD *************************************/
/*******************************************************************************/

/**
 * @brief RobotInterface::connectRobot
 * @return
 */
bool RobotInterface::connectRobot()
{
    m_pGps->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->gpsPort->text().toInt());
    m_pGyro->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->gyroPort->text().toInt());
    m_pJoystick->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->motorPort->text().toInt());
    m_pActuator->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->actuatorPort->text().toInt());
    m_pLidar->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->lidarPort->text().toInt());
//    m_pMagneto->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->magnetoPort->text().toInt());
    m_pMotor->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->motorPort->text().toInt());
    m_pOdo->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->odoPort->text().toInt());
//    m_pRemote->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->remotePort->text().toInt());
    m_pAccelero->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->acceleroPort->text().toInt());
    m_pMagneto->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->magnetoPort->text().toInt());

    return true;
}

/*******************************************************************************/
/********************************** SLOT ***************************************/
/*******************************************************************************/

/**
 * @brief RobotInterface::slotOnGpsDataAvailable
 */
void RobotInterface::slotOnGpsDataAvailable()
{
    m_pUi->altitudeResult->setText(QString::number(m_pGps->getAltitude()));
    m_pUi->longitudeResult->setText(QString::number(m_pGps->getLongitude()));
    m_pUi->latitudeResult->setText(QString::number(m_pGps->getLatitude()));
    m_pUi->qualityResult->setText(m_pGps->getQuality());
}

/**
 * @brief RobotInterface::slotOnGyroDataAvailable
 */
void RobotInterface::slotOnGyroDataAvailable()
{
    m_pUi->gyroXResult->setText(QString::number(m_pGyro->getXGyro()));
    m_pUi->gyroYResult->setText(QString::number(m_pGyro->getYGyro()));
    m_pUi->gyroZResult->setText(QString::number(m_pGyro->getZGyro()));
}

/**
 * @brief RobotInterface::slotOnActuatorDataAvailable
 */
void RobotInterface::slotOnActuatorDataAvailable()
{
    m_pUi->actuatorResult->setText(QString::number(m_pActuator->getActuator()));
}

/**
 * @brief RobotInterface::slotOnAcceleroDataAvailable
 */
void RobotInterface::slotOnAcceleroDataAvailable()
{
    m_pUi->acceleroXResult_2->setText(QString::number(m_pAccelero->getXAccelero()));
    m_pUi->acceleroYResult_2->setText(QString::number(m_pAccelero->getYAccelero()));
    m_pUi->acceleroZResult_2->setText(QString::number(m_pAccelero->getZAccelero()));
}

void RobotInterface::slotOnLidarDataAvailable()
{

}

void RobotInterface::slotOnOdoDataAvailable()
{
    m_pUi->fl->setText(QString::number(m_pOdo->getFrontLeft()));
    m_pUi->fr->setText(QString::number(m_pOdo->getFrontRight()));
    m_pUi->rl->setText(QString::number(m_pOdo->getRearLeft()));
    m_pUi->rr->setText(QString::number(m_pOdo->getRearRight()));
}

void RobotInterface::slotOnRemoteDataAvailable()
{
}
void RobotInterface::slotOnMagnetoDataAvailable()
{
//    m_pUi->acceleroXResult_2->setText(QString::number(m_pAccelero->getXAccelero()));
//    m_pUi->acceleroYResult_2->setText(QString::number(m_pAccelero->getYAccelero()));
//    m_pUi->acceleroZResult_2->setText(QString::number(m_pAccelero->getZAccelero()));
}


void RobotInterface::on_pbDroite_clicked()
{
   /* QByteArray baValue;

    if(p_InputState.leftThumbY != m_fOldLeftStickValueY || p_InputState.leftThumbX != m_fOldLeftStickValueX)
    {
        m_fOldLeftStickValueY = p_InputState.leftThumbY;
        m_fOldLeftStickValueX = p_InputState.leftThumbX;

        if(p_InputState.leftThumbY != 0)
        {
            if(p_InputState.leftThumbX > 0)
            {
                float DatasendToMotorRight = p_InputState.leftThumbY * 127 * (1-((p_InputState.leftThumbX + 1)/2));
                baValue[1] = DatasendToMotorRight;
                float DatasendToMotorLeft = p_InputState.leftThumbY * 127 * ((p_InputState.leftThumbX + 1)/2);
                baValue[0] = DatasendToMotorLeft;

            }
            else if(p_InputState.leftThumbX < 0)
            {
                float DatasendToMotorLeft = m_fOldLeftStickValueY * 127 * (1+((p_InputState.leftThumbX - 1)/2));
                baValue[0] = DatasendToMotorLeft;
                float DatasendToMotorRight = m_fOldLeftStickValueY * 127 * (-(p_InputState.leftThumbX - 1)/2);
                baValue[1] = DatasendToMotorRight;
            }
        }
    }
    SendData(baValue);*/
    QByteArray baValue;

    m_pUi->labelDemitour->setText("Demi tour in process");


    for(int i=0;i<=10;i++)
    {
        baValue[0] = 0;
        baValue[0] = 127;
        m_pMotor->SendData(baValue);
    }

    m_pUi->labelDemitour->setText("Unused");
}
