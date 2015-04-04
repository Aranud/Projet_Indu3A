#include "gyro.h"

/**
 * @brief Gyro::Gyro
 */
Gyro::Gyro(Protocole* p_pProtocole)
{
    m_pProtocole = p_pProtocole;
    m_eIDCommand = eIDCommandGyro;

    m_iXGyro = 0;
    m_iYGyro = 0;
    m_iZGyro = 0;
}

/**
 * @brief Gyro::~Gyro
 */
Gyro::~Gyro()
{

}

/*******************************************************************************/
/**************************** ACCESSOR - MODIFICATOR ***************************/
/*******************************************************************************/

/**
 * @brief Gyro::getXGyro
 * @return
 */
qint16 Gyro::getXGyro() const
{
    return m_iXGyro;
}

/**
 * @brief Gyro::setXGyro
 * @param p_iXGyro
 */
void Gyro::setXGyro(const qint16 &p_iXGyro)
{
    m_iXGyro = p_iXGyro;
}

/**
 * @brief Gyro::getYGyro
 * @return
 */
qint16 Gyro::getYGyro() const
{
    return m_iYGyro;
}

/**
 * @brief Gyro::setYGyro
 * @param p_iYGyro
 */
void Gyro::setYGyro(const qint16 &p_iYGyro)
{
    m_iYGyro = p_iYGyro;
}

/**
 * @brief Gyro::getZGyro
 * @return
 */
qint16 Gyro::getZGyro() const
{
    return m_iZGyro;
}

/**
 * @brief Gyro::setZGyro
 * @param p_iZGyro
 */
void Gyro::setZGyro(const qint16 &p_iZGyro)
{
    m_iZGyro = p_iZGyro;
}

/*******************************************************************************/
/********************************** SLOT ***************************************/
/*******************************************************************************/

/**
 * @brief Gyro::slotOnDataReceivedFromServer
 */
void Gyro::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    m_iXGyro = ReverseData(p_baDataExtracted.mid(0, 2)).toHex().toInt(0,16);
    m_iYGyro = ReverseData(p_baDataExtracted.mid(2, 2)).toHex().toInt(0,16);
    m_iZGyro = ReverseData(p_baDataExtracted.mid(4, 2)).toHex().toInt(0,16);

    emit emitDataAvailable();
}
