#include "robotinterface.h"

/**
 * @brief RobotInterface::RobotInterface
 * @param ui
 */
RobotInterface::RobotInterface(Ui::MainWindow* ui)
{
	//ui interface 
    m_pUi = ui;
    //Instance protocol class for define how the software communicate with NAIO
	m_pProtocole = new Protocole();
	
	//Open the socket for communication 
    m_pTCPSocketServer = new TCPSocketServer();

	//Connect the event data received from socket to robotinterface
    connect(m_pTCPSocketServer, SIGNAL(emitDataReceived(QString)), this, SLOT(slotOnReceivedFromIPAD(QString)));

	//set list of captor
    m_lstCaptors.clear();
	
	//set all captor
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
	
	//boolean wheel
    m_bRr = m_bRl = m_bFr = m_bFl = false;
	
	//Iamotor : the main algorithme
    m_pIAMoteur = new IAMoteur(m_pLidar, m_pMotor, m_pOdo);
	
	//kp ki kd => PID
     m_pIAMoteur->setKp(m_pUi->P->value());
     m_pIAMoteur->setKi(m_pUi->I->value());
     m_pIAMoteur->setKd(m_pUi->D->value());

	 //timer for algorithme
    m_pTimer = new QTimer();
    m_pTimer->setInterval(50);
	
	//draw a graphic scene for see the point catch by the lidar
    m_bDraw = true;
    m_pGraphScene = new QGraphicsScene();
    m_pGraphScene->setSceneRect(0,0,690,190);
    m_pPoint = new QPoint(690/2, 180);
    m_pUi->graphicsView->setScene(m_pGraphScene);

    connect(m_pTimer, SIGNAL(timeout()), this, SLOT(slotTimeOut()));
	
	//mapping of all conection event signal from captor
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
    connect(m_pIAMoteur,SIGNAL(signalRigolEnd()),this,SLOT(slotOnRigolEnd()));

    m_pUi->pbSendData->setEnabled(false);

    m_pUi->pbAvant->setEnabled(false);
    m_pUi->pbArriere->setEnabled(false);
    m_pUi->pbAvantGauche->setEnabled(false);
    m_pUi->pbArriereGauche->setEnabled(false);
    m_pUi->pbAvantDroit->setEnabled(false);
    m_pUi->pbArierreDroit->setEnabled(false);
    m_pUi->pbGauche->setEnabled(false);
    m_pUi->pbDroite->setEnabled(false);
    m_pUi->pbDt->setEnabled(false);
    m_pUi->pbLevel1->setEnabled(false);
    m_pUi->pbLevel2->setEnabled(false);
    m_pUi->pbLevel3->setEnabled(false);

}

/**
 * @brief RobotInterface::~RobotInterface
 */
RobotInterface::~RobotInterface()
{
	//destrcuteur
    foreach (Captor* captor, m_lstCaptors)
       captor->DisconnectCaptor();

    if(m_pTCPSocketServer)
        delete(m_pTCPSocketServer);
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
		 //on se connecte 
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
		 //sinon on se deconnecte
         if(m_pTimer->isActive())
            m_pTimer->stop();

         foreach (Captor* captor, m_lstCaptors)
            captor->DisconnectCaptor();
         m_pUi->pbConnection->setText("Connexion");
         m_pGraphScene->clear();

         m_pUi->pbSendData->setEnabled(false);
         m_pUi->pbAvant->setEnabled(false);
         m_pUi->pbArriere->setEnabled(false);
         m_pUi->pbAvantGauche->setEnabled(false);
         m_pUi->pbArriereGauche->setEnabled(false);
         m_pUi->pbAvantDroit->setEnabled(false);
         m_pUi->pbArierreDroit->setEnabled(false);
         m_pUi->pbGauche->setEnabled(false);
         m_pUi->pbDroite->setEnabled(false);
         m_pUi->pbDt->setEnabled(false);
         m_pUi->pbLevel1->setEnabled(false);
         m_pUi->pbLevel2->setEnabled(false);
         m_pUi->pbLevel3->setEnabled(false);

		//changer l'image de connection
         m_pUi->img->setPixmap(QPixmap(":icons/ICON_OZ_DISABLE").scaled(m_pUi->img->width(),m_pUi->img->height(),Qt::KeepAspectRatio));
     }


    return true;
}

