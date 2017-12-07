#include "login.h"
#include "ui_login.h"
#include "newuser.h"

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

void Login::on_pushButton_2_clicked()
{
    newUser *user = new newUser;
    user->exec();
}
