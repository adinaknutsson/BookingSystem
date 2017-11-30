#include "customers.h"

Customers::Customers()
{

}

Customers::Customers(int personNr, std::string name, std::string email, std::string address, std::string password)
{
    this->personNr = personNr;
    this->name = name;
    this->email = email;
    this->address = address;
    this->password = password;
}

Customers::~Customers()
{
    //Empty
}

std::string Customers::ToString() const
{
    std::string ret;
    //std::string intConverter;

    ret += "Namn: " + name + "\n";
    ret += "Personnummer: " +std::to_string(personNr) + "\n";
    ret += "Email: " + email + "\n";
    ret += "Adress: " + address + "\n";
    //Behövs lösenordet??
    return ret;
}

void Customers::setName(std::string newName)
{
    name = newName;
}

void Customers::setEmail(std::string NewEmail)
{
    email = NewEmail;
}

void Customers::setAddress(std::string NewAddress)
{
    address = NewAddress;
}

void Customers::setPassword(std::string NewPassword)
{
    password = NewPassword;
}

std::string Customers::getName() const
{
    return name;
}

int Customers::getPersonNr() const
{
    return personNr;
}

