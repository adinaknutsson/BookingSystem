#include "login.h"
#include "ui_login.h"
#include "newuser.h"
#include "loginuser.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_addCustomer_clicked()
{
    newUser addUser;
    addUser.setModal(true);
    addUser.exec();
}

void Login::on_login_clicked()
{
    loginUser login;
    login.setModal(true);
    login.exec();
}
