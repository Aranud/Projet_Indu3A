#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <QObject>
#include "captor.h"
#include "global.h"

class Actuator : public Captor
{
    Q_OBJECT
private:
    qint16 m_iActuator;

public:
    Actuator(Protocole* p_pProtocole);
    ~Actuator();

    void setActuator(const qint16 &p_iXActuator);
    qint16 getActuator() const;

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);
};

#endif // ACTUATOR_H
