#include "booktime.h"
#include "ui_booktime.h"
#include "QMessageBox"
#include "haircut.h"
#include "colortreatment.h"

bookTime::bookTime(bookingRegister* bookings, hairdresserRegister* hairdressers, Treatment** treatments, int activUser,  QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookTime)
{
    ui->setupUi(this);
    this->hairdressers = hairdressers;
    this->bookings = bookings;
    this->treatments = treatments;
    activ = activUser;
    for(int i=0; i <hairdressers->getNrOfHairdressers(); i++)
    {
        std::string temp = hairdressers->getNameToComboBox(i);
        QString hairdresser = QString::fromStdString(temp);
        ui->comboBox->addItem(hairdresser);
    }
    for(int i=0; i < 9; i++)
    {
        std::string nameTemp = treatments[i]->getName();
        QString name = QString::fromStdString(nameTemp);
        std::string type = treatments[i]->getTypeNameOfTreatment();
        QString type1 = QString::fromStdString(type);

        ui->comboBox_2->addItem(name + " , " + type1);
    }
}

bookTime::~bookTime()
{
    delete ui;
}

void bookTime::on_pushButton_clicked()
{
    QString hairdresser = ui->comboBox->currentText();
    QString dateToBook = ui->date->text();
    int dateToBook1 = dateToBook.toInt();
    QString timeToBook = ui->time_2->text();
    int timeToBook1 = timeToBook.toInt();
    int hairdresserIndex = ui->comboBox->currentIndex();
    int treatmentIndex = ui->comboBox_2->currentIndex() +1;

    bookings->addBooking(hairdresserIndex,treatmentIndex, dateToBook1, timeToBook1, activ);
    //1995 ska ändras till riktiga värden!!
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
