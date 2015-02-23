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

    m_baUnit.clear();
    m_baSateliteNumber.clear();
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
QByteArray GPS::getSateliteNumber() const
{
    return m_baSateliteNumber;
}

/**
 * @brief GPS::setSateliteNumber
 * @param p_baSateliteNumber
 */
void GPS::setSateliteNumber(const QByteArray &p_baSateliteNumber)
{
    m_baSateliteNumber = p_baSateliteNumber;
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
    qDebug() << "Data Extracted : " << p_baDataExtracted.toHex();
    qDebug() << "Data Extracted Lenght : " << p_baDataExtracted.length();

//    m_dTime = p_baDataExtracted.mid(0, 8).toDouble();
//    m_dLatitude = p_baDataExtracted.mid(8, 8).toDouble();
//    m_dLongitude = p_baDataExtracted.mid(16, 8).toDouble();
//    m_dAltitude = p_baDataExtracted.mid(24, 8).toDouble();
//    m_baUnit = p_baDataExtracted.mid(32, 1);
//    m_baSateliteNumber = p_baDataExtracted.mid(33, 1);
//    m_baQuality = p_baDataExtracted.mid(34, 1);
//    m_dGroundSpeed = p_baDataExtracted.mid(35, 8).toDouble();

    qDebug() << p_baDataExtracted.mid(0, 8).toHex();
    //qDebug() << p_baDataExtracted.mid(8, 8).toHex();
    QByteArray baSomeData = p_baDataExtracted.mid(8, 8);

    baSomeData = ReverseData(baSomeData);
    baSomeData = baSomeData.toHex();
    m_dLatitude = baSomeData.toDouble();

    qDebug() << "Lat hex : " << baSomeData;
    qDebug() << "HERE : " << baSomeData.fromHex(baSomeData).toDouble();
    qDebug() << "And there :" << m_dLatitude;

    qDebug() << p_baDataExtracted.mid(16, 8).toHex();
    qDebug() << p_baDataExtracted.mid(24, 8).toHex();
    qDebug() << p_baDataExtracted.mid(32, 1).toHex();
    qDebug() << p_baDataExtracted.mid(33, 1).toHex();
    qDebug() << p_baDataExtracted.mid(34, 1).toHex();
    qDebug() << p_baDataExtracted.mid(35, 8).toHex();

    qDebug() << "MID ! : " << m_dTime << " : "
                           << m_dLatitude << " : "
                           << m_dLongitude << " : "
                           << m_dAltitude << " : "
                           << m_baUnit << " : "
                           << m_baSateliteNumber << " : "
                           << m_baQuality << " : "
                           << m_dGroundSpeed << " || STOP";

    QString sDataConca;
    sDataConca.append( + "MID ! : " + QString::number(m_dTime) + " : "
                           + QString::number(m_dLatitude) + " : "
                           + QString::number(m_dLongitude) + " : "
                           + QString::number(m_dAltitude) + " : "
                           + m_baUnit + " : "
                           + m_baSateliteNumber + " : "
                           + m_baQuality + " : "
                           + QString::number(m_dGroundSpeed) + " : ");

    emit emitDataAvailable(sDataConca);
}
