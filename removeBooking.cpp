#include "removeBooking.h"
#include "ui_removeBooking.h"
#include <QMessageBox>

removeBooking::removeBooking(bookingRegister *bookings, int personNr,  QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removeBooking)
{
    ui->setupUi(this);
    this->setWindowTitle("Ta bort bokning");
    this->bookings = bookings;
    activUser = personNr;
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
    int index = bookings->bookingToRemove(dateToRemove, timeToRemove, activUser);
    if (index == -1)
    {
        QMessageBox::warning(this, "Ta bort bokning", "Det finns ingen bokning med detta datum och tid");
    }
    else
    {
        bookings->removeBooking(index);
        QMessageBox::information(this, "Ta bort bokning","Din bokning har tagits bort");
    };
    hide();
}

void removeBooking::on_pushButton_clicked()
{
    close();
    parentWidget()->show();
}
