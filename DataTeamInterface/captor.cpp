#include "captor.h"

/**
 * @brief Captor::Captor
 * @param parent
 */
Captor::Captor(eIDCommand p_eIDCommand, QObject *parent) :
    QObject(parent)
{
    m_eIDCommand = p_eIDCommand;

    //m_pProtocole = p_pProtocole->getInstance;

    m_pTCPConnection = new TCPConnection();
    m_bIsConnectionEtablished = false;

    connect(m_pTCPConnection, SIGNAL(Connected()), this, SLOT(slotOnConnection()));
    connect(m_pTCPConnection, SIGNAL(Disconnected()), this, SLOT(slotOnDisconnection()));
    connect(m_pTCPConnection, SIGNAL(DataReceivedFromServer(QByteArray)), this, SLOT(slotOnDataReceivedFromServer(QByteArray)));
}

/**
 * @brief Captor::~Captor
 */
Captor::~Captor()
{

}

/*******************************************************************************/
/*********************************** METHOD ************************************/
/*******************************************************************************/

/**
 * @brief Captor::ConnectCaptor
 * @param p_sAddresse
 * @param p_iPort
 * @return
 */
bool Captor::ConnectCaptor(QString p_sAddresse, qint16 p_iPort)
{
    return (m_bIsConnectionEtablished = m_pTCPConnection->ConnectFromServer(p_sAddresse, p_iPort));

}

/**
 * @brief Captor::DisconnectCaptor
 */
void Captor::DisconnectCaptor()
{
    m_pTCPConnection->DisconnectFromServer();
}

/**
 * @brief Captor::SendData
 * @param p_pDataToSend
 * @return
 */
bool Captor::SendData(QByteArray p_pDataToSend)
{
    Q_UNUSED(p_pDataToSend);
    return false;
}

/*******************************************************************************/
/*********************************** SLOT **************************************/
/*******************************************************************************/

/**
 * @brief Captor::slotOnDataReceivedFromServer
 * @param p_baData
 */
void Captor::slotOnDataReceivedFromServer(QByteArray p_baData)
{
    emit emitDataExtractedAvailable(m_pProtocole->ExtractData(p_baData));
}

/**
 * @brief Captor::slotOnDataExtractedReady
 * @param p_sDataExtracted
 */
void Captor::slotOnDataExtractedReady(QString p_sDataExtracted)
{
    emit emitDataAvailable(p_sDataExtracted);
}
