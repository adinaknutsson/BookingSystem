#include "login.h"
#include "ui_login.h"
#include "newuser.h"
#include "loginuser.h"
#include "mainwindow.h"

Login::Login(CustomerRegister* customers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    this->customers = customers;
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
}
