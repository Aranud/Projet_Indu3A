#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpconnection.h"
#include "protocole.h"
//#include "joystick.h"
#include "global.h"
#include <QPixmap>
#include "gps.h"
#include "robotinterface.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TCPConnection* m_pTCPConnection;
    //Joystick* m_pJoystick;
    Protocole* m_pProtocole;
    RobotInterface* m_pRobot;



    bool m_bIsConnectionEtablished;

public slots:
    void slotOnConnection();
    void slotOnDisconnection();
    void slotOnDataReceived(QString p_sDataReceived);
    void slotOnJoystickTouch(QByteArray p_baData);

private slots:
    void on_pbConnection_clicked();
    void on_pbSendData_clicked();
    void on_pbDroite_pressed();
    void on_pbGauche_pressed();
    void on_pbAvant_pressed();
    void on_pbArriere_pressed();
    void on_pbLevel1_clicked();
    void on_pbAvantGauche_pressed();
    void on_pbDt_pressed();
    void on_pbAvantDroit_pressed();
    void on_pbArriereGauche_pressed();
    void on_pbArierreDroit_pressed();
    void on_pbAvantGauche_released();
    void on_pbAvant_released();
    void on_pbAvantDroit_released();
    void on_pbGauche_released();
    void on_pbDt_released();
    void on_pbDroite_released();
    void on_pbArriereGauche_released();
    void on_pbArriere_released();
    void on_pbArierreDroit_released();
    void on_P_valueChanged(double dKp);
    void on_I_valueChanged(double dKi);
    void on_D_valueChanged(double dKd);
};

#endif // MAINWINDOW_H
