#ifndef ACCELERO_H
#define ACCELERO_H

#include <QObject>
#include "global.h"
#include "captor.h"

class Accelero : public Captor
{
    Q_OBJECT
private:
    qint16 m_iXAccelero;
    qint16 m_iYAccelero;
    qint16 m_iZAccelero;

public:
    Accelero(Protocole* p_pProtocole);
    ~Accelero();

    void setXAccelero(const qint16 &p_iXAccelero);
    qint16 getXAccelero() const;

    void setYAccelero(const qint16 &p_iYAccelero);
    qint16 getYAccelero() const;

    void setZAccelero(const qint16 &p_iZAccelero);
    qint16 getZAccelero() const;


public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);

};

#endif // ACCELERO_H
