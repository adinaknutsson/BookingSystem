#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "QMessageBox"
#include <QFile>
#include <QTextStream>

//KOLLA TA BORT BOKNINGEN! KOLLAR ALDRIG PERSONNR.
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), customers(), bookings(), hairdressers()
{
    ui->setupUi(this);

    hairdressers.addHairdresser(0,"Anna Larsson");
    hairdressers.addHairdresser(1,"Lisa Svensson");
    hairdressers.addHairdresser(2,"Pernilla Johansson");
    hairdressers.addHairdresser(3, "Mia Karlsson");
    hairdressers.addHairdresser(4, "Karl Olsson");

    counterTreatments=0;
    treatments = new Treatment*[capacityTreatments];
    treatments[counterTreatments++] = new Haircut(400, 1, "Klippning", "Långt hår");
    treatments[counterTreatments++] = new Haircut(300, 2, "Klippning", "kort hår");
    treatments[counterTreatments++] = new Haircut(200, 3, "Rakning", "Rakning");
    treatments[counterTreatments++] =new ColorTreatment(1000, 4, "Färgning", "Ljust");
    treatments[counterTreatments++] = new ColorTreatment (1200, 5, "Färgning", "Mörkt");
    treatments[counterTreatments++] =new ColorTreatment(1500, 6, "Slingor långt hår", "Mörkt");
    treatments[counterTreatments++] = new ColorTreatment(1200, 7, "Slingor kort hår", "Mörkt");
    treatments[counterTreatments++] = new ColorTreatment (1500, 8, "Slingor långt hår", "Ljust");
    treatments[counterTreatments++] = new ColorTreatment (1200, 9, "Slingor kort hår", "Ljust");

    QFile readFileCustomers("customersFile.txt");
    QFile readFileBookings("bookingFile.txt");
    if(readFileCustomers.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&readFileCustomers);
        QString nrOfCustomers = in.readLine();
        int counterCustomers = nrOfCustomers.toInt();
        for (int i=0; i < counterCustomers; i++)
        {
            QString personNr = in.readLine();
            int personNr2 = personNr.toInt();
            QString name = in.readLine();
            std::string name2 = name.toStdString();
            QString email = in.readLine();
            std::string email2 = email.toStdString();
            QString address = in.readLine();
            std::string address2 = address.toStdString();

            QString password = in.readLine();
            std::string password2 = password.toStdString();
            customers.addCustomer(personNr2, name2, email2, address2, password2);
        }
    }

    if (readFileBookings.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in2(&readFileBookings);
        QString nrOfBookings = in2.readLine();
        int counterBookings= nrOfBookings.toInt();
        for (int i=0; i < counterBookings; i++)
        {
            QString hairdresserID = in2.readLine();
            int hairdresserID2 = hairdresserID.toInt();
            QString treatmentID = in2.readLine();
            int treatmentID2 = treatmentID.toInt();
            QString date = in2.readLine();
            int date2 = date.toInt();
            QString time = in2.readLine();
            int time2 = time.toInt();
            QString personNr = in2.readLine();
            int personNr2 = personNr.toInt();
            bookings.addBooking(hairdresserID2, treatmentID2, date2,time2,personNr2);
        }
    }

    this->hide();
    loginWindow = new Login(&customers,&bookings, this);
    loginWindow->setModal(true);
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
    personNrActive = customers.getActiveUser();
    bookWindow = new bookTime(&bookings, &hairdressers, treatments, personNrActive, this);
    bookWindow->show();
    hide();
}

void MainWindow::on_pushButton_2_clicked()
{
    int count = bookings.getCounter();
    std::string booking ="";
    //personNrActive = customers.getActiveUser();
    for(int i=0; i < count; i++)
    {
        if (customers.getActiveUser() == bookings.getPersonNr(i))
        {
            booking = booking + bookings.toString(i);
            int treatmentID = bookings.getTreatmentIDAtIndex(i);
            int hairdresserID = bookings.gethairdresserIDAtIndex(i);
            for(int n=0; n < hairdressers.getNrOfHairdressers(); n++)
            {
                if(hairdressers.gethairdresserID(n) == hairdresserID)
                {
                   std::string nameHairdresser= hairdressers.getNameToComboBox(n);
                   n = hairdressers.getNrOfHairdressers();
                   booking = booking+ "Frisör: " + nameHairdresser + "\n";
                }
            }
            for (int j=0; j < counterTreatments; j++)
            {
                if (treatments[j]->getTreatmentID() == treatmentID)
                {
                    std::string treatment = treatments[i]->getName();
                    int price = treatments[i]->getPrice();
                    booking =booking + "Behandling: " + treatment + "\n";
                    booking =booking + "Pris: " + std::to_string(price) + "\n\n";
                    j = counterTreatments;
                }
            }

        }
    }
    QString bookingsString = QString::fromStdString(booking);
    QMessageBox::information(this, "Bokningar",bookingsString);
}

void MainWindow::on_pushButton_3_clicked()
{
    informationWindow = new changeInformation(&customers,personNrActive, this);
    informationWindow->show();
    hide();
}

void MainWindow::on_removeBooking_clicked()
{
    removeWindow = new removeBooking(&bookings, personNrActive,  this);
    removeWindow->show();
    hide();
}

void MainWindow::on_logOut_clicked()
{
    loginWindow->show();
    personNrActive =0;
}
