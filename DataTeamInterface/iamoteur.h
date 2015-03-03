#ifndef IAMOTEUR_H
#define IAMOTEUR_H

#include <QObject>
#include "lidar.h"
#include "motor.h"

class IAMoteur : public QObject
{
    Q_OBJECT
public:
    explicit IAMoteur(Lidar *p_pLidar, Motor* p_pMotor,  QObject *parent = 0);
    ~IAMoteur();

    Lidar *m_pLidar;
    Motor *m_pMotor;


    void MachineEtat();

signals:

public slots:

};

#endif // IAMOTEUR_H
