#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include "customerregister.h"
#include "hairdresserregister.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Hairdresser ab(01, "Kalle");
    CustomerRegister.addCustomer(19950621, "Adina Knutsson", "adina@bokning.se", "Adinagatan", "losen");

   // QTextStream(stdout) << ab.getName() << "\n" << CustomerRegister.ToString();

    w.show();

    return a.exec();
}
