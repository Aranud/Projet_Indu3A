#include "odo.h"

/**
 * @brief Odo::Odo
 */
Odo::Odo(Protocole *p_pProtocole)
{
    m_pProtocole = p_pProtocole;
    m_eIDCommand = eIDCommmandOdo;

    m_bFrontRight = 0;
    m_bRearRight = 0;
    m_bRearLeft = 0;
    m_bFrontLeft = 0;
}

/**
 * @brief Odo::~Odo
 */
Odo::~Odo()
{

}

/*******************************************************************************/
/**************************** ACCESSOR - MODIFICATOR ***************************/
/*******************************************************************************/

/**
 * @brief Odo::getFrontRight
 * @return
 */
bool Odo::getFrontRight() const
{
    return m_bFrontRight;
}

/**
 * @brief Odo::setFrontRight
 * @param p_bFrontRight
 */
void Odo::setFrontRight(bool p_bFrontRight)
{
    m_bFrontRight = p_bFrontRight;
}

/**
 * @brief Odo::bRearRight
 * @return
 */
bool Odo::getRearRight() const
{
    return m_bRearRight;
}

/**
 * @brief Odo::setRearRight
 * @param p_bRearRight
 */
void Odo::setRearRight(bool p_bRearRight)
{
    m_bRearRight = p_bRearRight;
}

/**
 * @brief Odo::getRearLeft
 * @return
 */
bool Odo::getRearLeft() const
{
    return m_bRearLeft;
}

/**
 * @brief Odo::setRearLeft
 * @param p_bRearLeft
 */
void Odo::setRearLeft(bool p_bRearLeft)
{
    m_bRearLeft = p_bRearLeft;
}

/**
 * @brief Odo::getFrontLeft
 * @return
 */
bool Odo::getFrontLeft() const
{
    return m_bFrontLeft;
}

/**
 * @brief Odo::setFrontLeft
 * @param p_bFrontLeft
 */
void Odo::setFrontLeft(bool p_bFrontLeft)
{
    m_bFrontLeft = p_bFrontLeft;
}

/*******************************************************************************/
/********************************** SLOT ***************************************/
/*******************************************************************************/

/**
 * @brief Odo::slotOnDataExtractedReady
 * @param p_baDataExtracted
 */
void Odo::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    qDebug() << "Odo Data Extracted : " << p_baDataExtracted.toHex();
    qDebug() << "Odo Data Extracted Lenght : " << p_baDataExtracted.length();

    m_bFrontRight = p_baDataExtracted.mid(0, 2).toHex().toInt();
    m_bRearRight = p_baDataExtracted.mid(2, 2).toHex().toInt();
    m_bRearLeft = p_baDataExtracted.mid(4, 2).toHex().toInt();
    m_bFrontLeft = p_baDataExtracted.mid(6, 2).toHex().toInt();

    qDebug() << "Result From Od : " << m_bFrontRight << " | "
                                    << m_bRearRight << " | "
                                    << m_bRearLeft << " | "
                                    << m_bFrontLeft;

    emit emitDataAvailable();
}
