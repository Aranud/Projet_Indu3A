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

void Lidar::setDistanceList(const QList<qint16> &lstiDistance)
{
    m_lstiDistance = lstiDistance;
}

QList<qint16> Lidar::getDegreeList() const
{
    return m_lstiDegree;
}

void Lidar::setDegreeList(const QList<qint16> &lstiDegree)
{
    m_lstiDegree = lstiDegree;
}

QList<qint16> Lidar::getAlbedoList() const
{
    return m_lstiAlbedo;
}

void Lidar::setAlbedoList(const QList<qint16> &lstiAlbedo)
{
    m_lstiAlbedo = lstiAlbedo;
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
        m_lstiDegree.clear();
        m_lstiAlbedo.clear();

        for(int iIncrement = 0; iIncrement < 271; iIncrement++)
        {
            m_lstiDistance.append(QString::number(p_baDataExtracted.at(iIncrement)).toInt());
            m_lstiDegree.append(QString::number(p_baDataExtracted.at(iIncrement + 271)).toInt());
            m_lstiAlbedo.append(QString::number(p_baDataExtracted.at(iIncrement + 542)).toInt());
        }

    //    m_lstiDistance.append(ReverseData(p_baDataExtracted.mid(0, 271)).toHex().toInt());
    //    m_lstiDegree.append(ReverseData(p_baDataExtracted.mid(271, 271)).toHex().toInt());
    //    m_lstiAlbedo.append(ReverseData(p_baDataExtracted.mid(542, 271)).toHex().toInt());

        //qDebug() << "lstDistance" << m_lstiDistance;
        //qDebug() << "lstDegree" << m_lstiDegree;
       // qDebug() << "lstAlbedo" << m_lstiAlbedo;

        emit emitDataAvailable();
    }
}
