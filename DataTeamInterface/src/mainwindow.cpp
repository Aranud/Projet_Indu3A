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
    ui->img->setPixmap(QPixmap(":icons/ICON_OZ_DISABLE").scaled(ui->img->width(),ui->img->height(),Qt::KeepAspectRatio));

    m_pRobot = new RobotInterface(ui);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow()
{
    if(m_pRobot)
        delete m_pRobot;
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
    Q_UNUSED(p_sDataReceived);
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
        m_pRobot->connectRobot();
}

/**
 * @brief MainWindow::on_pbSendData_clicked
 */
void MainWindow::on_pbSendData_clicked()
{
    m_pTCPConnection->SendData(ui->leDataToSend->text().toUtf8());

}

void MainWindow::on_pbAvant_pressed()
{
    ui->labelDemitour->setText("Avance");
    m_pRobot->pushButton(1);
}

void MainWindow::on_pbGauche_pressed()
{
    ui->labelDemitour->setText("Tourne à gauche");
    m_pRobot->pushButton(2);
}

void MainWindow::on_pbArriere_pressed()
{
    ui->labelDemitour->setText("Tourne à droite");
    m_pRobot->pushButton(3);
}

void MainWindow::on_pbDroite_pressed()
{
    ui->labelDemitour->setText("Recule");
    m_pRobot->pushButton(4);
}

void MainWindow::on_pbAvantGauche_pressed()
{
    ui->labelDemitour->setText("Avant Gauche");
    m_pRobot->pushButton(5);
}

void MainWindow::on_pbArierreDroit_pressed()
{
    ui->labelDemitour->setText("Arrière Droit");
    m_pRobot->pushButton(6);
}

void MainWindow::on_pbArriereGauche_pressed()
{
    ui->labelDemitour->setText("Arrière Droit");
    m_pRobot->pushButton(7);
}

void MainWindow::on_pbAvantDroit_pressed()
{
    ui->labelDemitour->setText("Avant Droit");
    m_pRobot->pushButton(8);
}
void MainWindow::on_pbDt_pressed()
{
    ui->labelDemitour->setText("test rotation");
    m_pRobot->pushButton(9);
}
void MainWindow::on_pbLevel1_clicked()
{
    ui->labelDemitour->setText("Level 1 en cours");
    m_pRobot->pushLevel1();
     ui->labelDemitour->setText("Fin");
}

void MainWindow::on_pbAvantGauche_released()
{
    m_pRobot->pushButton(0);
    ui->labelDemitour->setText("Fin");
}

void MainWindow::on_pbAvant_released()
{
     m_pRobot->pushButton(0);
    ui->labelDemitour->setText("Fin");
}

void MainWindow::on_pbAvantDroit_released()
{
    m_pRobot->pushButton(0);
    ui->labelDemitour->setText("Fin");
}

void MainWindow::on_pbGauche_released()
{
    m_pRobot->pushButton(0);
    ui->labelDemitour->setText("Fin");
}

void MainWindow::on_pbDt_released()
{
    m_pRobot->pushButton(0);
    ui->labelDemitour->setText("Fin");
}

void MainWindow::on_pbDroite_released()
{
    m_pRobot->pushButton(0);
    ui->labelDemitour->setText("Fin");
}

void MainWindow::on_pbArriereGauche_released()
{
    m_pRobot->pushButton(0);
    ui->labelDemitour->setText("Fin");
}

void MainWindow::on_pbArriere_released()
{
    m_pRobot->pushButton(0);
    ui->labelDemitour->setText("Fin");
}

void MainWindow::on_pbArierreDroit_released()
{
    m_pRobot->pushButton(0);
    ui->labelDemitour->setText("Fin");
}

void MainWindow::on_P_valueChanged(double dKp)
{
   m_pRobot->P_valueChanged(dKp);
}

void MainWindow::on_I_valueChanged(double dKi)
{
   m_pRobot->I_valueChanged(dKi);
}

void MainWindow::on_D_valueChanged(double dKd)
{
   m_pRobot->D_valueChanged(dKd);
}
