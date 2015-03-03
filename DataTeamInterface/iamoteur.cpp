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
    int etatcourant;

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
    /***            MACH A ETAT             ****/
    /*******************************************/

    if(Difference == 0 && MotorLeft == 0 && MotorRight == 0) // Etat 1
    {
        baValue[0]=127; // Tout Droit
        baValue[1]=127;
    }
    else
    {
        if(Difference < 0)  //Etat 2 Obstacle à droite + Important
        {
            if(MotorLeft < 10000 && MotorRight < 7000) //On tourne progréssivement
            {
                baValue[0]=90; // a droite, grand angle
                baValue[1]=127;

            }else //On tourne rapidement
            if(MotorLeft < 10000 && MotorRight > 7000 && MotorRight < 10000) //On tourne rapidement
            {
                baValue[0]=50; // a droite, petit angle
                baValue[1]=127;
            }
            else
            if(MotorLeft > 10000 && MotorRight < 10000)
            {
                baValue[0]=10; // a droite, Quasiment sur place
                baValue[1]=127;
            }
            else
            if(MotorLeft > 10000 && MotorRight > 10000)
            {
                baValue[0]=-127; // a droite, Quasiment sur place
                baValue[1]=-127;
            }
        }
        else if(Difference > 0) //Etat 3 Obstacle à gauche + Important
        {
            if(MotorRight < 10000 && MotorLeft < 7000) //On tourne progréssivement
            {
                baValue[1]=90; // a gauche, grand angle
                baValue[0]=127;

            }else //On tourne rapidement
            if(MotorRight < 10000 && MotorLeft > 7000 && MotorLeft < 10000) //On tourne rapidement
            {
                baValue[1]=50; // a gauche, petit angle
                baValue[0]=127;
            }
            else
            if(MotorRight > 10000 && MotorLeft < 10000)
            {
                baValue[1]=10; // a gauche, Quasiment sur place
                baValue[0]=127;
            }
            else
            if(MotorRight > 10000 && MotorLeft > 10000)
            {
                baValue[1]=-127; // a gauche, Quasiment sur place
                baValue[0]=-127;
            }

        }
        else if(Difference == 0 && MotorRight > 12000 && MotorLeft > 12000) //Trop proche d'un obstacle en face, on recule
        {
                baValue[0]=-127;
                baValue[1]=-127;
        }
        else if(Difference == 0 && MotorRight <10000 && MotorLeft < 10000) //On avance tout droit
        {
                baValue[0]=127;
                baValue[1]=127;
        }
    }




    //baValue[0]=127;
    //baValue[1]=127;
    m_pMotor->SendData(baValue);

    qDebug() << "_____________________________________________________________";
    qDebug() << " Motor Left = " << MotorLeft;
    qDebug() << " Motor Right = " << MotorRight;
    qDebug() << " Difference = " << Difference;

}
