#include "newuser.h"
#include "ui_newuser.h"
#include <QString>
#include "mainwindow.h"
#include <QMessageBox>

newUser::newUser(CustomerRegister* customers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUser)
{

    ui->setupUi(this);
    this->setWindowTitle("Ny användare");
    this->customers = customers;
}

newUser::~newUser()
{
    delete ui;
}
void newUser::on_addCustomer_clicked()
{

}


void newUser::on_agree_clicked()
{
    QString name = ui->name->text();
    std::string name2 = name.toStdString();
    QString personNr = ui->personNr->text();
    int personNr2 = personNr.toInt();
    QString address = ui->address->text();
    std::string address2 = address.toStdString();
    QString email = ui->email->text();
    std::string email2 = email.toStdString();
    QString password = ui->password->text();
    std::string password2 = password.toStdString();
    int index = customers->findCustomer(personNr2);
    if(index == -1)
    {
        customers->addCustomer(personNr2, name2, email2, address2,password2);
        QMessageBox::information(this, "Ny användare", "Din användare är nu registrerad");
        hide();
    }
    else
    {
        QMessageBox::warning(this, "Ny användare", "Det finns redan en användare med det personnumret");
    }
}
