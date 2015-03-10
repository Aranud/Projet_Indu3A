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
 * @brief IAMoteur::EtatParcelle
 */
void IAMoteur::EtatParcelle()
{
    MonTest();

//    QList<qint16> lstiPoids;
//    QList<qint16> lstiDistance;
//    QList<qint16> PxD;

//    QByteArray baValue;

//    double MotorLeft = 0;
//    double MotorRight = 0;
//    double Difference;


//    lstiDistance = m_pLidar->getDistanceList();
//    lstiPoids = m_pLidar->getPoidsList();

//    for(int i = 0 ; i < lstiPoids.length(); i++)
//    {
//            if(lstiDistance.at(i) < 500)
//                PxD.append(lstiDistance.at(i) * lstiPoids.at(i));
//            else
//                PxD.append(0);
//    }

//    for(int iIncrement = 0; iIncrement < 136; iIncrement++)
//    {
//        MotorLeft += PxD.at(iIncrement);
//        MotorRight += PxD.at(iIncrement + 135);
//    }

//    Difference = MotorLeft - MotorRight;

//    if(qMax(MotorLeft, MotorRight) == MotorLeft) // Difference > 0
//    {
//        if(qAbs(Difference) < 20000)
//        {
//            if(MaxReadedValueMotor == 0)
//            {
//                baValue[0] = MotorLeft/MotorLeft * 127;
//                baValue[1] = (MotorRight/MotorLeft * 127) + 50;
////                qDebug() << " First time Etat 1 avec Diff < 20 000 et baValue[0] = " << baValue[0];
////                qDebug() << " , baValue[1] = " << baValue[1];
////                qDebug() << " , MaxReadedValueMotor = " << MaxReadedValueMotor;
////                qDebug() << "==========================";
//            }
//            else
//            {
//                if(qMax(MaxReadedValueMotor, MotorLeft)==MotorLeft)
//                {
//                    MaxReadedValueMotor = MotorLeft;

//                }

//                baValue[0] = MotorLeft/MotorLeft * 127;
//                baValue[1] = (MotorRight/MotorRight * 127) - 50;
////                qDebug() << " Etat 1 avec Diff < 20 000 et baValue[0] = " << baValue[0];
////                qDebug() << " , baValue[1] = " << baValue[1];
////                qDebug() << " , MaxReadedValueMotor = " << MaxReadedValueMotor;
////                qDebug() << "==========================";
//            }


//        }
//        else
//        {
////            qDebug() << " Etat 1 avec Diff > 20 000";
////            qDebug() << "==========================";
//            baValue[0] = -127;
//            baValue[1] = -127;
//        }

//    }
//    else
//    if(qMax(qAbs(MotorLeft), qAbs(MotorRight)) == MotorRight)// Difference < 0
//    {
//        if(qAbs(Difference) < 20000)
//        {
//            if(MaxReadedValueMotor == 0)
//            {
//                baValue[0] = MotorLeft/MotorRight * 127 + 50;
//                baValue[1] = (MotorRight/MotorRight * 127);
////                qDebug() << " First time Etat 2 avec Diff < 20 000 et baValue[0] = " << baValue[0];
////                qDebug() << " , baValue[1] = " << baValue[1];
////                qDebug() << " , MaxReadedValueMotor = " << MaxReadedValueMotor;
////                qDebug() << "==========================";
//            }
//            else
//            {
//                if(qMax(MaxReadedValueMotor, MotorRight)==MotorRight)
//                {
//                    MaxReadedValueMotor = MotorRight;

//                }

//                baValue[0] = MotorLeft/MotorLeft * 127 - 50;
//                baValue[1] = (MotorRight/MotorRight * 127);
////                qDebug() << " Etat 2 avec Diff < 20 000 et baValue[0] = " << baValue[0];
////                qDebug() << " , baValue[1] = " << baValue[1];
////                qDebug() << " , MaxReadedValueMotor = " << MaxReadedValueMotor;
////                qDebug() << "==========================";
//            }
//        }
//        else
//        {
////            qDebug() << " Etat 2 avec Diff > 20 000";
////            qDebug() << "==========================";
//            baValue[0] = -127;
//            baValue[1] = -127;
//        }

//    }
//    else
//    {
//        if(qAbs(Difference) < 10000)
//        {
//            baValue[0] = 127;
//            baValue[1] = 127;
//        }
//        else
//        {
//            baValue[0] = -127;
//            baValue[1] = -127;
//        }
//    }

//    m_pMotor->SendData(baValue);

////    qDebug() << "_____________________________________________________________";
////    qDebug() << " Motor Left = " << MotorLeft;
////    qDebug() << " Motor Right = " << MotorRight;
////    qDebug() << " Difference = " << Difference;

}

