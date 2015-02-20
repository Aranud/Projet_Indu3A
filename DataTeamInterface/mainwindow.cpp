#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    m_pTCPConnection = new TCPConnection();
//    m_bIsConnectionEtablished = false;

    m_pJoystick = new Joystick();
    m_pProtocole = new Protocole();

    connect(m_pJoystick, SIGNAL(dataReceivedFromStick(QByteArray)), this, SLOT(slotOnJoystickTouch(QByteArray)));

    connect(m_pTCPConnection, SIGNAL(Connected()), this, SLOT(slotOnConnection()));
    connect(m_pTCPConnection, SIGNAL(Disconnected()), this, SLOT(slotOnDisconnection()));
    connect(m_pTCPConnection, SIGNAL(DataReceivedFromServer(QString)), this, SLOT(slotOnDataReceived(QString)));
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/*******************************************************************************/
/*********************************** SLOT **************************************/
/*******************************************************************************/

/**
 * @brief MainWindow::slotOnConnection
 */
void MainWindow::slotOnConnection()
{
    m_bIsConnectionEtablished = true;
    ui->pbConnection->setText("Disconnect");
}

/**
 * @brief MainWindow::slotOnDisconnection
 */
void MainWindow::slotOnDisconnection()
{
    m_bIsConnectionEtablished = false;
    ui->pbConnection->setText("Connect");
}

/**
 * @brief MainWindow::slotOnDataReceived
 * @param p_sDataReceived
 */
void MainWindow::slotOnDataReceived(QString p_sDataReceived)
{
    ui->lbDataReceived->setText(p_sDataReceived);
}

/**
 * @brief MainWindow::slotOnJoystickTouch
 * @param p_baData
 */
void MainWindow::slotOnJoystickTouch(QByteArray p_baData)
{
    QByteArray baCommandFormatted;
    baCommandFormatted.clear();

    baCommandFormatted = m_pProtocole->FormateCommand(eIDCommmandMotors, p_baData);

    qDebug() << baCommandFormatted;

    m_pTCPConnection->SendData(baCommandFormatted);
}

/*******************************************************************************/
/*********************************** SLOT BUTTON *******************************/
/*******************************************************************************/

/**
 * @brief MainWindow::on_pbConnection_clicked
 */
void MainWindow::on_pbConnection_clicked()
{
    if(m_bIsConnectionEtablished == false)
    {
        if(!m_pTCPConnection->ConnectFromServer(ui->leServerAddress->text(), ui->leServerPort->text().toInt()))
            qDebug() << "Data entry are wrong";
    }
    else
    {
        m_pTCPConnection->DisconnectFromServer();
    }
}

/**
 * @brief MainWindow::on_pbSendData_clicked
 */
void MainWindow::on_pbSendData_clicked()
{
    m_pTCPConnection->SendData(ui->leDataToSend->text().toUtf8());
}
