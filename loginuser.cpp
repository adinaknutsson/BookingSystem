#include "loginuser.h"
#include "ui_loginuser.h"
#include <QMessageBox>
#include "mainwindow.h"

loginUser::loginUser(CustomerRegister* customers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginUser)
{
    ui->setupUi(this);
    this->setWindowTitle("Logga in");
    this->customers = customers;
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowTitleHint);
}

loginUser::~loginUser()
{
    delete ui;
}

void loginUser::on_login_clicked()
{
    QString personNr = ui->personNr->text();
    int personNr2 = personNr.toInt();
    QString password = ui->password_2->text();
    std::string password2 = password.toStdString();

    if (customers->login(personNr2, password2) == true)
    {
        hide();
        customers->setActivUser(personNr2);

    }
    else
    {
        QMessageBox::warning(this, "Inloggning", "Fel användarnamn eller lösenord");
    }

}
