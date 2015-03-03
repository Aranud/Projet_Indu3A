#ifndef LIDAR_H
#define LIDAR_H

#include <QObject>
#include "captor.h"
#include "global.h"

class Lidar : public Captor
{
    Q_OBJECT
private:
    QList<qint16> m_lstiDistance;
    QList<qint16> m_lstiAlbedo;

public:
    Lidar(Protocole* p_pProtocole);
    ~Lidar();

    QList<qint16> getDistanceList() const;
    void setDistanceList(const QList<qint16> &p_lstiDistance);

    QList<qint16> getAlbedoList() const;
    void setAlbedoList(const QList<qint16> &p_lstiAlbedo);

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);
};

#endif // LIDAR_H
