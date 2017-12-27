#ifndef BOOKTIME_H
#define BOOKTIME_H

#include <QDialog>
#include "bookingregister.h"
#include "hairdresserregister.h"
#include "treatment.h"

namespace Ui {
class bookTime;
}

class bookTime : public QDialog
{
    Q_OBJECT

public:
    explicit bookTime(bookingRegister* bookings, hairdresserRegister* hairdressers, Treatment** treatments, int activUser, QWidget *parent = 0);
    ~bookTime();

private slots:

    void on_pushButton_clicked();

    void on_time_clicked();

    void on_end_clicked();

private:
    Ui::bookTime *ui;
    bookingRegister* bookings;
    hairdresserRegister* hairdressers;
    Treatment** treatments;
    int activ;
};

#endif // BOOKTIME_H
