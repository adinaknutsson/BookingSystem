#include "changeinformation.h"
#include "ui_changeinformation.h"
#include <QMessageBox>

changeInformation::changeInformation(CustomerRegister *customers, int personNractiv, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeInformation)
{
    ui->setupUi(this);
    this->setWindowTitle("Ändra användaruppgifter");
    this->customers = customers;
    activ = customers->getActiveUser();
}

changeInformation::~changeInformation()
{
    delete ui;
}

void changeInformation::on_pushButton_clicked()
{
    int index = customers->findCustomer(activ);
    if(index != -1)
    {
        if (ui->name->text().isEmpty() == false)
        {
            QString name = ui->name->text();
            std::string name2 = name.toStdString();
            customers[index].setName(name2);
        }
        if(ui->address->text().isEmpty() == false)
        {
            QString address = ui->address->text();
            std::string address2 = address.toStdString();
            customers[index].setAddress(address2);
        }
        if (ui->email->text().isEmpty() == false)
        {
            QString email = ui->email->text();
            std::string email2 = email.toStdString();
            customers[index].setEmail(email2);
        }
        if(ui->password->text().isEmpty() == false)
        {
            QString password = ui->password->text();
            std::string password2 = password.toStdString();
            customers[index].setPassword(password2);
        }
        QMessageBox::information(this, "Ändrade uppgifter", "Dina uppgifter har ändrats.");
    }
}

void changeInformation::on_pushButton_2_clicked()
{
    parentWidget()->show();
    close();
}
