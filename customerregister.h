#ifndef CUSTOMERREGISTER_H
#define CUSTOMERREGISTER_H
#include "customers.h"

class CustomerRegister
{
public:
    CustomerRegister();
    ~CustomerRegister();
    bool addCustomer(int personNr, std::string name, std::string email, std::string address, std::string password);
    int findCustomer(int personNr);

    std::string ToString(int personNr);
    std::string getName(int personNr);
private:
    Customers** CustomersArray;
    int counter;
    int capacity;
    void Expand();
};

#endif // CUSTOMERREGISTER_H
