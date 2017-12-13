#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), customers()
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCustomer(int personNr, std::string name, std::string email, std::string address, std::string password)
{
    customers.addCustomer(personNr, name, email, address, password);
}

