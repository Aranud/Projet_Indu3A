#include "iamoteur.h"

/**
 * @brief IAMoteur::IAMoteur
 * @param parent
 */
IAMoteur::IAMoteur(Lidar *p_pLidar, Motor *p_pMotor, Odo *p_pOdo, QObject *parent) :
    QObject(parent)
{
    m_pMotor = p_pMotor;
    m_pLidar = p_pLidar;
    m_pOdo = p_pOdo;

    m_eEtatIAMotor = eEtatIAMotorNone;
    m_ePositionRobot = ePositionRobotRigole;
    m_ePositionRobotPrecVirage = ePositionRobotNone;

    m_iRigoleCount = 0;
    m_iReturnRigol = 0;
    m_iReturnToDo = 0;

    m_iFl = 0;
    m_iFr = 0;
    m_iRl = 0;
    m_iRr = 0;

    m_dIntegral = 0;
    m_dError = 0;

    connect(m_pOdo, SIGNAL(emitDataAvailable()), this, SLOT(slotOnDataReadyFromOdo()));
}

/**
 * @brief IAMoteur::~IAMoteur
 */
IAMoteur::~IAMoteur()
{

}

/*******************************************************************************/
/**************************** ACCESSOR - MODIFICATOR ***************************/
/*******************************************************************************/

/**
 * @brief IAMoteur::getEtatIAMotor
 * @return
 */
eEtatIAMotor IAMoteur::getEtatIAMotor() const
{
    return m_eEtatIAMotor;
}

/**
 * @brief IAMoteur::setEtatIAMotor
 * @param p_eEtatIAMotor
 */
void IAMoteur::setEtatIAMotor(const eEtatIAMotor &p_eEtatIAMotor)
{
    m_eEtatIAMotor = p_eEtatIAMotor;
}

/**
 * @brief IAMoteur::getPositionRobot
 * @return
 */
ePositionRobot IAMoteur::getPositionRobot() const
{
    return m_ePositionRobot;
}

/**
 * @brief IAMoteur::setPositionRobot
 * @param value
 */
void IAMoteur::setPositionRobot(const ePositionRobot &p_ePositionRobot)
{
    m_ePositionRobot = p_ePositionRobot;
}

/*******************************************************************************/
/*********************************** METHOD ************************************/
/*******************************************************************************/

/**************************************************/
/*************** MACHINE ETAT *********************/
/**************************************************/
/**
 * @brief IAMoteur::MachineAEtat
 */
void IAMoteur::MachineAEtat()
{
    DataResult();

    switch(m_ePositionRobot)
    {
        case ePositionRobotRigole : InterieurRigole(); break;
        case ePositionRobotRigoleExterieure : ExterieurRigole(); break;
        case ePositionRobotPetitVirageDroite :
        case ePositionRobotPetitVirageGauche :
        case ePositionRobotGrandVirageDroite :
        case ePositionRobotGrandVirageGauche : MachineEtatVirage(); break;
        default :  break;
    }
}

/**************************************************/
/**************** TEST BOOLEAN ********************/
/**************************************************/

/**
 * @brief IAMoteur::IsHalfTurnRight
 * @return
 */

double IAMoteur::getKp()
{
    return Kp;
}

void IAMoteur::setKp(double value)
{
    Kp = value;
}

double IAMoteur::getKi()
{
    return Ki;
}

void IAMoteur::setKi(double value)
{
    Ki = value;
}

double IAMoteur::getKd()
{
    return Kd;
}

void IAMoteur::setKd(double value)
{
    Kd = value;
}
bool IAMoteur::IsHalfTurnRight()
{
    if(((m_iFl * 64.65) + (m_iFr * 64.65)) / 2 > CalculDistanceArcVirage())
    //if(m_iFr * 64.65 > CalculDistanceArcVirage())
    //if(/*m_iRr > 17 && m_iFl > 26 && */m_iFr >= 25/* && m_iRl > 27*/)
        return true;
    return false;
}

/**
 * @brief IAMoteur::IsHalfTurnLeft
 * @return
 */
bool IAMoteur::IsHalfTurnLeft()
{
    //if(m_iFl * 64.65 > CalculDistanceArcVirage())
    //if(/*m_iRr > 26 &&*/ m_iFl >= 25/* && m_iFr > 27 && m_iRl > 19*/)
        return true;
    //return false;
}

