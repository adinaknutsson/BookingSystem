#include "newuser.h"
#include "ui_newuser.h"
#include <QString>
#include "mainwindow.h"

newUser::newUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newUser)
{
    ui->setupUi(this);
}

newUser::~newUser()
{
    delete ui;
}
void newUser::on_addCustomer_clicked()
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

    w.addCustomer(personNr2, name2, email2, address2, password2);
}

