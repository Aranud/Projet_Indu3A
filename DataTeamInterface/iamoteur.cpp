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
    switch(m_eActionRobot)
    {
        case eActionRobotRigole : InterieurRigole(); break;
        case eActionRobotGrandVirageDroite : VirageDroite(); break;
        case eActionRobotGrandVirageGauche : VirageGauche(); break;
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
    QList<qint16> lstiDistance;
    QByteArray baValue;
    int iDistanceDroite = 1000, iDistanceGauche = 1000, iDistanceRef = 1000;
    int iDegreeDroite = 0, iDegreeGauche = 0, iDegreeRef = 0;

    lstiDistance = m_pLidar->getDistanceList();

    for(int iIncrement = 0; iIncrement < 90; iIncrement++)
    {
        if(lstiDistance.at(iIncrement + 45) != 0 && lstiDistance.at(iIncrement + 45) < iDistanceRef)
        {
            iDistanceDroite = lstiDistance.at(iIncrement + 45);
            iDegreeDroite = iIncrement;
            m_eEtatIAMotor = eEtatIAMotorDroite;
        }

        if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < iDistanceRef)
        {
            iDistanceGauche = lstiDistance.at(225 - iIncrement);
            iDegreeGauche = iIncrement;
            m_eEtatIAMotor = eEtatIAMotorGauche;
        }

        iDistanceRef = qMin(iDistanceDroite, iDistanceGauche);
    }

    if(iDistanceRef == iDistanceGauche)
        iDegreeRef = iDegreeGauche;
    else
        iDegreeRef = iDegreeDroite;

    if(iDistanceRef >= 600)            // Si le point le plus proche est très éloigné
    {
        baValue[0] = 127;
        baValue[1] = 127;

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
    else if(iDistanceRef > 180)
    {
        if(iDegreeRef > 70 && iDegreeRef == iDegreeGauche)
        {
            baValue[0] = 127;
            baValue[1] = 96;
            qDebug() << "Avant Leger Droite";
        }
        else if (iDegreeRef > 70 && iDegreeRef == iDegreeDroite)
        {
            baValue[0] = 96;
            baValue[1] = 127;
            qDebug() << "Avant Leger Gauche";
        }
        else
        {
            baValue[0] = 127;
            baValue[1] = 127;
            m_eEtatIAMotor = eEtatIAMotorAvant;
            qDebug() << "Avant";
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorDroite)
    {
        baValue[0] = 127;

        if(iDegreeRef < 45)
            baValue[1] = 96;
        else if(iDegreeRef < 60)
            baValue[1] = 63;
        else
            baValue[1] = 0;

        qDebug() << "Correction Droite";
    }
    else if(m_eEtatIAMotor == eEtatIAMotorGauche)
    {
        baValue[1] = 127;

        if(iDegreeRef < 45)
            baValue[0] = 96;
        else if(iDegreeRef < 60)
            baValue[0] = 63;
        else
            baValue[0] = 0;

        qDebug() << "Correction Gauche";
    }
    else
    {
        baValue[0] = 127;
        baValue[1] = 127;
        qDebug() << "Ne Rien Faire A L'Interieur???";
    }

    m_pMotor->SendData(baValue);
}

/**
 * @brief IAMoteur::VirageDroite
 */
void IAMoteur::VirageDroite()
{
    QList<qint16> lstiDistance;
    QByteArray baValue;

    lstiDistance = m_pLidar->getDistanceList();

    int iDistanceDroite = 1000, iDistanceGauche = 1000, iDistanceRef = 1000;
    int iDegreeDroite = 0, iDegreeGauche = 0, iDegreeRef = 0;

    for(int iIncrement = 0; iIncrement < 90; iIncrement++)
    {
        if(lstiDistance.at(iIncrement + 45) != 0 && lstiDistance.at(iIncrement + 45) < iDistanceGauche)
        {
            iDistanceGauche = lstiDistance.at(iIncrement + 45);
            iDegreeGauche = iIncrement;
        }

        if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < iDistanceDroite)
        {
            iDistanceDroite = lstiDistance.at(225 - iIncrement);
            iDegreeDroite = iIncrement;
        }
    }

    if(m_eEtatIAMotor == eEtatIAMotorArriere)
    {
        baValue[0] = -127;
        baValue[1] = -127;
        m_pMotor->SendData(baValue);

        if(iDistanceDroite > 200)
            m_eEtatIAMotor = eEtatIAMotorVirageDroite;

    }
    else if(m_eEtatIAMotor == eEtatIAMotorSortie)
    {
        baValue[0] = 127;
        baValue[1] = 127;
        m_pMotor->SendData(baValue);

        if(iDistanceDroite > 200)
        {
            qDebug() << "Sortie en cours";
            m_eEtatIAMotor = eEtatIAMotorVirageDroite;
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorVirageDroite)
    {
        baValue[0] = 127;
        baValue[1] = 32;
        m_pMotor->SendData(baValue);
/*
        if(iDistanceDroite < 200)
        {
            baValue[0] = 32;
            baValue[1] = 127;
            m_pMotor->SendData(baValue);
            qDebug() << "Contre braque !!";
        }
        else if(iDistanceDroite < 250)
        {
            baValue[0] = 127;
            baValue[1] = 64;
            m_pMotor->SendData(baValue);
            qDebug() << "Virage Douceur !!";
        }
        else
            qDebug() << "Virage !!";

        if(iDistanceGauche < 350 && iDegreeGauche < 45)   // On retrouve un point a droite
        {
            m_eEtatIAMotor = eEtatIAMotorNone;
            m_eActionRobot = eActionRobotRigole;
            qDebug() << "Fin Virage";
        }*/

        if(iDistanceDroite < 350)
            m_eEtatIAMotor = eEtatIAMotorArriere;
    }
}

/**
 * @brief IAMoteur::VirageGauche
 */
void IAMoteur::VirageGauche()
{
    QList<qint16> lstiDistance;
    QByteArray baValue;

    lstiDistance = m_pLidar->getDistanceList();

    int iDistanceDroite = 1000, iDistanceGauche = 1000, iDistanceRef = 1000;
    int iDegreeDroite = 0, iDegreeGauche = 0, iDegreeRef = 0;

    for(int iIncrement = 0; iIncrement < 90; iIncrement++)
    {
        if(lstiDistance.at(iIncrement + 45) != 0 && lstiDistance.at(iIncrement + 45) < iDistanceGauche)
        {
            iDistanceGauche = lstiDistance.at(iIncrement + 45);
            iDegreeGauche = iIncrement;
        }

        if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < iDistanceDroite)
        {
            iDistanceDroite = lstiDistance.at(225 - iIncrement);
            iDegreeDroite = iIncrement;
        }
    }

    if(m_eEtatIAMotor == eEtatIAMotorArriere)
    {
        baValue[0] = -127;
        baValue[1] = -127;
        m_pMotor->SendData(baValue);

        if(iDistanceDroite > 200)
            m_eEtatIAMotor = eEtatIAMotorVirageDroite;

    }
    else if(m_eEtatIAMotor == eEtatIAMotorSortie)
    {
        baValue[0] = 127;
        baValue[1] = 127;
        m_pMotor->SendData(baValue);

        if(iDistanceDroite > 200)
        {
            qDebug() << "Sortie en cours";
            m_eEtatIAMotor = eEtatIAMotorVirageDroite;
        }
    }
    else if(m_eEtatIAMotor == eEtatIAMotorVirageDroite)
    {
        baValue[1] = 127;
        baValue[0] = 32;
        m_pMotor->SendData(baValue);

        if(iDistanceGauche < 200)
        {
            baValue[1] = 32;
            baValue[0] = 127;
            m_pMotor->SendData(baValue);
            qDebug() << "Contre braque !!";
        }
        else if(iDistanceGauche < 250)
        {
            baValue[1] = 127;
            baValue[0] = 64;
            m_pMotor->SendData(baValue);
            qDebug() << "Virage Douceur !!";
        }
        else
            qDebug() << "Virage !!";

        if(iDistanceDroite < 350 && iDegreeDroite < 45)   // On retrouve un point a droite
        {
            m_eEtatIAMotor = eEtatIAMotorNone;
            m_eActionRobot = eActionRobotRigole;
            qDebug() << "Fin Virage";
        }
        return;
    }
}
