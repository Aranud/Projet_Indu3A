#include "actuator.h"

/**
 * @brief Actuator::Actuator
 */
Actuator::Actuator(Protocole *p_pProtocole)
{
    m_pProtocole = p_pProtocole;
    m_eIDCommand = eIDCommmandActuator;
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
