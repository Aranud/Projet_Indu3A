#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include "global.h"
#include "captor.h"

class Motor : public Captor
{
    Q_OBJECT
public:
    Motor(Protocole *p_pProtocole);
    ~Motor();

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);
};

#endif // MOTOR_H
