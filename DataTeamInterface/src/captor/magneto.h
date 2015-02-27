#ifndef MAGNETO_H
#define MAGNETO_H

#include <QObject>
#include "global.h"
#include "captor.h"

class Magneto : public Captor
{
    Q_OBJECT
private:
    qint16 m_iXMagneto;
    qint16 m_iYMagneto;
    qint16 m_iZMagneto;
public:
    Magneto(Protocole* p_pProtocole);
    ~Magneto();

    void setXMagneto(const qint16 &p_iXMagneto);
    qint16 getXMagneto() const;

    void setYMagneto(const qint16 &p_iYMagneto);
    qint16 getYMagneto() const;

    void setZMagneto(const qint16 &p_iZMagneto);
    qint16 getZMagneto() const;

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);
};

#endif // MAGNETO_H