/**
 * @brief IAMoteur::IsLastHalfTurnRight
 * @return
 */
bool IAMoteur::IsLastHalfTurnRight()
{
    if(/*m_iRr > 15 && m_iFl > 22 &&*/ m_iFr >= 25 /*&& m_iRl > 23*/)
        return true;
    return false;
}

/**
 * @brief IAMoteur::IsLastHalfTurnLeft
 * @return
 */
bool IAMoteur::IsLastHalfTurnLeft()
{
    if(/*m_iRr > 22 && */m_iFl >= 14/* && m_iFr > 21 && m_iRl > 14*/)
        return true;
    return false;
}

/**
 * @brief IAMoteur::IsBackEnough
 * @return
 */
bool IAMoteur::IsBackEnough()
{
    if(/*m_iRr >= 10 &&*/ m_iFl >= 9 && m_iFr >= 10 /*&& m_iRl >= 9*/)
        return true;
    return false;
}

/**
 * @brief IAMoteur::ResetOdoValue
 */
void IAMoteur::ResetOdoValue()
{
    m_iRr = 0;
    m_iFl = 0;
    m_iFr = 0;
    m_iRl = 0;
}

/**
 * @brief IAMoteur::InversePositionVirage
 */
void IAMoteur::InversePositionVirage()
{
    // Si le robot avait precedement effectuer un virage a gauche le suivant sera a droite
    if(m_ePositionRobotPrecVirage == ePositionRobotNone
    || m_ePositionRobotPrecVirage == ePositionRobotGrandVirageGauche
    || m_ePositionRobotPrecVirage == ePositionRobotPetitVirageGauche)
    {
        m_ePositionRobot = ePositionRobotGrandVirageDroite;
        m_ePositionRobotPrecVirage = ePositionRobotGrandVirageDroite;
    }
    // Si le robot avait precedement effectuer un virage a droite le suivant sera a gauche
    else if (m_ePositionRobotPrecVirage == ePositionRobotGrandVirageDroite
          || m_ePositionRobotPrecVirage == ePositionRobotPetitVirageDroite)
    {
        m_ePositionRobot = ePositionRobotGrandVirageGauche;
        m_ePositionRobotPrecVirage = ePositionRobotGrandVirageGauche;
    }
}

/*************************************************************/
/******************** RIGOLE INTERIEUR ***********************/
/*************************************************************/

/**
 * @brief IAMoteur::InterieurRigole
 */
void IAMoteur::InterieurRigole()
{
    // Si distance ref = gauche --> Oz derive a droite (vis-versa)
    m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche ?
        m_eEtatIAMotor = eEtatIAMotorDroite : m_eEtatIAMotor = eEtatIAMotorGauche;

    // Si le point le plus proche est éloigné de la longueur moyenne de la rigole
    if(m_structDataIA.iDistanceRef >= m_structDataIA.dLargerRigoleMoyenne * 1.25)
    {
        ControlMotor(92, 92, false);    // Avance
        qDebug() << "Fin Rigole interieur ";

        InversePositionVirage();        // Demande le virage oppose au precedent
        //qDebug()<<" EMIT ? Returnrigol = "<< m_iReturnRigol<< "\nReturnToDo = "<<m_iReturnToDo ;
        if(m_iReturnRigol >= 2 && m_iReturnToDo <= 0){
            m_ePositionRobot = ePositionRobotNone;
            ResetOdoValue();
            m_iRigoleCount = 0;
            m_iReturnRigol = 0;
            m_iReturnToDo = 0;
            m_dIntegral = 0;
            m_dError = 0;
            emit signalRigolEnd();
        }

        m_dError = 0;
        m_dIntegral = 0;
        m_ePositionRobotPrec = ePositionRobotRigole;
        m_eEtatIAMotor = eEtatIAMotorSortieRigole;
    }
    // Si les obstacles a gauche et droite sont eloigne a la largeur de ref. Oz fonce droit
    else if(m_structDataIA.iDistanceRef >= CalculLargeurReference() || m_eEtatIAMotor ==  eEtatIAMotorAvant)
    {
            ControlMotor(127, 127, false);
    }
    else    // Sinon les obstacles sont proches, un PID est applique
    {
        PID(m_eEtatIAMotor == eEtatIAMotorGauche ? true : false);
    }
}

