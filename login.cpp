#include "login.h"
#include "ui_login.h"
#include "newuser.h"
#include "loginuser.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>

Login::Login(CustomerRegister* customers, bookingRegister *bookings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    this->customers = customers;
    this->bookings = bookings;
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_addCustomer_clicked()
{
    newUser addUser(customers);
    addUser.setModal(true);
    addUser.exec();
}

void Login::on_login_clicked()
{
    loginUser login(customers);
    login.setModal(true);
    login.exec();
    hide();
}

void Login::on_endProgram_clicked()
{
    QFile customersFile("customersFile.txt");
    QFile bookingFile("bookingFile.txt");

    if(customersFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&customersFile);
        out << customers->getCounter() << "\n";
        for(int i=0; i < customers->getCounter(); i++)
        {
            int personNr = customers->getPersonNrAtIndex(i);
            std::string name = customers->getNameAtIndex(i);
            QString nameToFile = QString::fromStdString(name);
            std::string email = customers->getEmailAtIndex(i);
            QString emailToFile = QString::fromStdString(email);
            std::string address = customers->getAddressAtIndex(i);
            QString addressToFile = QString::fromStdString(address);
            std::string password = customers->getPasswordAtIndex(i);
            QString passwordToFile = QString::fromStdString(password);

            out << personNr << "\n";
            out << nameToFile << "\n";
            out << emailToFile << "\n";
            out << addressToFile << "\n";
            out << passwordToFile << "\n";
        }
    }
    if(bookingFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out2(&bookingFile);
        out2 << bookings->getCounter() << "\n";
        for (int i=0; i < bookings->getCounter(); i++)
        {
           int hairdresser = bookings->gethairdresserIDAtIndex(i);
           int treatmentIndex = bookings->getTreatmentIDAtIndex(i);
           int date = bookings->getDateAtIndex(i);
           int time = bookings->getTimeAtIndex(i);
           int personNr = bookings->getPersonNr(i);
           out2 << hairdresser << "\n";
           out2 << treatmentIndex << "\n";
           out2 << date << "\n";
           out2 << time << "\n";
           out2 << personNr << "\n";
        }
    }
    customersFile.flush();
    customersFile.close();
    bookingFile.flush();
    bookingFile.close();


    close();
    parentWidget()->close();
}
