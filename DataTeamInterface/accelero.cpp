#include "accelero.h"

/**
 * @brief Accelero::Accelero
 */
Accelero::Accelero(Protocole *p_pProtocole)
{
    m_pProtocole = p_pProtocole;
    m_eIDCommand = eIDCommmandAccelero;

    m_iXAccelero = 0;
    m_iYAccelero = 0;
    m_iZAccelero = 0;
}

/**
 * @brief Accelero::~Accelero
 */
Accelero::~Accelero()
{

}

/*******************************************************************************/
/**************************** ACCESSOR - MODIFICATOR ***************************/
/*******************************************************************************/

/**
 * @brief Accelero::getXAccelero
 * @return
 */
qint16 Accelero::getXAccelero() const
{
    return m_iXAccelero;
}

/**
 * @brief Accelero::setXAccelero
 * @param p_iXAccelero
 */
void Accelero::setXAccelero(const qint16 &p_iXAccelero)
{
    m_iXAccelero = p_iXAccelero;
}

/**
 * @brief Accelero::getYAccelero
 * @return
 */
qint16 Accelero::getYAccelero() const
{
    return m_iYAccelero;
}

/**
 * @brief Accelero::setYAccelero
 * @param p_iYAccelero
 */
void Accelero::setYAccelero(const qint16 &p_iYAccelero)
{
    m_iYAccelero = p_iYAccelero;
}

/**
 * @brief Accelero::getZAccelero
 * @return
 */
qint16 Accelero::getZAccelero() const
{
    return m_iZAccelero;
}

/**
 * @brief Accelero::setZAccelero
 * @param p_iZAccelero
 */
void Accelero::setZAccelero(const qint16 &p_iZAccelero)
{
    m_iZAccelero = p_iZAccelero;
}

/*******************************************************************************/
/********************************** SLOT ***************************************/
/*******************************************************************************/

/**
 * @brief Accelero::slotOnDataExtractedReady
 * @param p_baDataExtracted
 */
void Accelero::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    qDebug() << "Accelero Data Extracted : " << p_baDataExtracted.toHex();
    qDebug() << "Accelero Data Extracted Lenght : " << p_baDataExtracted.length();

    m_iXAccelero = ReverseData(p_baDataExtracted.mid(0, 2)).toHex().toInt();
    m_iYAccelero = ReverseData(p_baDataExtracted.mid(2, 2)).toHex().toInt();
    m_iZAccelero = ReverseData(p_baDataExtracted.mid(4, 2)).toHex().toInt();

    qDebug() << "Accelero Value --> X : "<< m_iXAccelero << " Y : " << m_iXAccelero << " Z : " << m_iZAccelero;

    emit emitDataAvailable();
}