/*************************************************************/
/******************** RIGOLE EXTERIEUR ***********************/
/*************************************************************/

/**
 * @brief IAMoteur::ExterieurRigole
 */
void IAMoteur::ExterieurRigole()
{
    // Si le point le plus proche est éloigné de la longueur moyenne de la rigole
    if(m_structDataIA.iDistanceRef >= (m_structDataIA.dLargerRigoleMoyenne * 1.25))
    {
        ControlMotor(127, 127, false);

        m_dError = 0;
        m_dIntegral = 0;
        m_ePositionRobot = m_ePositionRobotPrecVirage;          // Effectue le meme virage que precedement
        m_ePositionRobotPrec = ePositionRobotRigoleExterieure;
        m_eEtatIAMotor = eEtatIAMotorSortieRigole;          // Oz est en etat de sortie
    }
    PID(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche ? false : true);
}

/**************************************************/
/******************** VIRAGE **********************/
/**************************************************/

/**
 * @brief IAMoteur::Virage
 */
void IAMoteur::MachineEtatVirage()
{
    DataResultVirage();

    switch(m_eEtatIAMotor)
    {
        case eEtatIAMotorSortieRigole : SortieRigole(); break;
        case eEtatIAMotorSaute : SauteRigole(); break;
        case eEtatIAMotorReculeVirage : ReculeVirage(); break;
        case eEtatIAMotorDebutVirage : DebutVirage(); break;
        case eEtatIAMotorFinVirage : FinVirage(); break;
        default : break; // Ne doit pas se produire
    }
}

/**
 * @brief IAMoteur::SortieRigole
 */
void IAMoteur::SortieRigole()
{
    ControlMotor(127, 127, m_structVirageIA.bInverse);

    if(m_iFl >= 3 && m_iFr >= 3 && m_structVirageIA.iDistanceSide >= m_structDataIA.dLargerRigoleMoyenne / 2
            && m_structVirageIA.iDistanceOpposite >= m_structDataIA.dLargerRigoleMoyenne)
    {
        qDebug() << " Arc Distance : " << CalculDistanceArcVirage();
        qDebug() << " Moyenne largeur rigole : " << m_structDataIA.dLargerRigoleMoyenne;

        m_eEtatIAMotor = eEtatIAMotorDebutVirage;
        qDebug() << "Début virage";
    }
}

/**
 * @brief IAMoteur::ReculeVirage
 */
void IAMoteur::ReculeVirage()
{
    ControlMotor(-53, -53, m_structVirageIA.bInverse);

    if(IsBackEnough())
    {
        m_eEtatIAMotor = eEtatIAMotorFinVirage;

        if(m_ePositionRobot == ePositionRobotGrandVirageGauche)
            m_ePositionRobotPrecVirage = ePositionRobotPetitVirageGauche;
        else
            m_ePositionRobotPrecVirage = ePositionRobotPetitVirageDroite;

        ResetOdoValue();
    }
}

/**
 * @brief IAMoteur::SauteRigole
 */
void IAMoteur::SauteRigole()
{
    ControlMotor(127, 127, m_structVirageIA.bInverse);

    if(m_iFl > 1 && m_iFr > 1 && m_structVirageIA.iDegreeSide <= 30 && m_structVirageIA.iDistanceSide <= m_structDataIA.dLargerRigoleMoyenne)
    {
        m_eEtatIAMotor = eEtatIAMotorFinVirage;
        ResetOdoValue();
    }
}

/**
 * @brief IAMoteur::DebutVirage
 */
