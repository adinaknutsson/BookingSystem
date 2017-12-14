#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class newUser;
}

class newUser : public QDialog
{
    Q_OBJECT

public:
    explicit newUser(CustomerRegister* customers, QWidget *parent = 0);
    ~newUser();

private slots:
    void on_addCustomer_clicked();

    void on_agree_clicked();

private:
    Ui::newUser *ui;
    CustomerRegister* customers;
};

#endif // NEWUSER_H
