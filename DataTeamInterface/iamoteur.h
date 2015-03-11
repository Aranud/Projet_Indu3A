#ifndef IAMOTEUR_H
#define IAMOTEUR_H

#include <QObject>
#include "lidar.h"
#include "motor.h"
#include "global.h"

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

    int ite_Datasend;
    int viragePart;

    void MonTest();
    void InterieurRigole();
    void VirageDroite();
    void VirageGauche();
    void ExterieurRigole();

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