void IAMoteur::DebutVirage()
{
    ControlMotor(127, 32, m_structVirageIA.bInverse);

    if(IsHalfTurnRight() && IsHalfTurnLeft())
    {
        qDebug() << " Arc Distance : " << CalculDistanceArcVirage();
        qDebug() << " Value FL : " << m_iFl << " Value FR " << m_iFr;
        qDebug() << " FL mm : " << m_iFl * 64.65 << " FR mm : " << m_iFr * 64.65;

        qDebug() << " DegreeSide : " << m_structVirageIA.iDegreeSide;
        qDebug() << " DistanceSide : " << m_structVirageIA.iDistanceSide;
        qDebug() << " Robot Pos Prec : " << m_ePositionRobotPrec;

        ResetOdoValue();

        //  Si le point le plus proche ce trouve a moins de 30° et a une distance d'une rigole
        // Et que le la position precedent du robot soit une rigole interieur ou un petit virage
        if(m_structVirageIA.iDegreeSide < 30 && m_structVirageIA.iDistanceSide <= m_structDataIA.dLargerRigoleMoyenne &&
          (m_ePositionRobotPrecVirage == ePositionRobotPetitVirageDroite ||
          m_ePositionRobotPrecVirage == ePositionRobotPetitVirageGauche ||
          m_ePositionRobotPrec == ePositionRobotRigole))
        {
            if(m_ePositionRobot == ePositionRobotPetitVirageGauche)
                m_ePositionRobotPrecVirage = ePositionRobotGrandVirageGauche;
            else if(m_ePositionRobot == ePositionRobotGrandVirageDroite)
                m_ePositionRobotPrecVirage = ePositionRobotGrandVirageDroite;

            m_eEtatIAMotor = eEtatIAMotorSaute;
            m_ePositionRobotPrec = ePositionRobotNone;
        }
        else
        {
            m_eEtatIAMotor = eEtatIAMotorReculeVirage;
        }
    }
}

/**
 * @brief IAMoteur::FinVirage
 */
void IAMoteur::FinVirage()
{
    ControlMotor(127, 32, m_structVirageIA.bInverse);

    if((IsLastHalfTurnRight() || IsLastHalfTurnLeft()))
    {
        ResetOdoValue();
        m_eEtatIAMotor = eEtatIAMotorNone;

        // Si aucun obstacle n'est detecter sur le cote oppose, il s'agit d'une rigole exterieure
        if(m_structVirageIA.iDistanceOpposite > m_structDataIA.dLargerRigoleMoyenne && m_structVirageIA.iDegreeOpposite < 30)
        {
            //qDebug() << "Roue Gauche " << m_iFl << " --- Roue Droite " << m_iFr;
            ResetOdoValue();
            m_eEtatIAMotor = eEtatIAMotorNone;

            if(m_structVirageIA.iDistanceOpposite >  m_structDataIA.dLargerRigoleMoyenne && m_structVirageIA.iDegreeOpposite < 30)
            {
                m_ePositionRobot = ePositionRobotRigoleExterieure;
                //qDebug() << "Fin Virage, Rigole Exterieur";

                if(m_iReturnRigol <=0){
                    m_iReturnToDo = m_iRigoleCount - 1;
                }
                m_iReturnRigol++;
            }
            else
            {
                m_ePositionRobot = ePositionRobotRigole;
                if(m_iReturnRigol <=0)
                    m_iRigoleCount++;
                else if(m_iReturnRigol >=2)
                    m_iReturnToDo --;
                //qDebug() << "Fin Virage, Rigole Interieur";
            }
        }
    }
}

/*************************************************************/
/*********************** PID / MOTOR CMD *********************/
/*************************************************************/

/**
 * @brief IAMoteur::PID
 * @param bInverse
 */
void IAMoteur::PID(bool bInverse)
{
    double Kp = 0.6, Ki = 0.2, Kd = 0.3;
    double error = ((m_structDataIA.dLargerRigoleMoyenne / 2.0) - m_structDataIA.iDistanceRef);
    double derivative = (error - m_dError) / 0.5;
    m_dIntegral += error * 0.5;
    m_dError = error;

    double dCorrection = Kp * error
    + Ki * m_dIntegral
    + Kd * derivative;  

    if(m_ePositionRobot == ePositionRobotRigoleExterieure){
        if( !bInverse && dCorrection < 0){
            dCorrection = dCorrection * -1;
            bInverse = true;
            //qDebug() <<"ver la droite "<< "Correc : " << dCorrection<<"\n";
        }
        else if( bInverse && dCorrection < 0){
            dCorrection = dCorrection * -1;
            bInverse = false;
            //qDebug() <<"ver la gauche "<< "Correc : " << dCorrection<<"\n";
        }
    }
    else
        dCorrection > 75 ? dCorrection = 75 : 0;

    ControlMotor(127, 127 - dCorrection, bInverse);
}

