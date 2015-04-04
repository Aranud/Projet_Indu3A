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
    m_eActionRobot = eActionRobotRigole;
    m_eActionRobotPrecVirage = eActionRobotNone;

    m_iRigoleCount = 0;
    m_iReturnRigol = 0;
    m_iReturnToDo = 0;

    m_iFl = 0;
    m_iFr = 0;
    m_iRl = 0;
    m_iRr = 0;

    m_dIntegral = 0;
    m_dError = 0;

    connect(m_pOdo, SIGNAL(emitDataAvailable()), this, SLOT(onDataFromOdoReady()));
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

    switch(m_eActionRobot)
    {
        case eActionRobotRigole : InterieurRigole(); break;
        case eActionRobotPetitVirageDroite :
        case eActionRobotPetitVirageGauche :
        case eActionRobotGrandVirageDroite :
        case eActionRobotGrandVirageGauche : Virage(); break;

        case eActionRobotRigoleExterieure : ExterieurRigole(); break;
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
    if(/*m_iRr > 17 && m_iFl > 26 && */m_iFr >= 25/* && m_iRl > 27*/)
        return true;
    return false;
}
bool IAMoteur::IsLastHalfTurnRight()
{
    if(/*m_iRr > 15 && m_iFl > 22 &&*/ m_iFr >= 25 /*&& m_iRl > 23*/)
        return true;
    return false;
}

/**
 * @brief IAMoteur::IsHalfTurnLeft
 * @return
 */
bool IAMoteur::IsHalfTurnLeft()
{
    if(/*m_iRr > 26 &&*/ m_iFl >= 25/* && m_iFr > 27 && m_iRl > 19*/)
        return true;
    return false;
}
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

    // Si le point le plus proche est très éloigné
    if(m_structDataIA.iDistanceRef >= m_structDataIA.dLargerRigoleMoyenne)
    {
        ControlMotor(92, 92, false);

        if(m_eActionRobotPrecVirage == eActionRobotNone
        || m_eActionRobotPrecVirage == eActionRobotGrandVirageGauche
        || m_eActionRobotPrecVirage == eActionRobotPetitVirageGauche)
        {
            m_eActionRobot = eActionRobotGrandVirageDroite;
            m_eActionRobotPrecVirage = eActionRobotGrandVirageDroite;
        }
        else if (m_eActionRobotPrecVirage == eActionRobotGrandVirageDroite
              || m_eActionRobotPrecVirage == eActionRobotPetitVirageDroite)
        {
            m_eActionRobot = eActionRobotGrandVirageGauche;
            m_eActionRobotPrecVirage = eActionRobotGrandVirageGauche;
        }

        //qDebug()<<" EMIT ? Returnrigol = "<< m_iReturnRigol<< "\nReturnToDo = "<<m_iReturnToDo ;
        if(m_iReturnRigol >= 2 && m_iReturnToDo <= 0){
            m_eActionRobot = eActionRobotNone;
            ResetOdoValue();
            m_iRigoleCount = 0;
            m_iReturnRigol = 0;
            m_iReturnToDo = 0;
            m_dIntegral = 0;
            m_dError = 0;
            emit emitRigolEnd();
        }

        m_dError = 0;
        m_dIntegral = 0;
        m_eActionRobotPrec = eActionRobotRigole;
        m_eEtatIAMotor = eEtatIAMotorSortie;
        //qDebug() << "Sortie Actif";
    }
    else if(m_structDataIA.iDistanceRef >= CalculLargeurReference() || m_eEtatIAMotor ==  eEtatIAMotorAvant)
    {
            ControlMotor(127, 127, false);
            //qDebug() << "Avant";
    }
    else
    {/*
        bool bInverse = false;
        if(m_eEtatIAMotor == eEtatIAMotorGauche)
            bInverse = true;

        if(m_structDataIA.iDegreeRef < 20)
            ControlMotor(127, 96, bInverse);
        else if(m_structDataIA.iDegreeRef < 45)
            ControlMotor(127, 63, bInverse);
        else if(m_structDataIA.iDegreeRef < 60)
            ControlMotor(127, 32, bInverse);
        else
            ControlMotor(127, 0, bInverse);
*/
        bool bInverse = false;
        m_eEtatIAMotor == eEtatIAMotorGauche ? bInverse = true : bInverse = false;

        PID(bInverse);

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
    bool bInverse = false;

    if( m_structDataIA.iDistanceRef >= (m_structDataIA.dLargerRigoleMoyenne *1.25) )           // Si le point le plus proche est très éloigné
    {
        m_dError = 0;
        m_dIntegral = 0;
        ControlMotor(127, 127, bInverse);
        m_eActionRobot = m_eActionRobotPrecVirage;
        m_eActionRobotPrec = eActionRobotRigoleExterieure;
        m_eEtatIAMotor = eEtatIAMotorSortie;
    }

   /* if(m_structDataIA.iDistanceRef >= CalculLargeurReference() &&
       m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche){
            bInverse = true;
            qDebug()<<"dois tourner a droite";
    }

    else if(m_structDataIA.iDistanceRef < CalculLargeurReference() &&
            m_structDataIA.iDistanceRef == m_structDataIA.iDistanceDroite){
            bInverse = false;
             qDebug()<<"dois tourner a gauche";
    }*/

    if(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche)
        bInverse = false;
    else
        bInverse = true;

    PID(bInverse);

    /*if(m_structDataIA.iDegreeRef < 20)
        ControlMotor(127, 96, bInverse);
    else if(m_structDataIA.iDegreeRef < 45)
        ControlMotor(127, 63, bInverse);
    else if(m_structDataIA.iDegreeRef < 60)
        ControlMotor(127, 32, bInverse);
    else
        ControlMotor(127, 0, bInverse);*/
}

