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
    int getCounter() const;

    std::string getNameAtIndex(int index) const;
    int getPersonNrAtIndex(int index) const;
    std::string getPasswordAtIndex(int index) const;
    std::string getEmailAtIndex(int index) const;
    std::string getAddressAtIndex(int index) const;

    void setName(std::string newName);
    void setEmail(std::string newEmail);
    void setAddress(std::string newAddress);
    void setPassword(std::string newPassword);
private:
    Customers** CustomersArray;
    int counter;
    int capacity;
    int activUserPersonNr;
    void Expand();
};

#endif // CUSTOMERREGISTER_H
