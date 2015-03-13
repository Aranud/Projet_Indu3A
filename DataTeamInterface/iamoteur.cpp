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

    m_iViragePartCount = 0;
    m_iDataSendCount = 0;
    m_iRigoleCount = 0;

    m_bIsRillExit = false;
    m_bSauteRigoleFini = false;
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

/**
 * @brief IAMoteur::MachineAEtat
 */
void IAMoteur::MachineAEtat()
{
    DataResult();

    switch(m_eActionRobot)
    {
        case eActionRobotRigole : InterieurRigole(); break;
        case eActionRobotGrandVirageDroite :
        case eActionRobotGrandVirageGauche : Virage(); break;

        case eActionRobotRigoleExterieure : ExterieurRigole(); break;
        case eActionRobotPetitVirageDroite : break;
        case eActionRobotPetitVirageGauche : break;
        default :  break;
    }
}

/**
 * @brief IAMoteur::InterieurRigole
 */
void IAMoteur::InterieurRigole()
{

    m_iRigoleCount++;
    if(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche)
        m_eEtatIAMotor = eEtatIAMotorDroite;
    else
        m_eEtatIAMotor = eEtatIAMotorGauche;

    if(m_structDataIA.iDistanceRef >= 500)      // Si le point le plus proche est très éloigné
    {
        ControlMotor(127, 127, false);

        if(m_eActionRobotPrecVirage == eActionRobotNone || m_eActionRobotPrecVirage == eActionRobotGrandVirageGauche)
        {
            m_eActionRobot = eActionRobotGrandVirageDroite;
            m_eActionRobotPrecVirage = eActionRobotGrandVirageDroite;
        }
        else if (m_eActionRobotPrecVirage == eActionRobotGrandVirageDroite)
        {
            m_eActionRobot = eActionRobotGrandVirageGauche;
            m_eActionRobotPrecVirage = eActionRobotGrandVirageGauche;
        }

        m_eEtatIAMotor = eEtatIAMotorSortie;
        m_iRigoleCount++;
        qDebug() << "Sortie Actif";
    }
    else if(m_structDataIA.iDistanceRef > 200)
    {
        if(m_structDataIA.iDegreeRef > 70 && m_structDataIA.iDegreeRef == m_structDataIA.iDegreeGauche)
            ControlMotor(127, 96, false);
        else if (m_structDataIA.iDegreeRef > 70 && m_structDataIA.iDegreeRef == m_structDataIA.iDegreeDroite)
            ControlMotor(96, 127, false);
        else
            ControlMotor(127, 127, false);

        qDebug() << "Avant";
    }
    else if(m_eEtatIAMotor == eEtatIAMotorDroite)
    {
        if(m_structDataIA.iDegreeRef < 20)
            ControlMotor(127, 96, false);
        else if(m_structDataIA.iDegreeRef < 45)
            ControlMotor(127, 63, false);
        else if(m_structDataIA.iDegreeRef < 60)
            ControlMotor(127, 32, false);

        qDebug() << "Correction Droite";
    }
    else if(m_eEtatIAMotor == eEtatIAMotorGauche)
    {
        if(m_structDataIA.iDegreeRef < 20)
            ControlMotor(96, 127, false);
        else if(m_structDataIA.iDegreeRef < 45)
            ControlMotor(63, 127, false);
        else if(m_structDataIA.iDegreeRef < 60)
            ControlMotor(32, 127, false);

        qDebug() << "Correction Gauche";
    }
    else
        ControlMotor(127, 127, false);
}

/**
 * @brief IAMoteur::ExterieurRigole
 */
