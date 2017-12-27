#include "removeBooking.h"
#include "ui_removeBooking.h"
#include <QMessageBox>

removeBooking::removeBooking(bookingRegister *bookings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeBooking)
{
    ui->setupUi(this);
    this->bookings = bookings;
}

removeBooking::~removeBooking()
{
    delete ui;
}

void removeBooking::on_Confirm_clicked()
{
    QString date = ui->date->text();
    QString time = ui->time->text();
    int dateToRemove = date.toInt();
    int timeToRemove = time.toInt();
    int index = bookings->bookingToRemove(dateToRemove, timeToRemove);
    QString index1 = QString::number(index);
    if (index == -1)
    {
        QMessageBox::warning(this, "Ta bort bokning", "Det finns ingen bokning med detta datum och tid");
    }
    else
    {
        bookings->removeBooking(index);
        QMessageBox::information(this, "Ta bort bokning","Din bokning har tagits bort");
    };
}

void removeBooking::on_pushButton_clicked()
{
    close();
    parentWidget()->show();
}
