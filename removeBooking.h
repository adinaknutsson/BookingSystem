#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "bookingregister.h"

namespace Ui {
class removeBooking;
}

class removeBooking : public QDialog
{
    Q_OBJECT

public:
    explicit removeBooking(bookingRegister* bookings, QWidget *parent = 0);
    ~removeBooking();

private slots:
    void on_Confirm_clicked();

    void on_pushButton_clicked();

private:
    Ui::removeBooking *ui;
    bookingRegister* bookings;
};

#endif // DIALOG_H