/**
 * @brief RobotInterface::pushLevel1
 */
void RobotInterface::pushLevel1()
{
	//lancement du 1er algorithme
    qDebug() << "Direction1 :: "<<m_eDirection;

    if(m_eDirection != eIAMotorLevel1)
        m_eDirection = eIAMotorLevel1;
    else
        m_eDirection = eDirectionNone;

     qDebug()<<"Direction2 :: "<<m_eDirection;

    if(m_pTimer->isActive())
        m_pTimer->stop();
    else
        m_pTimer->start();
}

/**
 * @brief RobotInterface::pusButton
 */
void RobotInterface::pushButton(int button)
{
	//Si un bouton est appuyé, choix :
//    if(m_eDirection != eIAMotorLevel1)
//    {
        m_pTimer->start();
        switch(button){
            case 1:
                m_eDirection = eDirectionFront;
                break;
            case 2:
                m_eDirection = eDirectionLeft;
                break;
            case 3:
                m_eDirection = eDirectionBack;
                break;
            case 4:
                m_eDirection = eDirectionRight;
                break;
            case 5:
                m_eDirection = eDirectionFrontLeft;
                break;
            case 6:
                m_eDirection = eDirectionBackRight  ;
                break;
            case 7:
                m_eDirection = eDirectionBackLeft ;
                break;
            case 8:
                m_eDirection = eDirectionFrontRight;
                break;
            case 9:
                m_eDirection = eDirectionTest;
                break;
            default:
                m_eDirection = eDirectionNone;
                break;
//        }
    }
}

/*****************************************************************************/
/********************************** SLOT *************************************/
/*****************************************************************************/

/**
 * @brief RobotInterface::onGpsDataAvailable
 */
void RobotInterface::slotOnGpsDataAvailable()
{
    //reception data gps
    m_pUi->altitudeResult->setText(QString::number(m_pGps->getAltitude()));
    m_pUi->longitudeResult->setText(QString::number(m_pGps->getLongitude()));
    m_pUi->latitudeResult->setText(QString::number(m_pGps->getLatitude()));
    m_pUi->qualityResult->setText(m_pGps->getQuality());
    QDateTime date = QDateTime::fromMSecsSinceEpoch(m_pGps->getTime());
    m_pUi->timeResult->setText(date.toString());
    m_pUi->speedResult->setText(QString::number(m_pGps->getGroundSpeed()));
    m_pUi->numberSatResult->setText(QString::number(m_pGps->getSateliteNumber()));
}

/**
 * @brief RobotInterface::onGyroDataAvailable
 */
void RobotInterface::slotOnGyroDataAvailable()
{	
	//reception data gyro
    m_pUi->gyroXResult->setText(QString::number(m_pGyro->getXGyro()));
    m_pUi->gyroYResult->setText(QString::number(m_pGyro->getYGyro()));
    m_pUi->gyroZResult->setText(QString::number(m_pGyro->getZGyro()));
}

/**
 * @brief RobotInterface::onActuatorDataAvailable
 */
void RobotInterface::slotOnActuatorDataAvailable()
{
    m_pUi->actuatorResult->setText(QString::number(m_pActuator->getActuator()));
}

/**
 * @brief RobotInterface::onAcceleroDataAvailable
 */
void RobotInterface::slotOnAcceleroDataAvailable()
{	
	//reception data accelero
    m_pUi->acceleroXResult->setText(QString::number(m_pAccelero->getXAccelero()));
    m_pUi->acceleroYResult->setText(QString::number(m_pAccelero->getYAccelero()));
    m_pUi->acceleroZResult->setText(QString::number(m_pAccelero->getZAccelero()));
}

/**
 * @brief RobotInterface::onLidarDataAvailable
 */
