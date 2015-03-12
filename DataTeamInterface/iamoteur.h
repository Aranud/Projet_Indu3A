#ifndef IAMOTEUR_H
#define IAMOTEUR_H

#include <QObject>
#include "lidar.h"
#include "motor.h"
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
    double MaxReadedValueMotor;

    eEtatIAMotor m_eEtatIAMotor;
    eActionRobot m_eActionRobot;
    eActionRobot m_eActionRobotPrecVirage;

    structDataIA m_structDataIA;

    int m_iDataSendCount;
    int m_iViragePartCount;
    int m_iRigoleCount;

    void MonTest();
    void InterieurRigole();
    void Virage();
    void ExterieurRigole();

    void DataResult();
    void ControlMotor(int p_iMotorLeft, int p_iMotorRight, bool p_bInverse);

public:
    explicit IAMoteur(Lidar *p_pLidar, Motor* p_pMotor,  QObject *parent = 0);
    ~IAMoteur();

    void EtatParcelle();
    void MachineAEtat();

    eEtatIAMotor getEtatIAMotor() const;
    void setEtatIAMotor(const eEtatIAMotor &p_eEtatIAMotor);

signals:

public slots:

};

#endif // IAMOTEUR_H
