#include "lidar.h"

/**
 * @brief Lidar::Lidar
 */
Lidar::Lidar(Protocole *p_pProtocole)
{
    m_pProtocole = p_pProtocole;
    m_eIDCommand = eIDCommmandLidar;
}

/**
 * @brief Lidar::~Lidar
 */
Lidar::~Lidar()
{

}

/*******************************************************************************/
/**************************** ACCESSOR - MODIFICATOR ***************************/
/*******************************************************************************/

QList<qint16> Lidar::getDistanceList() const
{
    return m_lstiDistance;
}

void Lidar::setDistanceList(const QList<qint16> &p_lstiDistance)
{
    m_lstiDistance = p_lstiDistance;
}

QList<qint16> Lidar::getPoidsList() const
{
    return m_lstiPoids;
}

void Lidar::setPoidsList(const QList<qint16> &p_lstiPoids)
{
    m_lstiPoids = p_lstiPoids;
}


QList<qint16> Lidar::getAlbedoList() const
{
    return m_lstiAlbedo;
}

void Lidar::setAlbedoList(const QList<qint16> &p_lstiAlbedo)
{
    m_lstiAlbedo = p_lstiAlbedo;
}

/*******************************************************************************/
/********************************** SLOT ***************************************/
/*******************************************************************************/

/**
 * @brief Lidar::slotOnDataExtractedReady
 * @param p_baDataExtracted
 */
void Lidar::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    if(p_baDataExtracted.length() == 813)
    {
        m_lstiDistance.clear();
        m_lstiAlbedo.clear();

        for(int iIncrement = 0; iIncrement < 271; iIncrement++)
        {
            m_lstiDistance.append(p_baDataExtracted.mid(iIncrement * 2, 2).toHex().toInt());
            m_lstiAlbedo.append(QString::number(p_baDataExtracted.at(iIncrement + 542)).toInt());
        }
        emit emitDataAvailable();
    }
}
