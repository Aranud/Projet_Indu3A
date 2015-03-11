#include "iamoteur.h"

/**
 * @brief IAMoteur::IAMoteur
 * @param parent
 */
IAMoteur::IAMoteur(Lidar *p_pLidar, Motor *p_pMotor, QObject *parent) :
    QObject(parent)
{
    m_pMotor = p_pMotor;
    m_pLidar = p_pLidar;
    m_eEtatIAMotor = eEtatIAMotorNone;
    m_eActionRobot = eActionRobotRigole;
    m_eActionRobotPrecVirage = eActionRobotNone;
    viragePart = 0;
    ite_Datasend = 0;
    NbRigole = 0;
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
        case eActionRobotGrandVirageDroite : VirageDroite(); break;
        case eActionRobotGrandVirageGauche : VirageGauche(); break;
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
    NbRigole++;

    if(m_structDataIA.iDistanceRef >= 600)            // Si le point le plus proche est très éloigné
    {
        ControlMotor(127, 127);

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
        qDebug() << "Sortie Actif";
    }
    else if(m_structDataIA.iDistanceRef > 180)
    {
        if(m_structDataIA.iDegreeRef > 70 && m_structDataIA.iDegreeRef == m_structDataIA.iDegreeGauche)
            ControlMotor(127, 96);
        else if (m_structDataIA.iDegreeRef > 70 && m_structDataIA.iDegreeRef == m_structDataIA.iDegreeDroite)
            ControlMotor(96, 127);
        else
            ControlMotor(127, 127);
    }
    else if(m_eEtatIAMotor == eEtatIAMotorDroite)
    {
        if(m_structDataIA.iDegreeRef < 45)
            ControlMotor(127, 96);
        else if(m_structDataIA.iDegreeRef < 60)
            ControlMotor(127, 63);
        else
            ControlMotor(127, 0);

        qDebug() << "Correction Droite";
    }
    else if(m_eEtatIAMotor == eEtatIAMotorGauche)
    {
        if(m_structDataIA.iDegreeRef < 45)
            ControlMotor(96, 127);
        else if(m_structDataIA.iDegreeRef < 60)
            ControlMotor(63, 127);
        else
            ControlMotor(0, 127);

        qDebug() << "Correction Gauche";
    }
    else
        ControlMotor(127, 127);
}

/**
 * @brief IAMoteur::VirageDroite
 */
