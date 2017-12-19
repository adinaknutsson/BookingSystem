#ifndef CHANGEINFORMATION_H
#define CHANGEINFORMATION_H

#include <QDialog>
#include "customerregister.h"

namespace Ui {
class changeInformation;
}

class changeInformation : public QDialog
{
    Q_OBJECT

public:
    explicit changeInformation(CustomerRegister* customers, int personNractiv, QWidget *parent = 0);
    ~changeInformation();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::changeInformation *ui;
    CustomerRegister* customers;
    int activ;
};

#endif // CHANGEINFORMATION_H