void RobotInterface::slotOnLidarDataAvailable()
{
	//reception data Lidar
    QList<qint16> lstDistance = m_pLidar->getDistanceList();

        m_pGraphScene->clear();
        m_pGraphScene->addRect(0+m_pPoint->rx()-21,0+m_pPoint->ry(),42,50);
        for(int iIncrement = 45; iIncrement < 226; iIncrement++)
        {
             m_pGraphScene->addEllipse(m_pPoint->rx() + cos((iIncrement+135) * PI/180 ) * (lstDistance.at(iIncrement)/10) , m_pPoint->ry() + sin((iIncrement+135) * PI/180) *(lstDistance.at(iIncrement)/10), 2, 2);
        }
}

/**
 * @brief RobotInterface::onOdoDataAvailable
 */
void RobotInterface::slotOnOdoDataAvailable()
{
	//reception data odo
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
void RobotInterface::slotOnRemoteDataAvailable()
{
}

/**
 * @brief RobotInterface::onMotorDataAvailable
 */
void RobotInterface::slotOnMotorDataAvailable()
{

}

/**
 * @brief RobotInterface::onMagnetoDataAvailable
 */
void RobotInterface::slotOnMagnetoDataAvailable()
{
	//reception data magneto
    m_pUi->magnetoXResult->setText(QString::number(m_pMagneto->getXMagneto()) );
    m_pUi->magnetoYResult->setText(QString::number(m_pMagneto->getYMagneto()) );
    m_pUi->magnetoZResult->setText(QString::number(m_pMagneto->getZMagneto()) );

}

void RobotInterface::P_valueChanged(double dKp)
{
	//changement de la valeur P du PID
  m_pIAMoteur->setKp(dKp);
}

void RobotInterface::I_valueChanged(double dKi)
{
	//changement de la valeur I du PID
   m_pIAMoteur->setKi(dKi);
}

void RobotInterface::D_valueChanged(double dKd)
{
	//changement de la valeur D du PID
   m_pIAMoteur->setKd(dKd);
}



/*******************************************************************************/
/********************************** SLOT ***************************************/
/*******************************************************************************/
/**
 * @brief RobotInterface::slotTimeOut
 */
void RobotInterface::slotTimeOut()
{
	
	//choix de direction apres timeoutr
     QByteArray baValue;

    if( (m_iCompteur =  m_pUi->fl_2->text().toInt()  - m_iCompteur) <= 0 )
        m_iCompteur = m_pUi->fl_2->text().toInt();


     if(m_eDirection == eDirectionLeft)
     {
         baValue[0] = -1*m_pUi->maxWheel->value();
         baValue[1] =    m_pUi->maxWheel->value();
     }
     else if(m_eDirection == eDirectionRight)
     {
         baValue[0] =    m_pUi->maxWheel->value();//g
         baValue[1] = -1*m_pUi->maxWheel->value();//d
     }
     else if(m_eDirection == eDirectionFront)
     {
         baValue[0] = m_pUi->maxWheel->value();
         baValue[1] = m_pUi->maxWheel->value();
     }
     else if(m_eDirection == eDirectionBack)
     {
         baValue[0] = -1*m_pUi->maxWheel->value();//g
         baValue[1] = -1*m_pUi->maxWheel->value();//d
     }
     else if(m_eDirection == eDirectionFrontLeft)
     {
         baValue[0] = m_pUi->maxWheel->value()/m_pUi->ratio->value();
         baValue[1] = m_pUi->maxWheel->value();
     }
     else if(m_eDirection == eDirectionFrontRight)
     {
         baValue[0] = m_pUi->maxWheel->value();//g
         baValue[1] = m_pUi->maxWheel->value()/m_pUi->ratio->value();//d
     }
     else if(m_eDirection == eDirectionBackLeft)
     {
         baValue[0] = -1* (m_pUi->maxWheel->value()/m_pUi->ratio->value());
         baValue[1] = -1*  m_pUi->maxWheel->value();
     }
     else if(m_eDirection == eDirectionBackRight)
     {
         baValue[0] = -1*  m_pUi->maxWheel->value();
         baValue[1] = -1* (m_pUi->maxWheel->value()/m_pUi->ratio->value());
     }
     else if(m_eDirection == eDirectionTest)
     {
         baValue[0] = m_pUi->maxWheel->value()/m_pUi->ratio->value();
         baValue[1] = 127;
     }
     else if(m_eDirection == eIAMotorLevel1)
     {
         m_pIAMoteur->MachineAEtat();
         return;
     }
     else if(m_eDirection == eDirectionNone)
     {
         m_pTimer->stop();
     }

    if(m_eDirection != eIAMotorLevel1)
        m_pMotor->SendData(baValue);
}

/**
 * @brief RobotInterface::slotOnCaptorSignals
 */
void RobotInterface::slotOnCaptorSignals(int p_iValue)
{
	//reception Signal
    switch(p_iValue){
    case eIDCommandGyro:
        slotOnGyroDataAvailable();
        break;
    case eIDCommmandAccelero:
        slotOnAcceleroDataAvailable();
        break;
    case eIDCommmandActuator:
        slotOnActuatorDataAvailable();
        break;
    case eIDCommmandGPS:
        slotOnGpsDataAvailable();
        break;
    case eIDCommmandLidar:
        slotOnLidarDataAvailable();
        break;
    case eIDCommmandMagneto:
        slotOnMagnetoDataAvailable();
        break;
    case eIDCommmandMotors:
        slotOnMotorDataAvailable();
        break;
    case eIDCommmandOdo:
        slotOnOdoDataAvailable();
        break;
    case eIDCommmandRemote:
        slotOnRemoteDataAvailable();
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
	//connexion vérifié
    switch(p_iValue){
    case eIDCommmandMotors:
        m_pUi->pbSendData->setEnabled(true);
        m_pUi->pbAvant->setEnabled(true);
        m_pUi->pbArriere->setEnabled(true);
        m_pUi->pbAvantGauche->setEnabled(true);
        m_pUi->pbArriereGauche->setEnabled(true);
        m_pUi->pbAvantDroit->setEnabled(true);
        m_pUi->pbArierreDroit->setEnabled(true);
        m_pUi->pbGauche->setEnabled(true);
        m_pUi->pbDroite->setEnabled(true);
        m_pUi->pbDt->setEnabled(true);
        break;

    case eIDCommmandLidar:
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

    foreach (Captor* captor, m_lstCaptors) {

        if(captor->getIsConnected())
            m_pUi->img->setPixmap(QPixmap(":icons/ICON_OZ_ENABLE").scaled(m_pUi->img->width(),m_pUi->img->height(),Qt::KeepAspectRatio));
        else
            m_pUi->img->setPixmap(QPixmap(":icons/ICON_OZ_DISABLE").scaled(m_pUi->img->width(),m_pUi->img->height(),Qt::KeepAspectRatio));
    }
}

void RobotInterface::slotOnRigolEnd()
{
	//fin d'algorithme
    m_pTimer->stop();
    m_eDirection = eDirectionNone;
}
/**
 * @brief RobotInterface::slotOnIPADSendSomething
 */
void RobotInterface::slotOnReceivedFromIPAD(QString p_sData)
{
    if(p_sData == "epreuve1")
    {
        pushLevel1();
    }
    else if(p_sData == "epreuve2")
    {
        //PushButonLeft();
    }   
}

/**
 * @brief RobotInterface::on_P_valueChanged
 */
void RobotInterface::on_P_valueChanged(double P)
{
    m_pIAMoteur->setKp(P);
}
/**
 * @brief RobotInterface::on_I_valueChanged
 */
void RobotInterface::on_I_valueChanged(double I)
{
     m_pIAMoteur->setKi(I);
}

/**
 * @brief RobotInterface::on_D_valueChanged
 */
void RobotInterface::on_D_valueChanged(double D)
{
     m_pIAMoteur->setKd(D);
}
