#include "customers.h"

Customers::Customers()
{

}

Customers::Customers(int personNr, QString name, QString email, QString address, QString password)
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

QString Customers::ToString() const
{
    QString ret;
    QString intConverter;

    ret += "Namn: " + name + "\n";
    ret += "Personnummer: " + intConverter.setNum(personNr) + "\n";
    ret += "Email: " + email + "\n";
    ret += "Adress: " + address + "\n";
    //Behövs lösenordet??
    return ret;
}

void Customers::setName(QString newName)
{
    name = newName;
}

void Customers::setEmail(QString NewEmail)
{
    email = NewEmail;
}

void Customers::setAddress(QString NewAddress)
{
    address = NewAddress;
}

void Customers::setPassword(QString NewPassword)
{
    password = NewPassword;
}

QString Customers::getName() const
{
    return name;
}

int Customers::getPersonNr() const
{
    return personNr;
}

