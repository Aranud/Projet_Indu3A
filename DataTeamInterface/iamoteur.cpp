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
}

/**
 * @brief IAMoteur::~IAMoteur
 */
IAMoteur::~IAMoteur()
{

}

void IAMoteur::MachineEtat()
{
    QList<qint16> lstiPoids;
    QList<qint16> lstiDistance;
    QList<qint16> PxD;

    QByteArray baValue;
    //int etatcourant;

    double MotorLeft = 0;
    double MotorRight = 0;
    double Difference;


    lstiDistance = m_pLidar->getDistanceList();
    lstiPoids = m_pLidar->getPoidsList();

    //PxD = lstiDistance * lstiPoids;

    for(int i = 0 ; i < lstiPoids.length(); i++)
    {
            PxD.append(lstiDistance.at(i) * lstiPoids.at(i));
    }

    qDebug() << "****************MATRICE**************************************";
    qDebug() << "Lidar Liste PxD : " << PxD;
    qDebug() << "_____________________________________________________________";
    qDebug() << "Lidar Liste Poids : " << lstiPoids;
    qDebug() << "_____________________________________________________________";
    qDebug() << "Lidar Liste Distance : " << lstiDistance;
    qDebug() << "*************************************************************";

    for(int iteML=0; iteML < 136 ; iteML++)
       MotorLeft += PxD.at(iteML);

    qDebug() << "__________________________******______________________________";

    for(int iteMR=136; iteMR < 271 ; iteMR++)
       MotorRight += PxD.at(iteMR);


    Difference = MotorLeft - MotorRight;
    //qDebug() << " Difference = " << Difference;

    /*******************************************/
    /***     INITIALISATION MACH A ETAT     ****/
    /*******************************************/

    baValue[0]=127;
    baValue[1]=127;
    m_pMotor->SendData(baValue);

    qDebug() << "_____________________________________________________________";
    qDebug() << " Motor Left = " << MotorLeft;
    qDebug() << " Motor Right = " << MotorRight;
    qDebug() << " Difference = " << Difference;

}
