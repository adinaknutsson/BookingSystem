#ifndef CUSTOMERREGISTER_H
#define CUSTOMERREGISTER_H
#include "customers.h"

class CustomerRegister
{
public:
    CustomerRegister();
    ~CustomerRegister();
    bool addCustomer(int personNr, QString name, QString email, QString address, QString password);
    int findCustomer(int personNr);
    //Kanske göra en sökfunktion??
    QString ToString() const;
private:
    Customers** CustomersArray;
    int counter;
    int capacity;
    void Expand();
};

#endif // CUSTOMERREGISTER_H