/**
 * @brief IAMoteur::ControlMotor
 * @param p_iMotorLeft
 * @param p_iMotorRight
 * @param p_bInverse
 */
void IAMoteur::ControlMotor(int p_iMotorLeft, int p_iMotorRight, bool p_bInverse)
{
    QByteArray baDataToSend;

    if(p_bInverse)
    {
        baDataToSend[0] = p_iMotorRight;
        baDataToSend[1] = p_iMotorLeft;
    }
    else
    {
        baDataToSend[0] = p_iMotorLeft;
        baDataToSend[1] = p_iMotorRight;
    }
    m_pMotor->SendData(baDataToSend);
}

/**************************************************/
/***************** DATA TREATEMENT ****************/
/**************************************************/

/**
 * @brief IAMoteur::DataResult
 */
void IAMoteur::DataResult()
{
    QList<qint16> lstiDistance = m_pLidar->getDistanceList();

    m_structDataIA.iDistanceDroite = DEFAULT_DISTANCE_VALUE;
    m_structDataIA.iDistanceGauche = DEFAULT_DISTANCE_VALUE;
    m_structDataIA.iDistanceRef = DEFAULT_DISTANCE_VALUE;
    m_structDataIA.iDegreeFront = DEFAULT_DISTANCE_VALUE;

    m_structDataIA.iDegreeDroite = DEFAULT_DEGREE_VALUE;
    m_structDataIA.iDegreeGauche = DEFAULT_DEGREE_VALUE;
    m_structDataIA.iDegreeRef = DEFAULT_DEGREE_VALUE;
    m_structDataIA.iDegreeFront = DEFAULT_DEGREE_VALUE;

    for(int iIncrement = 0; iIncrement < 90; iIncrement++)
    {
        //Point le plus proche a gauche
        if(lstiDistance.at(START_LIDAR_VISIBILITY_RANGE + iIncrement) != 0 && lstiDistance.at(START_LIDAR_VISIBILITY_RANGE + iIncrement) < m_structDataIA.iDistanceGauche)
        {
            m_structDataIA.iDistanceGauche = lstiDistance.at(START_LIDAR_VISIBILITY_RANGE + iIncrement);
            m_structDataIA.iDegreeGauche = iIncrement;
        }

        //Point le plus proche a droite
        if(lstiDistance.at(END_LIDAR_VISIBILITY_RANGE - iIncrement) != 0 && lstiDistance.at(END_LIDAR_VISIBILITY_RANGE - iIncrement) < m_structDataIA.iDistanceDroite)
        {
            m_structDataIA.iDistanceDroite = lstiDistance.at(END_LIDAR_VISIBILITY_RANGE - iIncrement);
            m_structDataIA.iDegreeDroite = iIncrement;
        }
    }

    // Distance de reference entre la gauche et la droite
    m_structDataIA.iDistanceRef = qMin(m_structDataIA.iDistanceDroite, m_structDataIA.iDistanceGauche);

    // Degree de Reference entre la gauche et la droite
    m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche ?
        m_structDataIA.iDegreeRef = m_structDataIA.iDegreeGauche :
        m_structDataIA.iDegreeRef = m_structDataIA.iDegreeDroite;

    // Si dans une rigole alors calcul largeur de la rigole
    if(m_ePositionRobot == ePositionRobotRigole)
        CalculLargeurRigole();
}

void IAMoteur::DataResultVirage()
{
    if(m_ePositionRobot == ePositionRobotGrandVirageGauche || m_ePositionRobot == ePositionRobotPetitVirageGauche)
    {
        m_structVirageIA.bInverse = true;
        m_structVirageIA.iDistanceSide = m_structDataIA.iDistanceGauche;
        m_structVirageIA.iDistanceOpposite = m_structDataIA.iDistanceDroite;
        m_structVirageIA.iDegreeSide = m_structDataIA.iDegreeGauche;
        m_structVirageIA.iDegreeOpposite = m_structDataIA.iDegreeDroite;
    }
    else
    {
        m_structVirageIA.bInverse = false;
        m_structVirageIA.iDistanceSide = m_structDataIA.iDistanceDroite;
        m_structVirageIA.iDistanceOpposite = m_structDataIA.iDistanceGauche;
        m_structVirageIA.iDegreeSide = m_structDataIA.iDegreeDroite;
        m_structVirageIA.iDegreeOpposite = m_structDataIA.iDegreeGauche;
    }
}

