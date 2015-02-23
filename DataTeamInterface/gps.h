#ifndef GPS_H
#define GPS_H

#include <QObject>
#include "global.h"
#include "captor.h"

class GPS : public Captor
{
    Q_OBJECT
private:
    double m_dTime;
    double m_dLatitude;
    double m_dLongitude;
    double m_dAltitude;
    double m_dGroundSpeed;
    QByteArray m_baUnit;
    QByteArray m_baSateliteNumber;
    QByteArray m_baQuality;


public:
    GPS(Protocole* p_pProtocole);
    ~GPS();

    double getTime() const;
    void setTime(double p_dTime);

    double getLatitude() const;
    void setLatitude(double p_dLatitude);

    double getLongitude() const;
    void setLongitude(double p_dLongitude);

    double getAltitude() const;
    void setAltitude(double p_dAltitude);

    double getGroundSpeed() const;
    void setGroundSpeed(double p_dGroundSpeed);

    QByteArray getUnit() const;
    void setUnit(const QByteArray &p_baUnit);

    QByteArray getSateliteNumber() const;
    void setSateliteNumber(const QByteArray &p_baSateliteNumber);

    QByteArray getQuality() const;
    void setQuality(const QByteArray &p_baQuality);

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);

};

#endif // GPS_H
