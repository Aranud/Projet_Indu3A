#include "robotinterface.h"
#define PI 3.14159265

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
  //  m_pJoystick = new Joystick(m_pProtocole);
    m_pActuator = new Actuator(m_pProtocole);
    m_pAccelero = new Accelero(m_pProtocole);
    m_pLidar = new Lidar(m_pProtocole);
    m_pMagneto = new Magneto(m_pProtocole);
    m_pOdo = new Odo(m_pProtocole);
    m_pMotor = new Motor(m_pProtocole);
    //m_pRemote = new Remote(m_pProtocole);
    m_pRr = m_pRl = m_pFr = m_pFl = false;


    m_pIAMoteur = new IAMoteur(m_pLidar,m_pMotor);

    m_pTimer = new QTimer();
    m_pTimer->setInterval(500);

    draw = true;
    m_pGraphScene = new QGraphicsScene();
    m_pGraphScene->setSceneRect(0,0,690,190);
    m_pPoint = new QPoint(690/2, 180);
    m_pUi->graphicsView->setScene(m_pGraphScene);
    m_pGraphScene->addRect(0+m_pPoint->rx()-14,0+m_pPoint->ry(),28,40);
    //m_pUi->graphicsView->show();

    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));

    connect(m_pGps, SIGNAL(emitDataAvailable()), this, SLOT(slotOnGpsDataAvailable()));
    connect(m_pGyro, SIGNAL(emitDataAvailable()), this, SLOT(slotOnGyroDataAvailable()));
    connect(m_pActuator, SIGNAL(emitDataAvailable()), this, SLOT(slotOnActuatorDataAvailable()));
    connect(m_pAccelero, SIGNAL(emitDataAvailable()), this, SLOT(slotOnAcceleroDataAvailable()));
    connect(m_pLidar, SIGNAL(emitDataAvailable()), this, SLOT(slotOnLidarDataAvailable()));
    connect(m_pMagneto, SIGNAL(emitDataAvailable()), this, SLOT(slotOnMagnetoDataAvailable()));
    connect(m_pOdo, SIGNAL(emitDataAvailable()), this, SLOT(slotOnOdoDataAvailable()));
    //connect(m_pRemote, SIGNAL(emitDataAvailable()), this, SLOT(slotOnRemoteDataAvailable()));
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
 //   m_pJoystick->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->motorPort->text().toInt());
    m_pActuator->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->actuatorPort->text().toInt());
    m_pLidar->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->lidarPort->text().toInt());
    m_pMagneto->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->magnetoPort->text().toInt());
    m_pMotor->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->motorPort->text().toInt());
    m_pOdo->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->odoPort->text().toInt());
    //m_pRemote->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->remotePort->text().toInt());
    m_pAccelero->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->acceleroPort->text().toInt());

    return true;
}

/**
 * @brief RobotInterface::PushButonRight
 */
void RobotInterface::PushButonRight()
{
    m_eDirection = eDirectionRight;

    if(m_pTimer->isActive())
        m_pTimer->stop();
    else
        m_pTimer->start();
}

/**
 * @brief RobotInterface::PushButonLeft
 */
void RobotInterface::PushButonLeft()
{
    m_eDirection = eDirectionLeft;

    if(m_pTimer->isActive())
        m_pTimer->stop();
    else
        m_pTimer->start();
}

/**
 * @brief RobotInterface::PushButonFront
 */
void RobotInterface::PushButonFront()
{
    m_eDirection = eDirectionFront;

    if(m_pTimer->isActive())
        m_pTimer->stop();
    else
        m_pTimer->start();
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
    m_pUi->timeResult->setText(QString::number(m_pGps->getTime()));
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
    m_pUi->acceleroXResult->setText(QString::number(m_pAccelero->getXAccelero()));
    m_pUi->acceleroYResult->setText(QString::number(m_pAccelero->getYAccelero()));
    m_pUi->acceleroZResult->setText(QString::number(m_pAccelero->getZAccelero()));
}

/**
 * @brief RobotInterface::slotOnLidarDataAvailable
 */
void RobotInterface::slotOnLidarDataAvailable()
{
    QList<qint16> lstDistance = m_pLidar->getDistanceList();

    if(draw)
    {
         draw =false;
        QTime time;
        time.start();
        m_pGraphScene->clear();
        m_pGraphScene->addRect(0+m_pPoint->rx()-14,0+m_pPoint->ry(),28,40);
        for(int i=0; i< 270;i++){
             m_pGraphScene->addEllipse(m_pPoint->rx() + cos((i+135) * PI/180 ) * (lstDistance.at(i)/5) , m_pPoint->ry() + sin((i+135) * PI/180) *(lstDistance.at(i)/5), 2, 2);
            //qDebug() << "DISTANCE( " << i <<" ) = " << lstDistance.at(i);
        }
        draw = true;
    }

}

/**
 * @brief RobotInterface::slotOnOdoDataAvailable
 */
void RobotInterface::slotOnOdoDataAvailable()
{
    if(m_pOdo->getFrontLeft() && !m_pFl)
    {
        m_pUi->fl_2->setText(QString::number(m_pUi->fl_2->text().toInt() +1));
        m_pUi->fl->setText(QString::number(m_pOdo->getFrontLeft()));
        m_pFl = !m_pFl;
    }

    if(m_pOdo->getFrontRight() && !m_pFr)
    {
        m_pUi->fr_2->setText( QString::number(m_pUi->fr_2->text().toInt()+1));
        m_pUi->fl->setText(QString::number(m_pOdo->getFrontRight()));
         m_pFr = !m_pFr;
    }

    if(m_pOdo->getRearLeft() && !m_pRl)
    {
        m_pUi->rl_2->setText(QString::number( m_pUi->rl_2->text().toInt()+1));
        m_pUi->fl->setText(QString::number(m_pOdo->getRearLeft()));
        m_pRl = !m_pRl;
    }

    if(m_pOdo->getRearRight() && !m_pRr)
    {
        m_pUi->rr_2->setText(QString::number( m_pUi->rr_2->text().toInt()+1));
        m_pUi->fl->setText(QString::number(m_pOdo->getRearRight()));
        m_pRr = !m_pRr;
    }
}

/**
 * @brief RobotInterface::slotOnRemoteDataAvailable
 */
void RobotInterface::slotOnRemoteDataAvailable()
{
}

/**
 * @brief RobotInterface::slotOnMagnetoDataAvailable
 */
void RobotInterface::slotOnMagnetoDataAvailable()
{
}

void RobotInterface::slotTimeOut()
{
     QByteArray baValue;

     if(m_eDirection == eDirectionLeft)
     {
         baValue[0] = 0;
         baValue[1] = 127;
     }
     else if(m_eDirection == eDirectionRight)
     {
         baValue[0] = 127;
         baValue[1] = 0;
     }
     else if(m_eDirection == eDirectionFront)
     {
         m_pIAMoteur->EtatParcelle();
         return;
     }
     else
         return;
/*
     if(m_iCompteur >= 13)
     {
        m_iCompteur = 0;
        m_pTimer->stop();
        return;
     }

     m_pMotor->SendData(baValue);

     m_iCompteur++;
*/
}
