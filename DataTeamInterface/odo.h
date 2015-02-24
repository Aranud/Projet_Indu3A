#ifndef ODO_H
#define ODO_H

#include <QObject>
#include "captor.h"
#include "global.h"

class Odo : public Captor
{
    Q_OBJECT
private:
    bool m_bFrontRight;
    bool m_bRearRight;
    bool m_bRearLeft;
    bool m_bFrontLeft;

public:
    Odo(Protocole* p_pProtocole);
    ~Odo();

    bool getFrontRight() const;
    void setFrontRight(bool p_bFrontRight);

    bool getRearRight() const;
    void setRearRight(bool p_bRearRight);

    bool getRearLeft() const;
    void setRearLeft(bool p_bRearLeft);

    bool getFrontLeft() const;
    void setFrontLeft(bool p_bFrontLeft);

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);
};

#endif // ODO_H
