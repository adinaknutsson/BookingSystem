#include "booktime.h"
#include "ui_booktime.h"

bookTime::bookTime(bookingRegister* bookings,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::bookTime)
{
    ui->setupUi(this);
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