void IAMoteur::ExterieurRigole()
{

    m_iRigoleCount++;
    if(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche)
        m_eEtatIAMotor = eEtatIAMotorDroite;
    else
        m_eEtatIAMotor = eEtatIAMotorGauche;

    if(m_structDataIA.iDistanceRef >= 600)            // Si le point le plus proche est très éloigné
    {
        ControlMotor(127, 127, false);
        m_eActionRobot = m_eActionRobotPrecVirage;
        m_eEtatIAMotor = eEtatIAMotorVirage;
        m_bIsRillExit = true;
        qDebug() << "Sortie Actif";

    }

    if(m_structDataIA.iDistanceRef > 200)
    {
        if(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche)
            ControlMotor(96, 127, false);
        else
            ControlMotor(127, 96, false);

    }
    else if(m_structDataIA.iDistanceRef < 200)
    {
        if(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche)
            ControlMotor(127, 96, false);
        else
            ControlMotor(96, 127, false);
    }
    else if(m_structDataIA.iDistanceRef == 200)
        ControlMotor(127, 127, false);
}

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

    if(m_eActionRobot == eActionRobotGrandVirageGauche)
    {
        bInverse = true;
        iDistanceSide = m_structDataIA.iDistanceGauche;
        iDistanceOpposite = m_structDataIA.iDistanceDroite;
        iDegreeSide = m_structDataIA.iDegreeGauche;
        iDegreeOpposite = m_structDataIA.iDegreeDroite;
    }

    if(m_eEtatIAMotor == eEtatIAMotorSauteRigole)
    {
        if(m_iDataSendCount >= (4 * m_iRigoleCount) && m_bSauteRigoleFini == false) // Angle de 90 ° effectué
        {
            m_bSauteRigoleFini = true;
            m_iDataSendCount = 0;
        }
        else if(m_bSauteRigoleFini == true)
        {
//            ControlMotor(127, 32, bInverse);
//            m_iDataSendCount++;
//            if(m_iDataSendCount > 8)
//            {
//                m_eEtatIAMotor = eEtatIAMotorVirage;
//                m_iDataSendCount = 0;
//            }

            m_eEtatIAMotor = eEtatIAMotorVirage;
            m_iDataSendCount = 0;
            m_bIsRillExit = false;
        }
        else
        {
                ControlMotor(127, 127, bInverse);
                m_iDataSendCount++;
        }
    }
//    else if(m_eEtatIAMotor == eEtatIAMotorSortieExterieur)
//    {
//        if(iDistanceSide < 250)
//        {
//            ControlMotor(127, 127, bInverse);
//            m_iDataSendCount = 0;
//        }
//        else
//             ControlMotor(127, 32, bInverse);

//        m_iDataSendCount++;

//        if(m_iDataSendCount > 9) // Angle de 90 ° effectué
//        {
//            m_iDataSendCount = 0;
//            m_eEtatIAMotor = eEtatIAMotorSauteRigole;
//        }
//    }
    if(m_eEtatIAMotor == eEtatIAMotorSortie)
    {
        ControlMotor(127, 127, bInverse);

        if(iDistanceSide > 200)
        {
            m_eEtatIAMotor = eEtatIAMotorVirage;
            m_iDataSendCount = 0;
            qDebug() << "Sortie en cours";
        }
    }

    else if(m_eEtatIAMotor == eEtatIAMotorArriere)
    {
        ControlMotor(-53, -53, bInverse);

        m_iDataSendCount++;

        if((iDistanceSide < 500 && m_iDataSendCount > 7) || (iDistanceSide > 500 && m_iDataSendCount > 10))
        {
            m_eEtatIAMotor = eEtatIAMotorVirage;
            m_iDataSendCount = 0;
            m_iViragePartCount = 2;
        }
        if(m_iViragePartCount == 3 && m_iDataSendCount > 7)
        {
            m_eEtatIAMotor = eEtatIAMotorVirage;
            m_iDataSendCount = 0;
            m_iViragePartCount = 2;
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorVirage)
    {
        ControlMotor(127, 32, bInverse);

        m_iDataSendCount++;
        if(m_iDataSendCount >= 4 && iDegreeSide <= 30 && iDistanceSide <= 350 && m_iViragePartCount == 0 && !m_bIsRillExit)
        {
            if(m_bIsRillExit)
                m_eEtatIAMotor = eEtatIAMotorSauteRigole;
            else
                m_eEtatIAMotor = eEtatIAMotorArriere;

            m_iDataSendCount = 0;
            m_iViragePartCount = 1;
        }
        else if(m_iDataSendCount >= 10 && m_iViragePartCount == 0)
        {
            if(m_bIsRillExit)
                m_eEtatIAMotor = eEtatIAMotorSauteRigole;
            else
                m_eEtatIAMotor = eEtatIAMotorArriere;

            m_iDataSendCount = 0;
            m_iViragePartCount = 3;

        }
        else if(m_iDataSendCount >= 10 && m_iViragePartCount == 2 && iDistanceOpposite == 1000)
        {
            m_eEtatIAMotor = eEtatIAMotorNone;
            m_eActionRobot = eActionRobotRigoleExterieure;
            m_iDataSendCount = 0;
            m_iViragePartCount = 0;
            qDebug() << "Fin Virage, Rigole Exterieur";
        }
        else if(m_iDataSendCount >= 10 && m_iViragePartCount == 2)
        {
            m_eEtatIAMotor = eEtatIAMotorNone;
            m_eActionRobot = eActionRobotRigole;
            m_iDataSendCount = 0;
            m_iViragePartCount = 0;
            qDebug() << "Fin Virage, Rigole Interieur";
        }
    }
}

