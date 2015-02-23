#include "lidar.h"

/**
 * @brief Lidar::Lidar
 */
Lidar::Lidar()
{
}

/**
 * @brief Lidar::~Lidar
 */
Lidar::~Lidar()
{

}

/**
 * @brief Lidar::slotOnDataExtractedReady
 * @param p_baDataExtracted
 */
void Lidar::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    qDebug() << p_baDataExtracted;
}
