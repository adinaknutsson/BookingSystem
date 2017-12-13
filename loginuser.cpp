#include "loginuser.h"
#include "ui_loginuser.h"
#include <QMessageBox>

loginUser::loginUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginUser)
{
    ui->setupUi(this);
}

loginUser::~loginUser()
{
    delete ui;
}

void loginUser::on_login_clicked()
{
    QString personNr = ui->personNr->text();
    QString password = ui->password->text();

    //Kontroll om användaren finns, måste komma åt customerRegister.
    //for ( int i=0;  )
    //if (username ==  )
    QMessageBox::information(this, "Login", "Username and password is correct");
    //else inloggningen fungerade ej!...

}