void IAMoteur::MachineAEtat()
{

}

void IAMoteur::MonTest()
{
    QList<qint16> lstiDistance;
    QByteArray baValue;

    lstiDistance = m_pLidar->getDistanceList();

    int iDistanceDroite, iDistanceGauche, iDistanceRef = 1000;
    int iDegreeDroite, iDegreeGauche, iDegreeRef = 0;

    if(m_eEtatIAMotor == eEtatIAMotorSortie)
    {
        baValue[0] = 127;
        baValue[1] = 127;
        m_pMotor->SendData(baValue);

        for(int iIncrement = 0; iIncrement < 90; iIncrement++)
        {
            // Test le cote droit de Oz
            if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < iDistanceRef)
            {
                iDistanceRef = lstiDistance.at(225 - iIncrement);
                iDegreeRef = iIncrement;

                if(iDistanceRef < 200)
                    return;
            }
        }

        qDebug() << "Sortie en cours";
        m_eEtatIAMotor = eEtatIAMotorVirageDroite;
        return;
    }

    if(m_eEtatIAMotor == eEtatIAMotorVirageDroite)
    {
        baValue[0] = 127;
        baValue[1] = 32;
        m_pMotor->SendData(baValue);
/*
        for(int iIncrement = 0; iIncrement < 90; iIncrement++)
        {
            if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < iDistance)
            {
                iDistance = lstiDistance.at(225 - iIncrement);
                iDegree = iIncrement;

                if(iDistance < 200)
                {
                    //m_eEtatIAMotor = eEtatIAMotorEntree;
                    m_eEtatIAMotor = eEtatIAMotorNone;
                    qDebug() << "Fin Virage";

                    baValue[0] = 127;
                    baValue[1] = 32;
                    m_pMotor->SendData(baValue);
                    break;
                }
            }
        }
*/
        for(int iIncrement = 0; iIncrement < 90; iIncrement++)
        {
            if(lstiDistance.at(iIncrement + 45) != 0 && lstiDistance.at(iIncrement + 45) < iDistanceRef)
            {
                iDistanceDroite = lstiDistance.at(iIncrement + 45);
                iDegreeDroite = iIncrement;
            }

            if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < iDistanceRef)
            {
                iDistanceGauche = lstiDistance.at(225 - iIncrement);
                iDegreeGauche = iIncrement;
            }
        }

        if(iDistanceGauche < 250)
        {
            baValue[0] = 127;
            baValue[1] = 64;
            m_pMotor->SendData(baValue);
            qDebug() << "Virage Douceur !!";
        }
        else
            qDebug() << "Virage !!";

        if(iDistanceDroite < 400)   // On retrouve un point a droite
        {
            m_eEtatIAMotor = eEtatIAMotorNone;
            qDebug() << "Fin Virage";
        }
        return;
    }
    InterieurRigole();
}

void IAMoteur::InterieurRigole()
{
    QList<qint16> lstiDistance;
    QByteArray baValue;
    int iDistanceDroite, iDistanceGauche, iDistanceRef = 1000;
    int iDegreeDroite, iDegreeGauche, iDegreeRef = 0;

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
        m_eEtatIAMotor = eEtatIAMotorSortie;
        qDebug() << "Sortie Actif";
    }
    else if(iDistanceRef > 250)
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
            baValue[1] = 63;
        else
            baValue[1] = 0;

        qDebug() << "Correction Droite";
    }
    else if(m_eEtatIAMotor == eEtatIAMotorGauche)
    {
        baValue[1] = 127;
        if(iDegreeRef < 45)
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

void IAMoteur::Virage()
{

}
