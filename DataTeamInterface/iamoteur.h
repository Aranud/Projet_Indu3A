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

public:
    explicit IAMoteur(Lidar *p_pLidar, Motor* p_pMotor,  QObject *parent = 0);
    ~IAMoteur();

    void EtatParcelle();
    void MachineAEtat();

    void MonTest();
    void InterieurRigole();
    void Virage();

    eEtatIAMotor getEtatIAMotor() const;
    void setEtatIAMotor(const eEtatIAMotor &p_eEtatIAMotor);

signals:

public slots:

};

#endif // IAMOTEUR_H
