#include "loginuser.h"
#include "ui_loginuser.h"
#include <QMessageBox>

loginUser::loginUser(CustomerRegister* customers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginUser)
{
    ui->setupUi(this);
    this->customers = customers;
}

loginUser::~loginUser()
{
    delete ui;
}

void loginUser::on_login_clicked()
{
    QString personNr = ui->personNr->text();
    int personNr2 = personNr.toInt();
    QString password = ui->password->text();
    std::string password2 = password.toStdString();
    if (customers->login(personNr2, password2))
    {
         //QMessageBox::information(this, "Login", "Username and password is correct");
        hide();
        parentWidget()->show();
    }
    else
    {
        QMessageBox::warning(this, "Inloggning", "Fel användarnamn eller lösenord");
    }

    //else inloggningen fungerade ej!...

}
