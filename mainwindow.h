#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "login.h"
#include "customerregister.h"
#include "bookingregister.h"
#include "booktime.h"
#include "hairdresserregister.h"
#include "haircut.h"
#include "colortreatment.h"
#include "changeinformation.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void addCustomer(int personNr, std::string name, std::string email, std::string address, std::string password);
    void setActiveCustomer(int personNr);
private slots:
    void on_bookTime_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Treatment** treatments;
    int counterTreatments;
    int capacityTreatments =9;
    CustomerRegister customers;
    bookingRegister bookings;
    hairdresserRegister hairdressers;

    int personNrActive;

    //Fönster
    Login* loginWindow;
    bookTime* bookWindow;
    changeInformation* informationWindow;

};

#endif // MAINWINDOW_H