/**************************************************/
/******************** VIRAGE **********************/
/**************************************************/

/**
 * @brief IAMoteur::Virage
 */
void IAMoteur::Virage()
{
    bool bInverse = false;
    int iDistanceSide = m_structDataIA.iDistanceDroite;
    int iDistanceOpposite = m_structDataIA.iDistanceGauche;
    int iDegreeSide = m_structDataIA.iDegreeDroite;
    int iDegreeOpposite = m_structDataIA.iDegreeGauche;

    if(m_eActionRobot == eActionRobotGrandVirageGauche || m_eActionRobot == eActionRobotPetitVirageGauche)
    {
        bInverse = true;
        iDistanceSide = m_structDataIA.iDistanceGauche;
        iDistanceOpposite = m_structDataIA.iDistanceDroite;
        iDegreeSide = m_structDataIA.iDegreeGauche;
        iDegreeOpposite = m_structDataIA.iDegreeDroite;
    }

    if(m_eEtatIAMotor == eEtatIAMotorSortie)
    {
        ControlMotor(127, 127, bInverse);

        if(m_iFl >= 3 && m_iFr >= 3 && iDistanceSide >= m_structDataIA.dLargerRigoleMoyenne / 2
                && iDistanceOpposite >= m_structDataIA.dLargerRigoleMoyenne )
        {
            m_eEtatIAMotor = eEtatIAMotorDebutVirage;
            //qDebug() << "Début virage";
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorSaute)
    {
        ControlMotor(127, 127, bInverse);

        if(m_iFl > 1 && m_iFr > 1 && iDegreeSide <= 30 && iDistanceSide <= m_structDataIA.dLargerRigoleMoyenne)
        {
            m_eEtatIAMotor = eEtatIAMotorFinVirage;
            ResetOdoValue();
            //qDebug() << "Fin virage";
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorArriere)
    {
        ControlMotor(-53, -53, bInverse);

        if(IsBackEnough())
        {
            m_eEtatIAMotor = eEtatIAMotorFinVirage;

            if(m_eActionRobot == eActionRobotGrandVirageGauche)
                m_eActionRobotPrecVirage = eActionRobotPetitVirageGauche;
            else
                m_eActionRobotPrecVirage = eActionRobotPetitVirageDroite;

            ResetOdoValue();
            //qDebug() << "Fin Arriere";
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorDebutVirage)
    {
        ControlMotor(127, 32, bInverse);

        if(IsHalfTurnRight() || IsHalfTurnLeft())
        {
            ResetOdoValue();

            if(iDegreeSide < 30 && iDistanceSide <=  m_structDataIA.dLargerRigoleMoyenne &&
              (m_eActionRobotPrecVirage == eActionRobotPetitVirageDroite ||
              m_eActionRobotPrecVirage == eActionRobotPetitVirageGauche ||
              m_eActionRobotPrec == eActionRobotRigole))
            {
                if(m_eActionRobot == eActionRobotPetitVirageGauche)
                    m_eActionRobotPrecVirage = eActionRobotGrandVirageGauche;
                else if(m_eActionRobot == eActionRobotGrandVirageDroite)
                    m_eActionRobotPrecVirage = eActionRobotGrandVirageDroite;

                m_eEtatIAMotor = eEtatIAMotorSaute;
                m_eActionRobotPrec = eActionRobotNone;
                //qDebug() << "Debut virage";
            }
            else
            {
                m_eEtatIAMotor = eEtatIAMotorArriere;
                //qDebug() << "Debut Arriere";
            }
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorFinVirage)
    {
        ControlMotor(127, 32, bInverse);

        if((IsLastHalfTurnRight() || IsLastHalfTurnLeft()))
        {
            //qDebug() << "Roue Gauche " << m_iFl << " --- Roue Droite " << m_iFr;
            ResetOdoValue();
            m_eEtatIAMotor = eEtatIAMotorNone;

            if(iDistanceOpposite >  m_structDataIA.dLargerRigoleMoyenne && iDegreeOpposite < 30)
            {
                m_eActionRobot = eActionRobotRigoleExterieure;
                //qDebug() << "Fin Virage, Rigole Exterieur";

                if(m_iReturnRigol <=0){
                    m_iReturnToDo = m_iRigoleCount - 1;
                }
                m_iReturnRigol++;
            }
            else
            {
                m_eActionRobot = eActionRobotRigole;
                if(m_iReturnRigol <=0)
                    m_iRigoleCount++;
                else if(m_iReturnRigol >=2)
                    m_iReturnToDo --;
                //qDebug() << "Fin Virage, Rigole Interieur";
            }
        }
    }
}

void IAMoteur::PID(bool bInverse)
{
    double error = ((m_structDataIA.dLargerRigoleMoyenne / 2.0) - m_structDataIA.iDistanceRef);
    double derivative = (error - m_dError) /0.5;
    m_dIntegral += error * 0.5;
    m_dError = error;

    double dCorrection = Kp * error
    + Ki * m_dIntegral
    + Kd * derivative;  

    if(m_eActionRobot == eActionRobotRigoleExterieure){
        if( !bInverse && dCorrection < 0){
            dCorrection = dCorrection*-1;
            bInverse = true;
            //qDebug() <<"ver la droite "<< "Correc : " << dCorrection<<"\n";
        }
        else if( bInverse && dCorrection < 0){
            dCorrection = dCorrection*-1;
            bInverse = false;
            //qDebug() <<"ver la gauche "<< "Correc : " << dCorrection<<"\n";
        }
    }
    else
        dCorrection > 75 ? dCorrection = 75 : 0;

    ControlMotor(127, 127 - dCorrection, bInverse);
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
    if(m_eActionRobot == eActionRobotRigole)
        CalculLargeurRigole();
}

/**
 * @brief IAMoteur::CalculLargeurRigole
 */
void IAMoteur::CalculLargeurRigole()
{
    double dLargeurMesure = (cos(m_structDataIA.iDegreeGauche * PI / 180.0) * m_structDataIA.iDistanceGauche)
                  - (cos((180 - m_structDataIA.iDegreeDroite) * PI / 180.0) * m_structDataIA.iDistanceDroite);

    if(m_structDataIA.lstdLargerRigole.length() < 50)
        m_structDataIA.lstdLargerRigole.append(dLargeurMesure);
    else if(qAbs(m_structDataIA.dLargerRigoleMoyenne - dLargeurMesure) <= 200)  // Si la differences n'est pas supérieur
    {
        double dValueMax = 0, dValueMin = 4000, dValueRef = 0;

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

    if(m_structDataIA.lstdLargerRigole.length() > 0)    // Securite
    {
        foreach(double dValue, m_structDataIA.lstdLargerRigole)
            m_structDataIA.dLargerRigoleMoyenne += dValue;

        m_structDataIA.dLargerRigoleMoyenne /= m_structDataIA.lstdLargerRigole.length();
    }
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
void IAMoteur::onDataFromOdoReady()
{
    if(m_eActionRobot == eActionRobotGrandVirageDroite || m_eActionRobot == eActionRobotGrandVirageGauche
    || m_eActionRobot == eActionRobotPetitVirageDroite || m_eActionRobot == eActionRobotPetitVirageGauche)
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

