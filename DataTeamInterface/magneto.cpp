#include "magneto.h"

/**
 * @brief Magneto::Magneto
 */
Magneto::Magneto(Protocole *p_pProtocole)
{
    m_pProtocole = p_pProtocole;
    m_eIDCommand = eIDCommmandMagneto;

    m_iXMagneto = 0;
    m_iYMagneto = 0;
    m_iZMagneto = 0;
}

/**
 * @brief Magneto::~Magneto
 */
Magneto::~Magneto()
{

}

/*******************************************************************************/
/**************************** ACCESSOR - MODIFICATOR ***************************/
/*******************************************************************************/

/**
 * @brief Magneto::getXMagneto
 * @return
 */
qint16 Magneto::getXMagneto() const
{
    return m_iXMagneto;
}

/**
 * @brief Magneto::setXMagneto
 * @param p_iXMagneto
 */
void Magneto::setXMagneto(const qint16 &p_iXMagneto)
{
    m_iXMagneto = p_iXMagneto;
}

/**
 * @brief Magneto::getYMagneto
 * @return
 */
qint16 Magneto::getYMagneto() const
{
    return m_iYMagneto;
}

/**
 * @brief Magneto::setYMagneto
 * @param p_iYMagneto
 */
void Magneto::setYMagneto(const qint16 &p_iYMagneto)
{
    m_iYMagneto = p_iYMagneto;
}

/**
 * @brief Magneto::getZMagneto
 * @return
 */
qint16 Magneto::getZMagneto() const
{
    return m_iZMagneto;
}

/**
 * @brief Magneto::setZMagneto
 * @param p_iZMagneto
 */
void Magneto::setZMagneto(const qint16 &p_iZMagneto)
{
    m_iZMagneto = p_iZMagneto;
}

/*******************************************************************************/
/********************************** SLOT ***************************************/
/*******************************************************************************/

/**
 * @brief Magneto::slotOnDataExtractedReady
 * @param p_baDataExtracted
 */
void Magneto::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    qDebug() << "Magneto Data Extracted : " << p_baDataExtracted.toHex();
    qDebug() << "Magneto Data Extracted Lenght : " << p_baDataExtracted.length();

    m_iXMagneto = ReverseData(p_baDataExtracted.mid(0, 2)).toHex().toInt();
    m_iYMagneto = ReverseData(p_baDataExtracted.mid(2, 2)).toHex().toInt();
    m_iZMagneto = ReverseData(p_baDataExtracted.mid(4, 2)).toHex().toInt();

    qDebug() << "Magneto Value --> X : "<< m_iXMagneto << " Y : " << m_iXMagneto << " Z : " << m_iZMagneto;

    emit emitDataAvailable();
}
