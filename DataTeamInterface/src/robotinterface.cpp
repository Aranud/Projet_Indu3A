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

    m_lstCaptors.clear();

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

    m_lstCaptors.append(m_pMotor);
    m_lstCaptors.append(m_pGps);
    m_lstCaptors.append(m_pGyro);
    //m_lstCaptors.append(m_pJoystick);
    m_lstCaptors.append(m_pActuator);
    m_lstCaptors.append(m_pAccelero);
    m_lstCaptors.append(m_pMagneto);
    m_lstCaptors.append(m_pOdo);
    m_lstCaptors.append(m_pLidar);


    m_bRr = m_bRl = m_bFr = m_bFl = false;

    m_pIAMoteur = new IAMoteur(m_pLidar,m_pMotor);

    m_pTimer = new QTimer();
    m_pTimer->setInterval(500);

    draw = true;
    m_pGraphScene = new QGraphicsScene();
    m_pGraphScene->setSceneRect(0,0,690,190);
    m_pPoint = new QPoint(690/2, 180);
    m_pUi->graphicsView->setScene(m_pGraphScene);

    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));

    m_pSignalConnectionMapper = new QSignalMapper(this);
    m_pSignalCaptorMapper = new QSignalMapper(this);

    foreach (Captor* captor, m_lstCaptors)
    {
        connect(captor, SIGNAL(emitConnected()), m_pSignalConnectionMapper, SLOT(map()));
        m_pSignalConnectionMapper->setMapping(captor, (int)captor->getEIDCommand());

        connect(captor, SIGNAL(emitDataExtractedAvailable(QByteArray)), m_pSignalCaptorMapper, SLOT(map()));
        m_pSignalCaptorMapper->setMapping(captor, (int)captor->getEIDCommand());
    }

    connect(m_pSignalConnectionMapper, SIGNAL(mapped(int)), this, SLOT(slotOnConectedCaptorReady(int)));
    connect(m_pSignalCaptorMapper, SIGNAL(mapped(int)), this, SLOT(slotOnCaptorSignals(int)));

    m_pUi->pbSendData->setEnabled(false);
    m_pUi->pbAvant->setEnabled(false);
    m_pUi->pbArriere->setEnabled(false);
    m_pUi->pbGauche->setEnabled(false);
    m_pUi->pbDroite->setEnabled(false);
    m_pUi->pbDt->setEnabled(false);
    m_pUi->pbBordure->setEnabled(false);
    m_pUi->pbRigole->setEnabled(false);
    m_pUi->pbLevel1->setEnabled(false);
    m_pUi->pbLevel2->setEnabled(false);
    m_pUi->pbLevel3->setEnabled(false);
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
     if(m_pUi->pbConnection->text() == "Connexion")
     {
        m_pGps->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->gpsPort->text().toInt());
        m_pGyro->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->gyroPort->text().toInt());
        // m_pJoystick->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->motorPort->text().toInt());
        m_pActuator->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->actuatorPort->text().toInt());
        m_pLidar->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->lidarPort->text().toInt());
        m_pMagneto->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->magnetoPort->text().toInt());
        m_pMotor->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->motorPort->text().toInt());
        m_pOdo->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->odoPort->text().toInt());
        m_pAccelero->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->acceleroPort->text().toInt());
        //m_pRemote->ConnectCaptor(m_pUi->leServerAddress->text(), m_pUi->remotePort->text().toInt());
     }
     else{
         if(m_pTimer->isActive())
            m_pTimer->stop();

         foreach (Captor* captor, m_lstCaptors)
            captor->DisconnectCaptor();
         m_pUi->pbConnection->setText("Connexion");
         m_pGraphScene->clear();

         m_pUi->pbSendData->setEnabled(false);
         m_pUi->pbAvant->setEnabled(false);
         m_pUi->pbArriere->setEnabled(false);
         m_pUi->pbGauche->setEnabled(false);
         m_pUi->pbDroite->setEnabled(false);
         m_pUi->pbDt->setEnabled(false);
         m_pUi->pbBordure->setEnabled(false);
         m_pUi->pbRigole->setEnabled(false);
         m_pUi->pbLevel1->setEnabled(false);
         m_pUi->pbLevel2->setEnabled(false);
         m_pUi->pbLevel3->setEnabled(false);
     }


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

/**
 * @brief RobotInterface::onGpsDataAvailable
 */
void RobotInterface::onGpsDataAvailable()
{
    m_pUi->altitudeResult->setText(QString::number(m_pGps->getAltitude()));
    m_pUi->longitudeResult->setText(QString::number(m_pGps->getLongitude()));
    m_pUi->latitudeResult->setText(QString::number(m_pGps->getLatitude()));
    m_pUi->qualityResult->setText(m_pGps->getQuality());
    m_pUi->timeResult->setText(QString::number(m_pGps->getTime()));
}

/**
 * @brief RobotInterface::onGyroDataAvailable
 */
void RobotInterface::onGyroDataAvailable()
{
    m_pUi->gyroXResult->setText(QString::number(m_pGyro->getXGyro()));
    m_pUi->gyroYResult->setText(QString::number(m_pGyro->getYGyro()));
    m_pUi->gyroZResult->setText(QString::number(m_pGyro->getZGyro()));
}

/**
 * @brief RobotInterface::onActuatorDataAvailable
 */
void RobotInterface::onActuatorDataAvailable()
{
    m_pUi->actuatorResult->setText(QString::number(m_pActuator->getActuator()));
}