/**
 * @brief IAMoteur::CalculLargeurRigole
 */
void IAMoteur::CalculLargeurRigole()
{
    double dLargeurMesure = (cos(m_structDataIA.iDegreeGauche * PI_180) * m_structDataIA.iDistanceGauche)
                  - (cos((180 - m_structDataIA.iDegreeDroite) * PI_180) * m_structDataIA.iDistanceDroite);

    if(m_structDataIA.lstdLargerRigole.length() < AVERAGE_DISTANCE_SAMPLE_MAX)
        m_structDataIA.lstdLargerRigole.append(dLargeurMesure);
    else if(qAbs(m_structDataIA.dLargerRigoleMoyenne - dLargeurMesure) <= LIMIT_RANGE)  // Si la differences n'est pas supérieur
    {
        double dValueMax = 0, dValueMin = DEFAULT_DISTANCE_VALUE, dValueRef = 0;

        foreach(double dValue, m_structDataIA.lstdLargerRigole)
        {
            qMin(dValue, dValueMin) == dValue ? dValueMin = dValue : 0;
            qMax(dValue, dValueMax) == dValue ? dValueMax = dValue : 0;
        }

        dValueRef = qBound(dValueMin, m_structDataIA.dLargerRigoleMoyenne, dValueMax);
        dValueRef == dValueMin ? dValueRef = dValueMax : dValueRef = dValueMin;

        if(qBound(dValueRef, m_structDataIA.dLargerRigoleMoyenne, dLargeurMesure) == dLargeurMesure)
            m_structDataIA.lstdLargerRigole.replace(m_structDataIA.lstdLargerRigole.indexOf(dValueRef), dLargeurMesure);
    }

    if(m_structDataIA.lstdLargerRigole.isEmpty() == false)    // Securite
    {
        foreach(double dValue, m_structDataIA.lstdLargerRigole)
            m_structDataIA.dLargerRigoleMoyenne += dValue;

        m_structDataIA.dLargerRigoleMoyenne /= m_structDataIA.lstdLargerRigole.length();
    }
}

/**
 * @brief IAMoteur::CalculDistanceArcVirage
 * @return
 */
double IAMoteur::CalculDistanceArcVirage()
{
    return ((90.0 * PI * m_structDataIA.dLargerRigoleMoyenne * 1.25) / 180.0);
}

/**
 * @brief IAMoteur::CalculLargeurReference
 * @return
 */
int IAMoteur::CalculLargeurReference()
{
    return (m_structDataIA.dLargerRigoleMoyenne / 2.0) - (m_structDataIA.dLargerRigoleMoyenne / 16.0);
}

/*******************************************************************************/
/*********************************** SLOT **************************************/
/*******************************************************************************/

/**
 * @brief IAMoteur::onDataFromOdoReady
 */
void IAMoteur::slotOnDataReadyFromOdo()
{
    if(m_ePositionRobot == ePositionRobotGrandVirageDroite || m_ePositionRobot == ePositionRobotGrandVirageGauche
    || m_ePositionRobot == ePositionRobotPetitVirageDroite || m_ePositionRobot == ePositionRobotPetitVirageGauche)
    {
        if(m_pOdo->getFrontLeft() != m_bFl)
        {
            m_bFl ? m_bFl = false : m_bFl = true;
            m_iFl++;
        }

        if(m_pOdo->getFrontRight() != m_bFr)
        {
            m_bFr ? m_bFr = false : m_bFr = true;
            m_iFr++;
        }

        if(m_pOdo->getRearLeft() != m_bRl)
        {
            m_bRl? m_bRl = false : m_bRl = true;
            m_iRl++;
        }

        if(m_pOdo->getRearRight() != m_bRr)
        {
            m_bRr ? m_bRr = false : m_bRr = true;
            m_iRr++;
        }
    }
}