void IAMoteur::VirageDroite()
{
    if(m_eEtatIAMotor == eEtatIAMotorArriere)
    {
        ControlMotor(-127, -127);

        ite_Datasend++;

        if(m_structDataIA.iDistanceDroite < 500 && ite_Datasend == 3)
        {
            m_eEtatIAMotor = eEtatIAMotorVirageDroite;
            ite_Datasend = 0;
            viragePart = 2;
        }else
        if(ite_Datasend >= 3 && m_structDataIA.iDistanceDroite > 500)
        {
            ControlMotor(127, 127);
            ite_Datasend = 0;
            viragePart = 2;
            m_eEtatIAMotor = eEtatIAMotorVirageDroite;
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorSortie)
    {
        ControlMotor(127, 127);

        if(m_structDataIA.iDistanceDroite > 200)
        {
            qDebug() << "Sortie en cours";
            m_eEtatIAMotor = eEtatIAMotorVirageDroite;
            ite_Datasend = 0;
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorVirageDroite)
    {
        ControlMotor(127, 32);

        ite_Datasend++;
        if(ite_Datasend >= 10 && viragePart == 0)
        {
            m_eEtatIAMotor = eEtatIAMotorArriere;
            ite_Datasend = 0;
            viragePart = 1;
        }else
        if(ite_Datasend >= 10 && m_structDataIA.iDistanceGauche == 1000 && viragePart == 2)
        {
            m_eEtatIAMotor = eEtatIAMotorNone;
            m_eActionRobot = eActionRobotRigoleExterieure;
            viragePart = 0;
        }else
        if(ite_Datasend >= 10 && viragePart == 2)
        {
            m_eEtatIAMotor = eEtatIAMotorNone;
            m_eActionRobot = eActionRobotRigole;
            viragePart = 0;
            qDebug() << "Fin Virage";
        }
    }
}

/**
 * @brief IAMoteur::VirageGauche
 */
void IAMoteur::VirageGauche()
{
    if(m_eEtatIAMotor == eEtatIAMotorArriere)
    {
        ControlMotor(-127, -127);

        ite_Datasend++;
        if(m_structDataIA.iDistanceGauche < 450 && ite_Datasend >= 3)
        {
            m_eEtatIAMotor = eEtatIAMotorVirageGauche;
            ite_Datasend = 0;
            viragePart = 2;
        }

    }
    else if(m_eEtatIAMotor == eEtatIAMotorSortie)
    {
        ControlMotor(127, 127);

        if(m_structDataIA.iDistanceGauche > 200)
        {
            qDebug() << "Sortie en cours";
            m_eEtatIAMotor = eEtatIAMotorVirageGauche;
            ite_Datasend = 0;
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorVirageGauche)
    {
        ControlMotor(32, 127);

        ite_Datasend++;
        if(ite_Datasend >= 10 && viragePart == 0)
        {
            m_eEtatIAMotor = eEtatIAMotorArriere;
            ite_Datasend = 0;
            viragePart = 1;
        }
        if(ite_Datasend >= 10 && viragePart == 2)
        {
            m_eEtatIAMotor = eEtatIAMotorNone;
            m_eActionRobot = eActionRobotRigole;
            viragePart = 0;
            qDebug() << "Fin Virage";
        }
    }
}

/**
 * @brief IAMoteur::ExterieurRigole
 */
void IAMoteur::ExterieurRigole()
{
    NbRigole++;

    if(m_structDataIA.iDistanceRef >= 600)            // Si le point le plus proche est très éloigné
    {
        ControlMotor(127, 127);
        m_eActionRobot = m_eActionRobotPrecVirage;
        m_eEtatIAMotor = eEtatIAMotorSortie;
        qDebug() << "Sortie Actif";
    }

    if(m_structDataIA.iDistanceRef > 200)
    {
        if(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche)
            ControlMotor(96, 127);
        else
            ControlMotor(127, 96);

    }else
    if(m_structDataIA.iDistanceRef < 200)
    {
        if(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche)
            ControlMotor(127, 96);
        else
            ControlMotor(96, 127);
    }
    else if(m_structDataIA.iDistanceRef == 200)
        ControlMotor(127, 127);
}

/**
 * @brief IAMoteur::DataResult
 */
void IAMoteur::DataResult()
{
    QList<qint16> lstiDistance = m_pLidar->getDistanceList();

    m_structDataIA.iDegreeDroite = 0;
    m_structDataIA.iDegreeGauche = 0;
    m_structDataIA.iDegreeRef = 0;
    m_structDataIA.iDistanceDroite = 1000;
    m_structDataIA.iDistanceGauche = 1000;
    m_structDataIA.iDistanceRef = 1000;

    for(int iIncrement = 0; iIncrement < 90; iIncrement++)
    {
        if(lstiDistance.at(iIncrement + 45) != 0 && lstiDistance.at(iIncrement + 45) < m_structDataIA.iDistanceGauche)
        {
            m_structDataIA.iDistanceGauche = lstiDistance.at(iIncrement + 45);
            m_structDataIA.iDegreeGauche = iIncrement;
        }

        if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < m_structDataIA.iDistanceDroite)
        {
            m_structDataIA.iDistanceDroite = lstiDistance.at(225 - iIncrement);
            m_structDataIA.iDegreeDroite = iIncrement;
        }
    }

    m_structDataIA.iDistanceRef = qMin(m_structDataIA.iDistanceDroite, m_structDataIA.iDistanceGauche);

    m_structDataIA.iLargerRigol = qAbs(m_structDataIA.iDistanceDroite) + qAbs(m_structDataIA.iDistanceGauche);

    if(m_structDataIA.iDistanceRef == m_structDataIA.iDistanceGauche)
        m_structDataIA.iDegreeRef = m_structDataIA.iDegreeGauche;
    else
        m_structDataIA.iDegreeRef = m_structDataIA.iDegreeDroite;
}

/**
 * @brief IAMoteur::ControlMotor
 * @param p_iMotorLeft
 * @param p_iMotorRight
 */
void IAMoteur::ControlMotor(int p_iMotorLeft, int p_iMotorRight)
{
    QByteArray baDataToSend;

    baDataToSend[0] = p_iMotorLeft;
    baDataToSend[1] = p_iMotorRight;

    m_pMotor->SendData(baDataToSend);
}
