#include "robotinterface.h"

RobotInterface::RobotInterface(Ui::MainWindow* ui)
{
    m_pUi = ui;
    m_pProtocole = new Protocole();
    m_pGps = new GPS(m_pProtocole);

     connect(m_pGps, SIGNAL(emitDataAvailable()), this, SLOT(slotOnGpsDataAvailable()));
}

RobotInterface::~RobotInterface()
{

}

bool RobotInterface::connectRobot()
{
  if(m_pGps->ConnectCaptor(m_pUi->leServerAddress->text(),m_pUi->gpsPort->text().toInt()))
    return true;
  else
      return false;
}

void RobotInterface::slotOnGpsDataAvailable()
{
    m_pUi->altitudeResult->setText(QString::number(m_pGps->getAltitude()));
    m_pUi->longitudeResult->setText(QString::number(m_pGps->getLongitude()));
    m_pUi->latitudeResult->setText(QString::number(m_pGps->getLatitude()));
}

