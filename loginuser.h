#ifndef LOGINUSER_H
#define LOGINUSER_H

#include <QDialog>

namespace Ui {
class loginUser;
}

class loginUser : public QDialog
{
    Q_OBJECT

public:
    explicit loginUser(QWidget *parent = 0);
    ~loginUser();

private slots:
    void on_login_clicked();

private:
    Ui::loginUser *ui;
};

#endif // LOGINUSER_H
