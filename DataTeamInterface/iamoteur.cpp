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

    int iDistance = 1000;
    int iDegree = 0;

    if(m_eEtatIAMotor == eEtatIAMotorSortie)
    {
        baValue[0] = 127;
        baValue[1] = 127;
        m_pMotor->SendData(baValue);

        for(int iIncrement = 0; iIncrement < 90; iIncrement++)
        {
            if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < iDistance)
            {
                iDistance = lstiDistance.at(225 - iIncrement);
                iDegree = iIncrement;

                if(iDistance < 200)
                    return;
            }
        }

        m_eEtatIAMotor = eEtatIAMotorVirageDroite;
        return;
    }

    if(m_eEtatIAMotor == eEtatIAMotorVirageDroite)
    {
        baValue[0] = 127;
        baValue[1] = 32;

        for(int iIncrement = 0; iIncrement < 90; iIncrement++)
        {
            if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < iDistance)
            {
                iDistance = lstiDistance.at(225 - iIncrement);
                iDegree = iIncrement;

                if(iDistance < 200)
                {
                    m_eEtatIAMotor = eEtatIAMotorNone;
                    break;
                }
            }
        }
        m_pMotor->SendData(baValue);
        return;
    }

//    if(m_eEtatIAMotor == eEtatIAMotorArriere)
//    {
//        baValue[0] = -127;
//        baValue[1] = -127;
//        m_eEtatIAMotor = eEtatIAMotorNone;
//    }

    for(int iIncrement = 0; iIncrement < 90; iIncrement++)
    {
        if(lstiDistance.at(iIncrement + 45) != 0 && lstiDistance.at(iIncrement + 45) < iDistance)
        {
            iDistance = lstiDistance.at(iIncrement + 45);
            iDegree = iIncrement;
            m_eEtatIAMotor = eEtatIAMotorDroite;
        }

        if(lstiDistance.at(225 - iIncrement) != 0 && lstiDistance.at(225 - iIncrement) < iDistance)
        {
            iDistance = lstiDistance.at(225 - iIncrement);
            iDegree = iIncrement;
            m_eEtatIAMotor = eEtatIAMotorGauche;
        }
    }

    if(iDistance >= 500)
    {
        baValue[0] = 127;
        baValue[1] = 127;
        m_eEtatIAMotor = eEtatIAMotorSortie;
    }
    else if(iDistance > 100)
    {
        baValue[0] = 127;
        baValue[1] = 127;
        m_eEtatIAMotor = eEtatIAMotorAvant;
    }
    else if(m_eEtatIAMotor == eEtatIAMotorDroite)
    {
        baValue[0] = 127;

        if(iDegree < 45)
            baValue[1] = 63;
        else
            baValue[1] = 0;
    }
    else if(m_eEtatIAMotor == eEtatIAMotorGauche)
    {
        baValue[1] = 127;
        if(iDegree < 45)
            baValue[0] = 63;
        else
            baValue[0] = 0;
    }

    m_pMotor->SendData(baValue);
}
