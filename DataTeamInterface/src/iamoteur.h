#ifndef IAMOTEUR_H
#define IAMOTEUR_H

#include <QObject>
#include "lidar.h"
#include "motor.h"
#include "odo.h"
#include "global.h"

#define START_LIDAR_VISIBILITY_RANGE 45
#define END_LIDAR_VISIBILITY_RANGE 225

#define DEFAULT_DISTANCE_VALUE 4000
#define DEFAULT_DEGREE_VALUE 0

#define AVERAGE_DISTANCE_SAMPLE_MAX 50
#define LIMIT_RANGE 200

class IAMoteur : public QObject
{
    Q_OBJECT
private:
    Lidar *m_pLidar;
    Motor *m_pMotor;
    Odo *m_pOdo;

    double MaxReadedValueMotor;

    eEtatIAMotor m_eEtatIAMotor;
    ePositionRobot m_ePositionRobot;
    ePositionRobot m_ePositionRobotPrec;
    ePositionRobot m_ePositionRobotPrecVirage;

    structDataIA m_structDataIA;
    structVirageData m_structVirageIA;

    int m_iReturnRigol;
    int m_iRigoleCount;
    int m_iReturnToDo;

    double m_dIntegral;
    double m_dError;

    bool m_bRr, m_bRl, m_bFr, m_bFl;
    int m_iRr, m_iRl, m_iFr, m_iFl;

    // Test Odométrique
    double Kp, Ki, Kd;

    bool IsHalfTurnRight();
    bool IsLastHalfTurnRight();
    bool IsHalfTurnLeft();
    bool IsLastHalfTurnLeft();
    bool IsBackEnough();
    void ResetOdoValue();

    void InversePositionVirage();

    // Gestion des passages rigoles
    void InterieurRigole();
    void ExterieurRigole();

    // Gestion des virages
    void MachineEtatVirage();
    void SortieRigole();
    void ReculeVirage();
    void SauteRigole();
    void DebutVirage();
    void FinVirage();

    // Controle des moteurs
    void PID(bool bInverse);
    void ControlMotor(int p_iMotorLeft, int p_iMotorRight, bool p_bInverse);

    // Traitement des données
    void DataResult();
    void DataResultVirage();
    void CalculLargeurRigole();
    double CalculDistanceArcVirage();
    int CalculLargeurReference();

    double CalculX(int p_iDistance, int p_iDegree);
    double CalculY(int p_iDistance, int p_iDegree);

public:
    explicit IAMoteur(Lidar *p_pLidar, Motor* p_pMotor, Odo *p_pOdo, QObject *parent = 0);
    ~IAMoteur();

    void MachineAEtat();
    void Reset();

    // Ascessor - Mutator

    eEtatIAMotor getEtatIAMotor() const;
    void setEtatIAMotor(const eEtatIAMotor &p_eEtatIAMotor);

    ePositionRobot getPositionRobot() const;
    void setPositionRobot(const ePositionRobot &p_ePositionRobot);
    double getKp();
    void setKp(double value);

    double getKi();
    void setKi(double value);

    double getKd();
    void setKd(double value);

signals:
    void signalRigolEnd();

public slots:
    void slotOnDataReadyFromOdo();

};

#endif // IAMOTEUR_H