/**
 * @brief RobotInterface::onAcceleroDataAvailable
 */
void RobotInterface::onAcceleroDataAvailable()
{
    m_pUi->acceleroXResult->setText(QString::number(m_pAccelero->getXAccelero()));
    m_pUi->acceleroYResult->setText(QString::number(m_pAccelero->getYAccelero()));
    m_pUi->acceleroZResult->setText(QString::number(m_pAccelero->getZAccelero()));
}

/**
 * @brief RobotInterface::onLidarDataAvailable
 */
void RobotInterface::onLidarDataAvailable()
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
 * @brief RobotInterface::onOdoDataAvailable
 */
void RobotInterface::onOdoDataAvailable()
{
    bool bFl,bFr,bRl,bRr;
    m_pUi->fl->setText(QString::number(bFl = m_pOdo->getFrontLeft()));
    m_pUi->fr->setText(QString::number(bFr =m_pOdo->getFrontRight()));
    m_pUi->rl->setText(QString::number(bRl =m_pOdo->getRearLeft()));
    m_pUi->rr->setText(QString::number(bRr =m_pOdo->getRearRight()));

    if(bFl != m_bFl)
    {
        m_pUi->fl_2->setText(QString::number(m_pUi->fl_2->text().toInt() +1));
        m_bFl = bFl;
    }

    if(bFr != m_bFr)
    {
        m_pUi->fr_2->setText( QString::number(m_pUi->fr_2->text().toInt()+1));
        m_bFr = bFr;
    }

    if(bRl != m_bRl)
    {
        m_pUi->rl_2->setText(QString::number( m_pUi->rl_2->text().toInt()+1));
        m_bRl = bRl;
    }

    if(bRr != m_bRr)
    {
        m_pUi->rr_2->setText(QString::number( m_pUi->rr_2->text().toInt()+1));
        m_bRr = bRr;
    }
}

/**
 * @brief RobotInterface::onRemoteDataAvailable
 */
void RobotInterface::onRemoteDataAvailable()
{
}

/**
 * @brief RobotInterface::onMotorDataAvailable
 */
void RobotInterface::onMotorDataAvailable()
{

}

/**
 * @brief RobotInterface::onMagnetoDataAvailable
 */
void RobotInterface::onMagnetoDataAvailable()
{

    m_pUi->magnetoXResult->setText(QString::number(m_pMagneto->getXMagneto()) );
    m_pUi->magnetoYResult->setText(QString::number(m_pMagneto->getYMagneto()) );
    m_pUi->magnetoZResult->setText(QString::number(m_pMagneto->getZMagneto()) );

}


/*******************************************************************************/
/********************************** SLOT ***************************************/
/*******************************************************************************/
/**
 * @brief RobotInterface::slotTimeOut
 */
void RobotInterface::slotTimeOut()
{
     QByteArray baValue;

     if(m_eDirection == eDirectionLeft)
     {
         baValue[0] = 32;
         baValue[1] = 127;
         m_iCompteur++;
     }
     else if(m_eDirection == eDirectionRight)
     {
         baValue[0] = 127;
         baValue[1] = 32;
         m_iCompteur++;
     }
     else if(m_eDirection == eDirectionFront)
     {
         m_pIAMoteur->MachineAEtat();
         return;
     }
     else
         return;

     if(m_iCompteur >= 11)
     {
        m_iCompteur = 0;
        m_pTimer->stop();
        return;
     }

     m_pMotor->SendData(baValue);

}

/**
 * @brief RobotInterface::slotOnCaptorSignals
 */
void RobotInterface::slotOnCaptorSignals(int p_iValue)
{
    switch(p_iValue){
    case eIDCommandGyro:
        onGyroDataAvailable();
        break;
    case eIDCommmandAccelero:
        onAcceleroDataAvailable();
        break;
    case eIDCommmandActuator:
        onActuatorDataAvailable();
        break;
    case eIDCommmandGPS:
        onGpsDataAvailable();
        break;
    case eIDCommmandLidar:
        onLidarDataAvailable();
        break;
    case eIDCommmandMagneto:
        onMagnetoDataAvailable();
        break;
    case eIDCommmandMotors:
        onMotorDataAvailable();
        break;
    case eIDCommmandOdo:
        onOdoDataAvailable();
        break;
    case eIDCommmandRemote:
        onRemoteDataAvailable();
        break;
    default:
        break;
    }
}

/**
 * @brief RobotInterface::slotOnConectedCaptorReady
 */
void RobotInterface::slotOnConectedCaptorReady(int p_iValue)
{

    switch(p_iValue){
    case eIDCommmandMotors:
        m_pUi->pbSendData->setEnabled(true);
        m_pUi->pbAvant->setEnabled(true);
        m_pUi->pbArriere->setEnabled(true);
        m_pUi->pbGauche->setEnabled(true);
        m_pUi->pbDroite->setEnabled(true);
        m_pUi->pbDt->setEnabled(true);
        break;

    case eIDCommmandLidar:
        m_pUi->pbRigole->setEnabled(true);
        m_pUi->pbBordure->setEnabled(true);

        if(m_pMotor->getIsConnected()){
            m_pUi->pbLevel1->setEnabled(true);
            m_pUi->pbLevel2->setEnabled(true);
            m_pUi->pbLevel3->setEnabled(true);
        }
        break;
    default:
        if(m_pUi->pbConnection->text() == "Connexion")
            m_pUi->pbConnection->setText("Deconnexion");
        break;
    }


}
