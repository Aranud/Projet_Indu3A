#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include "global.h"
#include "captor.h"

class Motor : public Captor
{
    Q_OBJECT
public:
    Motor();
    ~Motor();

public slots:

};

#endif // MOTOR_H
