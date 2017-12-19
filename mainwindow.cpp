#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "QMessageBox"


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

    this->hide();
    loginWindow = new Login(&customers, this);
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
    for(int i=0; i < count; i++)
    {
        if(personNrActive ==bookings.getPersonNr(i));
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
