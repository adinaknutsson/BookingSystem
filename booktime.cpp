#include "booktime.h"
#include "ui_booktime.h"
#include "QMessageBox"

bookTime::bookTime(bookingRegister* bookings, hairdresserRegister* hairdressers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookTime)
{
    ui->setupUi(this);
    this->hairdressers = hairdressers;
    this->bookings = bookings;
    for(int i=0; i <hairdressers->getNrOfHairdressers(); i++)
    {
        std::string temp = hairdressers->getNameToComboBox(i);
        QString hairdresser = QString::fromStdString(temp);
        ui->comboBox->addItem(hairdresser);
    }
}

bookTime::~bookTime()
{
    delete ui;
}

void bookTime::on_pushButton_clicked()
{
    QString hairdresser = ui->comboBox->currentText();
    QMessageBox::information(this, "title", hairdresser);
    QString dateToBook = ui->date->text();
    int dateToBook1 = dateToBook.toInt();
    QString timeToBook = ui->time_2->text();
    int timeToBook1 = timeToBook.toInt();
    int hairdresserIndex = ui->comboBox->currentIndex();
    bookings->addBooking(hairdresserIndex,01, dateToBook1, timeToBook1,1995);
    //01 och 1995 ska ändras till riktiga värden!!
    hide();
    parentWidget()->show();

}

void bookTime::on_time_clicked()
{
    QString date = ui->date->text();
    int date1 = date.toInt();
    int hairdresserIndex = ui->comboBox->currentIndex();
    std::string freeTimes = bookings->freeTimesToString(date1,hairdresserIndex);
    QString time = QString::fromStdString(freeTimes);
    ui->textBrowser->setText(time);

}
