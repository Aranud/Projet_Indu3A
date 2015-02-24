#include "actuator.h"

/**
 * @brief Actuator::Actuator
 */
Actuator::Actuator(Protocole *p_pProtocole)
{
    m_pProtocole = p_pProtocole;
    m_eIDCommand = eIDCommmandActuator;
    m_iActuator = 0;
}

/**
 * @brief Actuator::~Actuator
 */
Actuator::~Actuator()
{

}

/*******************************************************************************/
/**************************** ACCESSOR - MODIFICATOR ***************************/
/*******************************************************************************/

/**
 * @brief Actuator::setActuator
 * @param p_iXActuator
 */
void Actuator::setActuator(const qint16 &p_iXActuator)
{
    m_iActuator = p_iXActuator;
}

/**
 * @brief Actuator::getActuator
 * @return
 */
qint16 Actuator::getActuator() const
{
    return m_iActuator;
}

/*******************************************************************************/
/******************************** SLOT *****************************************/
/*******************************************************************************/

/**
 * @brief Actuator::slotOnDataExtractedReady
 * @param p_baDataExtracted
 */
void Actuator::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    qDebug() << "Actuator : " << p_baDataExtracted.toHex();

    m_iActuator = p_baDataExtracted.toHex().toInt();

    emit emitDataAvailable();
}
