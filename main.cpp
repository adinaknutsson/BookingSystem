#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include <QString>
#include "customerregister.h"
#include "hairdresserregister.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Hairdresser ab(01, "Kalle");
    CustomerRegister test;
    test.addCustomer(19950621, "Adina Knutsson", "adina@bokning.se", "Adinagatan", "losen");

    QString test1 = QString::fromStdString(ab.getName());
    QString test2 = QString::fromStdString(test.ToString(19950621));

   QTextStream(stdout) << test1 << "\n" << test2;

    w.show();

    return a.exec();
}
