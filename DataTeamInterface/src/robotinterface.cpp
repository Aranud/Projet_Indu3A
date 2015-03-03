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
    m_pMagneto = new Magneto(m_pProtocole);
    m_pOdo = new Odo(m_pProtocole);
    m_pMotor = new Motor(m_pProtocole);
    //m_pRemote = new Remote(m_pProtocole);
    m_pMagneto = new Magneto(m_pProtocole);

    m_pTimer = new QTimer();
    m_pTimer->setInterval(500);

    m_pGraphScene = new QGraphicsScene();
    m_pGraphScene->setSceneRect(0,0,790,490);
    m_pPoint = new QPoint(790/2,465);
    m_pGraphicView = new QGraphicsView;
    m_pGraphicView->setFixedSize(800, 500);
    m_pGraphicView->setScene(m_pGraphScene);
    m_pGraphScene->addRect(0+m_pPoint->rx()-15,0+m_pPoint->ry(),30,50);
    m_pGraphicView->show();

    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));

    connect(m_pGps, SIGNAL(emitDataAvailable()), this, SLOT(slotOnGpsDataAvailable()));
    connect(m_pGyro, SIGNAL(emitDataAvailable()), this, SLOT(slotOnGyroDataAvailable()));
    connect(m_pActuator, SIGNAL(emitDataAvailable()), this, SLOT(slotOnActuatorDataAvailable()));
    connect(m_pAccelero, SIGNAL(emitDataAvailable()), this, SLOT(slotOnAcceleroDataAvailable()));
    connect(m_pLidar, SIGNAL(emitDataAvailable()), this, SLOT(slotOnLidarDataAvailable()));
    connect(m_pMagneto, SIGNAL(emitDataAvailable()), this, SLOT(slotOnMagnetoDataAvailable()));
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
    m_pMagneto->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->magnetoPort->text().toInt());
    m_pMotor->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->motorPort->text().toInt());
    m_pOdo->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->odoPort->text().toInt());
//    m_pRemote->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->remotePort->text().toInt());
    m_pAccelero->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->acceleroPort->text().toInt());
    m_pMagneto->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->magnetoPort->text().toInt());

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

void RobotInterface::FrontMove()
{
//    QList<qint16> lstiPoids;
//    QList<qint16> lstiDistance;
//    QList<qint16> PxD;

//    QByteArray baValue;
//    int etatcourant;

//    double MotorLeft = 0;
//    double MotorRight = 0;
//    double Difference;


//    lstiDistance = m_pLidar->getDistanceList();
//    lstiPoids = m_pLidar->getPoidsList();

//    //PxD = lstiDistance * lstiPoids;

//    for(int i = 0 ; i < lstiPoids.length(); i++)
//    {
//        /*if((lstiDistance.at(i) * lstiPoids.at(i)) < -500)
//            PxD.append(reference);
//        else*/
//            PxD.append(lstiDistance.at(i) * lstiPoids.at(i));
//    }


//    qDebug() << "Lidar Liste PxD : " << PxD;
//    qDebug() << "_____________________________________________________________";
//    qDebug() << "Lidar Liste Poids : " << lstiPoids;
//    qDebug() << "_____________________________________________________________";
//    qDebug() << "Lidar Liste Distance : " << lstiDistance;
//    qDebug() << "_____________________________________________________________";

//    for(int iteML=0; iteML < 136 ; iteML++)
//       MotorLeft += PxD.at(iteML);

//    qDebug() << "__________________________******______________________________";

//    for(int iteMR=136; iteMR < 271 ; iteMR++)
//       MotorRight += PxD.at(iteMR);


//    Difference = MotorLeft - MotorRight;
//    //qDebug() << " Difference = " << Difference;

//    /*******************************************/
//    /***     INITIALISATION MACH A ETAT     ****/
//    /*******************************************/

//    //Etats de départ
//    if(  Difference < 200
//      && Difference > -220
//      && MotorLeft < 10150
//      && MotorLeft > 10130
//      && MotorRight < 9970
//      && MotorRight > 9950)
//    {
//        etatcourant = 0; // Sans obstacles
//    }
//    else
//    if(  Difference > 200
//      && MotorLeft < 10130
//      && MotorRight < 9970
//      && MotorRight > 9950)
//    {
//        etatcourant = 9999;
//    }
//    else
//    if(  Difference < -220
//      && MotorLeft < 10130
//      && MotorRight < 9970
//      && MotorRight > 9950)
//    {
//        etatcourant = 1; // Obstacle uniquement à gauche
//    }
//    else
//    if(  Difference > 200
//      && MotorRight < 9950
//      && MotorLeft < 10150
//      && MotorLeft > 10130)
//    {
//        etatcourant = 2; // Obstacle uniquement à droite
//    }
//    else
//    if(  Difference < -220
//      && MotorRight < 9950
//      && MotorLeft < 10150
//      && MotorLeft > 10130)
//    {
//        etatcourant = 9999; //Etat Erreur
//    }
//    else
//    if(  Difference > 200
//      && MotorRight < 9950
//      && MotorLeft < 10130)
//    {
//        etatcourant = 2; //Double Obstacles plus concentré sur la droite
//    }
//    else
//    if(  Difference < -220
//      && MotorRight < 9950
//      && MotorLeft < 10130)
//    {
//        etatcourant = 1; //Double Obstacles plus concentré sur la gauche
//    }



//    switch( etatcourant )
//    {
//    case(0):
//            baValue[0] = 127;
//            baValue[1] = 127;
//        break;
//    case(1):
//        if(MotorRight < 9950 && MotorLeft < 10130)
//        {
//            baValue[0] = 127;
//            baValue[1] = 20;
//        }else
//        {
//            baValue[0] = 127;
//            baValue[1] = 90;
//        }
//        break;
//    case(2):
//        if(MotorRight < 9950 && MotorLeft < 10130)
//        {
//            baValue[0] = 20;
//            baValue[1] = 127;
//        }else
//        {
//            baValue[0] = 90;
//            baValue[1] = 127;
//        }
//        break;
//    case(9999):
//        qDebug() << "Etat Erreur";
//        break;
//    }
//    m_pMotor->SendData(baValue);

//    //qDebug() << "_____________________________________________________________";
//    //qDebug() << " Motor Left = " << MotorLeft;
//    //qDebug() << " Motor Right = " << MotorRight;
//    //qDebug() << " Difference = " << Difference;

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
    //QList<qint16> lstDistance = m_pLidar->getDistanceList();

    //for( int i=0; i<270;i++)
            //m_pGraphScene->addEllipse(cos(lstDistance.at(i)-135)*100 + m_pPoint->rx(), sin(lstDistance.at(i)-135)*100 + m_pPoint->ry(),1,1);
}

/**
 * @brief RobotInterface::slotOnOdoDataAvailable
 */
void RobotInterface::slotOnOdoDataAvailable()
{
    m_pUi->fl->setText(QString::number(m_pOdo->getFrontLeft()));
    m_pUi->fr->setText(QString::number(m_pOdo->getFrontRight()));
    m_pUi->rl->setText(QString::number(m_pOdo->getRearLeft()));
    m_pUi->rr->setText(QString::number(m_pOdo->getRearRight()));
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
         FrontMove();
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
