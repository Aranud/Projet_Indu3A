#include "gps.h"

/**
 * @brief GPS::GPS
 */
GPS::GPS(Protocole *p_pProtocole)
{
    m_eIDCommand = eIDCommmandGPS;
    m_pProtocole = p_pProtocole;

    m_dTime = 0.0;
    m_dLatitude = 0.0;
    m_dLongitude = 0.0;
    m_dAltitude = 0.0;
    m_dGroundSpeed = 0.0;
    m_iSateliteNumber = 0;

    m_baUnit.clear();
    m_baQuality.clear();
}

/**
 * @brief GPS::~GPS
 */
GPS::~GPS()
{

}

/*******************************************************************************/
/**************************** ACCESSOR - MODIFICATOR ***************************/
/*******************************************************************************/

/**
 * @brief GPS::getTime
 * @return
 */
double GPS::getTime() const
{
    return m_dTime;
}

/**
 * @brief GPS::setTime
 * @param p_dTime
 */
void GPS::setTime(double p_dTime)
{
    m_dTime = p_dTime;
}

/**
 * @brief GPS::getLatitude
 * @return
 */
double GPS::getLatitude() const
{
    return m_dLatitude;
}

/**
 * @brief GPS::setLatitude
 * @param p_dLatitude
 */
void GPS::setLatitude(double p_dLatitude)
{
    m_dLatitude = p_dLatitude;
}

/**
 * @brief GPS::getLongitude
 * @return
 */
double GPS::getLongitude() const
{
    return m_dLongitude;
}

/**
 * @brief GPS::setLongitude
 * @param p_dLongitude
 */
void GPS::setLongitude(double p_dLongitude)
{
    m_dLongitude = p_dLongitude;
}

/**
 * @brief GPS::getAltitude
 * @return
 */
double GPS::getAltitude() const
{
    return m_dAltitude;
}

/**
 * @brief GPS::setAltitude
 * @param p_dAltitude
 */
void GPS::setAltitude(double p_dAltitude)
{
    m_dAltitude = p_dAltitude;
}

/**
 * @brief GPS::getGroundSpeed
 * @return
 */
double GPS::getGroundSpeed() const
{
    return m_dGroundSpeed;
}

/**
 * @brief GPS::setGroundSpeed
 * @param p_dGroundSpeed
 */
void GPS::setGroundSpeed(double p_dGroundSpeed)
{
    m_dGroundSpeed = p_dGroundSpeed;
}

/**
 * @brief GPS::getUnit
 * @return
 */
QByteArray GPS::getUnit() const
{
    return m_baUnit;
}

/**
 * @brief GPS::setUnit
 * @param p_baUnit
 */
void GPS::setUnit(const QByteArray &p_baUnit)
{
    m_baUnit = p_baUnit;
}

/**
 * @brief GPS::getSateliteNumber
 * @return
 */
int GPS::getSateliteNumber() const
{
    return m_iSateliteNumber;
}

/**
 * @brief GPS::setSateliteNumber
 * @param p_baSateliteNumber
 */
void GPS::setSateliteNumber(const int &p_iSateliteNumber)
{
    m_iSateliteNumber = p_iSateliteNumber;
}

/**
 * @brief GPS::getQuality
 * @return
 */
QByteArray GPS::getQuality() const
{
    return m_baQuality;
}

/**
 * @brief GPS::setQuality
 * @param p_baQuality
 */
void GPS::setQuality(const QByteArray &p_baQuality)
{
    m_baQuality = p_baQuality;
}

/*******************************************************************************/
/*********************************** SLOT **************************************/
/*******************************************************************************/

/**
 * @brief GPS::slotOnDataExtractedReady
 * @param p_sDataExtracted
 */
void GPS::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    qlonglong llTemp = 0;

    llTemp = ReverseData(p_baDataExtracted.mid(0, 8)).toHex().toLongLong(0, 16);
    m_dTime = reinterpret_cast<double&>(llTemp);

    llTemp = ReverseData(p_baDataExtracted.mid(8, 8)).toHex().toLongLong(0, 16);
    m_dLatitude = reinterpret_cast<double&>(llTemp);

    llTemp = ReverseData(p_baDataExtracted.mid(16, 8)).toHex().toLongLong(0, 16);
    m_dLongitude = reinterpret_cast<double&>(llTemp);

    llTemp = ReverseData(p_baDataExtracted.mid(24, 8)).toHex().toLongLong(0, 16);
    m_dAltitude = reinterpret_cast<double&>(llTemp);

    m_baUnit = p_baDataExtracted.mid(32, 1).toHex();
    m_iSateliteNumber = p_baDataExtracted.mid(33, 1).toHex().toInt(0, 16);
    m_baQuality = p_baDataExtracted.mid(34, 1).toHex();

    llTemp = ReverseData(p_baDataExtracted.mid(35, 8)).toHex().toLongLong(0, 16);
    m_dGroundSpeed = reinterpret_cast<double&>(llTemp);

    emit emitDataAvailable();
}
