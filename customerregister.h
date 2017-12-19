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
    bool login(int personNr, std::string password);
    void setActivUser(int personNr);
    int getActiveUser() const;
private:
    Customers** CustomersArray;
    int counter;
    int capacity;
    int activUserPersonNr;
    void Expand();
};

#endif // CUSTOMERREGISTER_H
