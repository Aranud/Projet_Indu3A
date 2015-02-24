#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <QObject>
#include "captor.h"
#include "global.h"

class Actuator : public Captor
{
    Q_OBJECT
private:

public:
    Actuator(Protocole* p_pProtocole);
    ~Actuator();

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);
};

#endif // ACTUATOR_H
