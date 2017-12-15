#ifndef LOGINUSER_H
#define LOGINUSER_H

#include <QDialog>
#include "customerregister.h"

namespace Ui {
class loginUser;
}

class loginUser : public QDialog
{
    Q_OBJECT

public:
    explicit loginUser(CustomerRegister* customers, QWidget *parent = 0);
    ~loginUser();

private slots:
    void on_login_clicked();

private:
    Ui::loginUser *ui;
    CustomerRegister* customers;
};

#endif // LOGINUSER_H
