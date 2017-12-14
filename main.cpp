#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QTextStream>
#include <QString>
#include "customerregister.h"
#include "hairdresserregister.h"
#include "haircut.h"
#include "colortreatment.h"
#include "bookingregister.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    /*
    hairdresserRegister hairdressers;
    hairdressers.addHairdresser(01,"Anna Larsson");
    hairdressers.addHairdresser(02,"Lisa Svensson");
    hairdressers.addHairdresser(03,"Pernilla Johansson");
    hairdressers.addHairdresser(04, "Mia Karlsson");
    hairdressers.addHairdresser(05, "Karl Olsson");
*/
    //CustomerRegister test;
    //test.addCustomer(19950621, "Adina Knutsson", "adina@bokning.se", "Adinagatan", "losen");



    Haircut cutLong(400, 60, 01, "Klippning", "Långt hår");
    Haircut cutShort(300, 30, 02, "Klippning", "kort hår");
    Haircut shave(200, 30, 03, "Rakning", "Rakning");
    ColorTreatment coloring(1000, 60, 04, "Färgning", "blond");
    //Ska inte lägga till färg här?
    ColorTreatment strands(1200, 90, 05, "Slingor", "brunt");

    bookingRegister bookings;
    bookings.addBooking(01, 01,20171202, 1000, 19950621);
    bookings.addBooking(03,05,20171201,1200, 19950621);

    //QString test3 = QString::fromStdString(test.ToString(19950621));
    QString test1 = QString::fromStdString(bookings.toString(19950621));
    //QString test2 = QString::fromStdString(test.getName(19950621));
    QString test4 = QString::fromStdString(shave.ToString());

    //QTextStream(stdout) << test1 << "\n" << test2 << "\n" << test4;


    //w.hide();
    w.show();

    return a.exec();
}
