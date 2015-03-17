#ifndef IAMOTEUR_H
#define IAMOTEUR_H

#include <QObject>
#include "lidar.h"
#include "motor.h"
#include "odo.h"
#include "global.h"

#define START_LIDAR_VISIBILITY_RANGE 45
#define END_LIDAR_VISIBILITY_RANGE 225
#define DEFAULT_DISTANCE_VALUE 1000
#define DEFAULT_DEGREE_VALUE 0

class IAMoteur : public QObject
{
    Q_OBJECT
private:
    Lidar *m_pLidar;
    Motor *m_pMotor;
    Odo *m_pOdo;

    double MaxReadedValueMotor;

    eEtatIAMotor m_eEtatIAMotor;
    eActionRobot m_eActionRobot;
    eActionRobot m_eActionRobotPrecVirage;

    structDataIA m_structDataIA;

    int m_iRigoleCount;

    bool m_bSauteRigoleFini;
    bool m_bRr, m_bRl, m_bFr, m_bFl;
    int m_iRr, m_iRl, m_iFr, m_iFl;

    bool IsHalfTurnRight();
    bool IsLastHalfTurnRight();
    bool IsHalfTurnLeft();
    bool IsLastHalfTurnLeft();
    bool IsBackEnough();
    void ResetOdoValue();

    void MonTest();
    void InterieurRigole();
    void Virage();
    void ExterieurRigole();

    void DataResult();
    void ControlMotor(int p_iMotorLeft, int p_iMotorRight, bool p_bInverse);

public:
    explicit IAMoteur(Lidar *p_pLidar, Motor* p_pMotor, Odo *p_pOdo, QObject *parent = 0);
    ~IAMoteur();

    void EtatParcelle();
    void MachineAEtat();

    eEtatIAMotor getEtatIAMotor() const;
    void setEtatIAMotor(const eEtatIAMotor &p_eEtatIAMotor);


signals:

public slots:
    void onDataFromOdoReady();

};

#endif // IAMOTEUR_H