/**
 * @brief IAMoteur::DataResult
 */
void IAMoteur::DataResult()
{
    QList<qint16> lstiDistance = m_pLidar->getDistanceList();

    m_structDataIA.iDistanceDroite = DEFAULT_DISTANCE_VALUE;
    m_structDataIA.iDistanceGauche = DEFAULT_DISTANCE_VALUE;
    m_structDataIA.iDistanceRef = DEFAULT_DISTANCE_VALUE;

    m_structDataIA.iDegreeDroite = DEFAULT_DEGREE_VALUE;
    m_structDataIA.iDegreeGauche = DEFAULT_DEGREE_VALUE;
    m_structDataIA.iDegreeRef = DEFAULT_DEGREE_VALUE;

    for(int iIncrement = 0; iIncrement < 90; iIncrement++)
    {
        if(lstiDistance.at(START_LIDAR_VISIBILITY_RANGE + iIncrement) != 0 && lstiDistance.at(START_LIDAR_VISIBILITY_RANGE + iIncrement) < m_structDataIA.iDistanceGauche)
        {
            m_structDataIA.iDistanceGauche = lstiDistance.at(START_LIDAR_VISIBILITY_RANGE + iIncrement);
            m_structDataIA.iDegreeGauche = iIncrement;
        }

        if(lstiDistance.at(END_LIDAR_VISIBILITY_RANGE - iIncrement) != 0 && lstiDistance.at(END_LIDAR_VISIBILITY_RANGE - iIncrement) < m_structDataIA.iDistanceDroite)
        {
            m_structDataIA.iDistanceDroite = lstiDistance.at(END_LIDAR_VISIBILITY_RANGE - iIncrement);
            m_structDataIA.iDegreeDroite = iIncrement;
        }
    }

    m_structDataIA.iDistanceRef = qMin(m_structDataIA.iDistanceDroite, m_structDataIA.iDistanceGauche);

    if(m_eActionRobot == eActionRobotRigole)
    {
        if(m_structDataIA.lstdLargerRigole.length() < 50)
            m_structDataIA.lstdLargerRigole.append(m_structDataIA.iDistanceDroite + m_structDataIA.iDistanceGauche);
        else
        {
            double dValueMax = 0, dValueMin = 1000, dValueRef = 0;

            foreach(double dValue, m_structDataIA.lstdLargerRigole)
            {
                if(qMin(dValue, dValueMax) == dValue)
                {
                    dValueMin = dValue;
                }
                if(qMax(dValue, dValueMax) == dValue)
                {
                    dValueMax = dValue;
                }
            }

            dValueRef = qBound(dValueMin, m_structDataIA.dLargerRigoleMoyenne, dValueMax);
            double dNewValue = m_structDataIA.iDistanceDroite + m_structDataIA.iDistanceGauche;

            if(qBound(dValueRef, m_structDataIA.dLargerRigoleMoyenne, dNewValue) == dNewValue)
                m_structDataIA.lstdLargerRigole.replace(m_structDataIA.lstdLargerRigole.indexOf(dValueRef), dNewValue);
        }

        foreach(double dValue, m_structDataIA.lstdLargerRigole)
            m_structDataIA.dLargerRigoleMoyenne += dValue;

        m_structDataIA.dLargerRigoleMoyenne /= m_structDataIA.lstdLargerRigole.length();

        qDebug() << "Largeur Rigole " << m_structDataIA.dLargerRigoleMoyenne;
    }

    if(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche)
        m_structDataIA.iDegreeRef = m_structDataIA.iDegreeGauche;
    else
        m_structDataIA.iDegreeRef = m_structDataIA.iDegreeDroite;
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
