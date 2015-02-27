#ifndef GYRO_H
#define GYRO_H

#include <QObject>
#include "captor.h"
#include "global.h"

class Gyro : public Captor
{
    Q_OBJECT
private:
    qint16 m_iXGyro;
    qint16 m_iYGyro;
    qint16 m_iZGyro;

public:
    Gyro(Protocole *p_pProtocole);
    ~Gyro();

    qint16 getXGyro() const;
    void setXGyro(const qint16 &p_iXGyro);

    qint16 getYGyro() const;
    void setYGyro(const qint16 &p_iYGyro);

    qint16 getZGyro() const;
    void setZGyro(const qint16 &p_iZGyro);

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);

};

#endif // GYRO_H
