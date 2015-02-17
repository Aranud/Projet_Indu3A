#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pTCPConnection = new TCPConnection();

    m_bIsConnectionEtablished = false;

    connect(m_pTCPConnection, SIGNAL(Connected()), this, SLOT(slotOnConnection()));
    connect(m_pTCPConnection, SIGNAL(Disconnected()), this, SLOT(slotOnDisconnection()));
    connect(m_pTCPConnection, SIGNAL(DataReceivedFromServer(QString)), this, SLOT(slotOnDataReceived(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotOnConnection()
{
    m_bIsConnectionEtablished = true;
    ui->pbConnection->setText("Disconnect");
}

void MainWindow::slotOnDisconnection()
{
    m_bIsConnectionEtablished = false;
    ui->pbConnection->setText("Connect");
}

void MainWindow::slotOnDataReceived(QString p_sDataReceived)
{
    ui->lbDataReceived->setText(p_sDataReceived);
}

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

void MainWindow::on_pbSendData_clicked()
{
    m_pTCPConnection->SendData(ui->leDataToSend->text().toUtf8());
}
