#include "robotinterface.h"

RobotInterface::RobotInterface(Ui::MainWindow* ui)
{
    m_pUi = ui;
    m_pProtocole = new Protocole();
    m_pGps = new GPS(m_pProtocole);
    m_pGyro = new Gyro(m_pProtocole);
    m_pJoystick = new Joystick(m_pProtocole);

     connect(m_pGps, SIGNAL(emitDataAvailable()), this, SLOT(slotOnGpsDataAvailable()));
     connect(m_pGyro, SIGNAL(emitDataAvailable()), this, SLOT(slotOnGyroDataAvailable()));
}

RobotInterface::~RobotInterface()
{

}

bool RobotInterface::connectRobot()
{
    m_pGps->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->gpsPort->text().toInt());
    m_pGyro->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->gyroPort->text().toInt());
    m_pJoystick->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->motorPort->text().toInt());

    return true;
}

void RobotInterface::slotOnGpsDataAvailable()
{
    m_pUi->altitudeResult->setText(QString::number(m_pGps->getAltitude()));
    m_pUi->longitudeResult->setText(QString::number(m_pGps->getLongitude()));
    m_pUi->latitudeResult->setText(QString::number(m_pGps->getLatitude()));
    m_pUi->qualityResult->setText(m_pGps->getQuality());
}

void RobotInterface::slotOnGyroDataAvailable()
{
    m_pUi->gyroXResult->setText(QString::number(m_pGyro->getXGyro()));
    m_pUi->gyroYResult->setText(QString::number(m_pGyro->getYGyro()));
    m_pUi->GyroZResult->setText(QString::number(m_pGyro->getZGyro()));
}

