#ifndef LIDAR_H
#define LIDAR_H

#include <QObject>
#include "captor.h"
#include "global.h"

class Lidar : public Captor
{
    Q_OBJECT
private:

public:
    Lidar(Protocole* p_pProtocole);
    ~Lidar();

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);
};

#endif // LIDAR_H
