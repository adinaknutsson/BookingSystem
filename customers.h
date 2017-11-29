#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <QString>


class Customers
{
public:
    Customers();
    Customers(int personNr, QString name, QString email, QString address, QString password);
    ~Customers();
    QString ToString() const;
    void setName(QString NewName);
    void setEmail(QString NewEmail);
    void setAddress(QString NewAddress);
    void setPassword(QString NewPassword);

    QString getName() const;
    int getPersonNr() const;
    //Fler getters efter behov...
private:
    int personNr;
    QString name;
    QString email;
    QString address;
    QString password;
};

#endif // CUSTOMERS_H
