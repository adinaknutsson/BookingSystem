#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include <string>


class Customers
{
public:
    Customers();
    Customers(int personNr, std::string name, std::string email, std::string address, std::string password);
    ~Customers();
    std::string ToString() const;
    void setName(std::string NewName);
    void setEmail(std::string NewEmail);
    void setAddress(std::string NewAddress);
    void setPassword(std::string NewPassword);

    std::string getName() const;
    int getPersonNr() const;
    std::string getPassword() const;
    std::string getEmail() const;
    std::string getAddress() const;
    //Fler getters efter behov...
private:
    int personNr;
    std::string name;
    std::string email;
    std::string address;
    std::string password;
};

#endif // CUSTOMERS_H
