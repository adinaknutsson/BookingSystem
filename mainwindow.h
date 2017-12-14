#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "customerregister.h"
#include "login.h"
#include "bookingregister.h"
#include "booktime.h"
#include "hairdresserregister.h"

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
   // void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

    void on_pushButton_clicked();

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
