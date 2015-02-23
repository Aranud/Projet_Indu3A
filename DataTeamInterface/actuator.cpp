#include "actuator.h"

/**
 * @brief Actuator::Actuator
 */
Actuator::Actuator()
{
}

/**
 * @brief Actuator::~Actuator
 */
Actuator::~Actuator()
{

}

/**
 * @brief Actuator::slotOnDataExtractedReady
 * @param p_baDataExtracted
 */
void Actuator::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    qDebug() << p_baDataExtracted;
}
