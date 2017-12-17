#include "booktime.h"
#include "ui_booktime.h"

bookTime::bookTime(bookingRegister* bookings, hairdresserRegister* hairdressers, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookTime)
{
    ui->setupUi(this);
    this->hairdressers = hairdressers;
    for(int i=0; i <hairdressers->getNrOfHairdressers(); i++)
    {
        std::string temp = hairdressers->getNameToComboBox(i);
        QString hairdresser = QString::fromStdString(temp);
        ui->comboBox->addItem(hairdresser);
    }
ui->comboBox->addItem("Mark");

}

bookTime::~bookTime()
{
    delete ui;
}

void bookTime::on_comboBox_activated(const QString &arg1)
{

}

void bookTime::on_dateEdit_editingFinished()
{

}
