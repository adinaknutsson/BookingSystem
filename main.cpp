#include "mainwindow.h"
#include <QApplication>
#include "hairdresser.h"
#include <QTextStream>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Hairdresser ab(01, "Kalle");

    QTextStream(stdout) << ab.getName();

    w.show();

    return a.exec();
}
