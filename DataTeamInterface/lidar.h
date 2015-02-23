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
    Lidar();
    ~Lidar();

public slots:
    void slotOnDataExtractedReady(QByteArray p_baDataExtracted);
};

#endif // LIDAR_H
