#include "captor.h"

/**
 * @brief Captor::Captor
 */
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
/**************************** ACCESSOR - MUTATOR *******************************/
/*******************************************************************************/

bool Captor::getIsConnected()
{
    return m_IsConnected;
}

/**
 * @brief Captor::setIsConnected
 * @param IsConnected
 */
void Captor::setIsConnected(bool IsConnected)
{
    m_IsConnected = IsConnected;
}

/**
 * @brief Captor::getEIDCommand
 * @return
 */
eIDCommand Captor::getEIDCommand()
{
    return m_eIDCommand;
}

/**
 * @brief Captor::setEIDCommand
 * @param eIDCommand
 */
void Captor::setEIDCommand(eIDCommand &eIDCommand)
{
    m_eIDCommand = eIDCommand;
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
    emit emitConnected();
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
