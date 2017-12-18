#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "QMessageBox"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), customers(), bookings(), hairdressers()
{
    ui->setupUi(this);
    personNrActive = 1995;

    hairdressers.addHairdresser(0,"Anna Larsson");
    hairdressers.addHairdresser(1,"Lisa Svensson");
    hairdressers.addHairdresser(2,"Pernilla Johansson");
    hairdressers.addHairdresser(3, "Mia Karlsson");
    hairdressers.addHairdresser(4, "Karl Olsson");

    Haircut cutLong(400, 01, "Klippning", "Långt hår");
    Haircut cutShort(300, 02, "Klippning", "kort hår");
    Haircut shave(200, 03, "Rakning", "Rakning");
    ColorTreatment coloringBlonde(1000, 04, "Färgning", "Ljust");
    ColorTreatment coloringDark(1200, 05, "Slingor", "Mörkt");
    //Ska inte lägga till färg här?
    ColorTreatment strandsBrown(1200, 06, "Slingor", "Mörk");
    ColorTreatment strandsBlonde(1200, 07, "Slingor", "Ljust");
    //hide();
    loginWindow = new Login(&customers, this);
    loginWindow->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCustomer(int personNr, std::string name, std::string email, std::string address, std::string password)
{
    customers.addCustomer(personNr, name, email, address, password);
}

void MainWindow::setActiveCustomer(int personNr)
{
    personNrActive = personNr;
}

void MainWindow::on_bookTime_clicked()
{
    bookWindow = new bookTime(&bookings, &hairdressers, this);
    bookWindow->show();
    hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    int count = bookings.getCounter();
    std::string booking;
    for(int i=0; i < count; i++)
    {
        if(personNrActive ==bookings.getPersonNr(i));
        {
            booking = bookings.toString(i);
            //int treatmentID = bookings.getTreatmentIDAtIndex(i);
            int hairdresserID = bookings.gethairdresserIDAtIndex(i);
            for(int n=0; n < hairdressers.getNrOfHairdressers(); n++)
            {
                if(hairdressers.gethairdresserID(n) == hairdresserID)
                {
                   std::string name = hairdressers.getNameToComboBox(n);
                }
            }
        }
    }
}
