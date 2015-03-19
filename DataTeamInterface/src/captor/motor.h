#ifndef MOTOR_H
#define MOTOR_H

#include <QObject>
#include "global.h"
#include "captor.h"

class Motor : public Captor
{
    Q_OBJECT
private:

    eEtatIAMotor m_eEtatIAMotor;

public:
    Motor(Protocole *p_pProtocole);
    ~Motor();

    bool SendData(QByteArray p_pDataToSend);

    eEtatIAMotor getEtatIAMotor() const;
    void setEtatIAMotor(const eEtatIAMotor &eEtatIAMotor);

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);
};

#endif // MOTOR_H
