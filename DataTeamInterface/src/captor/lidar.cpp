#include "lidar.h"

/**
 * @brief Lidar::Lidar
 */
Lidar::Lidar(Protocole *p_pProtocole)
{
    m_pProtocole = p_pProtocole;
    m_eIDCommand = eIDCommmandLidar;

    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(7);
    m_lstiPoids.append(7);
    m_lstiPoids.append(7);
    m_lstiPoids.append(7);
    m_lstiPoids.append(7);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(13);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(12);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(11);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(10);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(9);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(8);
    m_lstiPoids.append(7);
    m_lstiPoids.append(7);
    m_lstiPoids.append(7);
    m_lstiPoids.append(7);
    m_lstiPoids.append(7);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(6);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(5);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(4);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(3);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(2);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(1);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);
    m_lstiPoids.append(0);

;


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

        emit emitDataAvailable();
    }
}
