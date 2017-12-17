#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), customers(), bookings(), hairdressers()
{
    ui->setupUi(this);

    hairdressers.addHairdresser(01,"Anna Larsson");
    hairdressers.addHairdresser(02,"Lisa Svensson");
    hairdressers.addHairdresser(03,"Pernilla Johansson");
    hairdressers.addHairdresser(04, "Mia Karlsson");
    hairdressers.addHairdresser(05, "Karl Olsson");

    Haircut cutLong(400, 60, 01, "Klippning", "Långt hår");
    Haircut cutShort(300, 30, 02, "Klippning", "kort hår");
    Haircut shave(200, 30, 03, "Rakning", "Rakning");
    ColorTreatment coloring(1000, 60, 04, "Färgning", "blond");
    //Ska inte lägga till färg här?
    ColorTreatment strands(1200, 90, 05, "Slingor", "brunt");

    loginWindow = new Login(&customers, this);
    loginWindow->show();
    this->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCustomer(int personNr, std::string name, std::string email, std::string address, std::string password)
{
    customers.addCustomer(personNr, name, email, address, password);
}

void MainWindow::on_bookTime_clicked()
{
    bookWindow = new bookTime(&bookings, &hairdressers, this);
    bookWindow->show();
    hide();
}
