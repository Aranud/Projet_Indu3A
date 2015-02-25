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
        m_lstiPoids.clear();
        m_lstiAlbedo.clear();

        for(int iIncrement = 0; iIncrement < 271; iIncrement++)
        {
            m_lstiDistance.append(QString::number(p_baDataExtracted.at(iIncrement * 2)).toInt());
            m_lstiPoids.append(QString::number(p_baDataExtracted.at(iIncrement * 2 + 1)).toInt());
            m_lstiAlbedo.append(QString::number(p_baDataExtracted.at(iIncrement + 542)).toInt());
        }

    //    m_lstiDistance.append(ReverseData(p_baDataExtracted.mid(0, 271)).toHex().toInt());
    //    m_lstiDegree.append(ReverseData(p_baDataExtracted.mid(271, 271)).toHex().toInt());
    //    m_lstiAlbedo.append(ReverseData(p_baDataExtracted.mid(542, 271)).toHex().toInt());

        qDebug() << "lstDistance" << m_lstiDistance;
        qDebug() << "lstPoids" << m_lstiPoids;
        qDebug() << "lstAlbedo" << m_lstiAlbedo;

        emit emitDataAvailable();
    }
}
