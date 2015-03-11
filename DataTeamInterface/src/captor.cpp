#include "captor.h"

/**
 * @brief Captor::Captor
 * @param parent
 */

bool Captor::IsConnected()
{
    return m_IsConnected;
}

void Captor::setIsConnected(bool IsConnected)
{
    m_IsConnected = IsConnected;
}

Captor::Captor()
{
    m_eIDCommand = eIDCommandNone;
    m_pProtocole = NULL;

    m_pTCPConnection = new TCPConnection();
    m_bIsConnectionEtablished = false;

    connect(m_pTCPConnection, SIGNAL(Connected()), this, SLOT(slotOnConnection()));
    connect(m_pTCPConnection, SIGNAL(Disconnected()), this, SLOT(slotOnDisconnection()));
    connect(m_pTCPConnection, SIGNAL(DataReceivedFromServer(QByteArray)), this, SLOT(slotOnDataReceivedFromServer(QByteArray)));

    connect(this, SIGNAL(emitDataExtractedAvailable(QByteArray)), this, SLOT(slotOnDataExtractedReady(QByteArray)));
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
    return m_pTCPConnection->SendData(m_pProtocole->FormateCommand(m_eIDCommand, p_pDataToSend));
}

/**
 * @brief Captor::ReverseData
 * @param p_baData
 * @return
 */
QByteArray Captor::ReverseData(QByteArray p_baData)
{
    QByteArray baData;
    for(int iIncrement = p_baData.length() - 1; iIncrement >= 0; iIncrement--)
        baData += p_baData.mid(iIncrement, 1);
    return baData;
}

/*******************************************************************************/
/*********************************** SLOT **************************************/
/*******************************************************************************/

/**
 * @brief Captor::slotOnConnection
 */
void Captor::slotOnConnection()
{
    m_bIsConnectionEtablished = true;
}

/**
 * @brief Captor::slotOnDisconnection
 */
void Captor::slotOnDisconnection()
{
    m_bIsConnectionEtablished = false;
}

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
void Captor::slotOnDataExtractedReady(QByteArray p_baDataExtracted)
{
    Q_UNUSED(p_baDataExtracted);
    emit emitDataAvailable();
}
