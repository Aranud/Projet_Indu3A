#include "mainwindow.h"
#include <QApplication>

/**
 * @brief main - Soft. Start Ffrom There
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(w.width(), w.height());
    w.show();

    return a.exec();
}
