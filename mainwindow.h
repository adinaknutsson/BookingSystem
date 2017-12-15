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

private slots:
    void on_bookTime_clicked();

private:
    Ui::MainWindow *ui;
    CustomerRegister customers;
    bookingRegister bookings;
    hairdresserRegister hairdressers;

    //Fönster
    Login* loginWindow;
    bookTime* bookWindow;
};

#endif // MAINWINDOW_H
