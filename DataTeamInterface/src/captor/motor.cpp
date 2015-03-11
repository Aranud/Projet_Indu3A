#include "motor.h"

/**
 * @brief Motor::Motor
 */
Motor::Motor(Protocole* p_pProtocole)
{
    m_pProtocole = p_pProtocole;
    m_eIDCommand = eIDCommmandMotors;
}

/**
 * @brief Motor::~Motor
 */
Motor::~Motor()
{

}

/*******************************************************************************/
/********************************** SLOT ***************************************/
/*******************************************************************************/

/**
 * @brief Motor::slotOnDataExtractedReady
 * @param p_baDataExtracted
 */
void Motor::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    Q_UNUSED(p_baDataExtracted);
    emit emitDataAvailable();
}
