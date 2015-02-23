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
    qDebug() << "Data Extracted : " << p_baDataExtracted.toHex();
    qDebug() << "Data Extracted Lenght : " << p_baDataExtracted.length();

    m_iXGyro = p_baDataExtracted.mid(0, 2).toInt();
    m_iYGyro = p_baDataExtracted.mid(2, 2).toInt();
    m_iZGyro = p_baDataExtracted.mid(4, 2).toInt();

    qDebug() << "X : "<< m_iXGyro << " Y : " << m_iXGyro << " Z : " << m_iZGyro;

    emit emitDataAvailable();
}
