#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "loginuser.h"
#include "bookingregister.h"

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(CustomerRegister* customers, bookingRegister* bookings, QWidget *parent =0);
    ~Login();

private slots:
    void on_addCustomer_clicked();

    void on_login_clicked();

    void on_endProgram_clicked();

private:
    Ui::Login *ui;
    CustomerRegister* customers;
    bookingRegister* bookings;
};

#endif // LOGIN_H
