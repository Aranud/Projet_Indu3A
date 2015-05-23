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

/**
 * @brief Motor::eEtatIAMotor
 * @return
 */
eEtatIAMotor Motor::getEtatIAMotor() const
{
    return m_eEtatIAMotor;
}

/**
 * @brief Motor::setEEtatIAMotor
 * @param eEtatIAMotor
 */
void Motor::setEtatIAMotor(const eEtatIAMotor &eEtatIAMotor)
{
    m_eEtatIAMotor = eEtatIAMotor;
}

/**
 * @brief Motor::SendData
 * @param p_pDataToSend
 * @return
 */
bool Motor::SendData(QByteArray p_pDataToSend)
{
    bool bDataSend = m_pTCPConnection->SendData(m_pProtocole->FormateCommand(m_eIDCommand, p_pDataToSend));


    if(p_pDataToSend.length() == 2)
    {
        if(p_pDataToSend.at(0) > 0 && p_pDataToSend.at(1) > 0)
            m_eEtatIAMotor = eEtatIAMotorAvant;
        if(p_pDataToSend.at(0) < 0 && p_pDataToSend.at(1) < 0)
            m_eEtatIAMotor = eEtatIAMotorReculeVirage;
    }


    return bDataSend;
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
