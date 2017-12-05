#include "mainwindow.h"
#include <QApplication>
#include <QTextStream>
#include <QString>
#include "customerregister.h"
#include "hairdresserregister.h"
#include "haircut.h"
#include "colortreatment.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Hairdresser ab(01, "Kalle");
    hairdresserRegister hairdressers;
    hairdressers.addHairdresser(01,"Adam Backe");
    hairdressers.addHairdresser(02,"Lisa Svensson");
    CustomerRegister test;
    test.addCustomer(19950621, "Adina Knutsson", "adina@bokning.se", "Adinagatan", "losen");

    Haircut testing(200, 60, 01, "Klippning", "Långt hår", 01);
    ColorTreatment testing2(1000, 90, 02, "Färgning", "blond", 02); //Ska inte lägga till färg här!!
    QString test3 = QString::fromStdString(testing.ToString());
    //QString test1 = QString::fromStdString(
    QString test2 = QString::fromStdString(test.ToString(19950621));
    QString test4 = QString::fromStdString(testing2.ToString());
    QTextStream(stdout) << /*test1 <<*/ "\n" << test2 << "\n" << test3 << "\n" << test4;

    w.show();

    return a.exec();
}
