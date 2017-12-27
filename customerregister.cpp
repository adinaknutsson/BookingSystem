#include "customerregister.h"

CustomerRegister::CustomerRegister()
{
    counter =0;
    capacity = 5;
    CustomersArray = new Customers*[capacity];
}

CustomerRegister::~CustomerRegister()
{
  for (int i=0; i < counter; i++)
  {
      delete CustomersArray[i];
  }
  delete[] CustomersArray;
}

bool CustomerRegister::addCustomer(int personNr, std::string name, std::string email, std::string address, std::string password)
{
    bool added = false;
    int index;
    if (counter == capacity)
    {
        Expand();
    }
    index = findCustomer(personNr);
    if (index == -1)
    {
        Customers toAdd(personNr, name, email, address, password);
        CustomersArray[counter] =  new Customers(toAdd);
        counter++;
        added = true;
    }
    return added;
}

int CustomerRegister::findCustomer(int personNr)
{
    int index =-1;
    if( counter !=0)
    {
        for(int i =0; i < counter; i++)
        {
            if (personNr == CustomersArray[i]->getPersonNr())
            {
               index = i;
               i = counter;
            }
        }
    }
    return index;
}

std::string CustomerRegister::ToString(int personNr)
{
    //Inloggade persons personnummer ska kunna hämtas och sedan
    //skickas vidare
    std::string ret ="";
    int index;
    index = findCustomer(personNr);
    if (index !=-1)
    {
        ret += CustomersArray[index]->ToString();
    }

    return ret;
}

std::string CustomerRegister::getName(int personNr)
{
    int index = findCustomer(personNr);
    std::string ret;
    if (index !=-1)
    {
        ret += "Namn: " + CustomersArray[index]->getName() + "\n";
    }
    return ret;
}

bool CustomerRegister::login(int personNr, std::string password)
{
    bool existingCustomer = false;
    for (int i=0; i < counter; i++)
    {
        if(personNr == CustomersArray[i]->getPersonNr() && password == CustomersArray[i]->getPassword())
        {
            existingCustomer = true;
            i= counter;
        }
    }
    return existingCustomer;
}

void CustomerRegister::setActivUser(int personNr)
{
    activUserPersonNr = personNr;
}

int CustomerRegister::getActiveUser() const
{
    return activUserPersonNr;
}

int CustomerRegister::getCounter() const
{
    return counter;
}

std::string CustomerRegister::getNameAtIndex(int index) const
{
    return CustomersArray[index]->getName();
}

int CustomerRegister::getPersonNrAtIndex(int index) const
{
    return CustomersArray[index]->getPersonNr();
}

std::string CustomerRegister::getPasswordAtIndex(int index) const
{
    return CustomersArray[index]->getPassword();
}

std::string CustomerRegister::getEmailAtIndex(int index) const
{
    return CustomersArray[index]->getEmail();
}

std::string CustomerRegister::getAddressAtIndex(int index) const
{
    return CustomersArray[index]->getAddress();
}

void CustomerRegister::setName(std::string newName)
{
    int index = findCustomer(activUserPersonNr);
    if (index != -1)
    {
        CustomersArray[index]->setName(newName);
    }
}

void CustomerRegister::setEmail(std::string newEmail)
{
    int index = findCustomer(activUserPersonNr);
    if (index != -1)
    {
        CustomersArray[index]->setEmail(newEmail);
    }
}

void CustomerRegister::setAddress(std::string newAddress)
{
    int index = findCustomer(activUserPersonNr);
    if (index != -1)
    {
        CustomersArray[index]->setAddress(newAddress);
    }
}

void CustomerRegister::setPassword(std::string newPassword)
{
    int index = findCustomer(activUserPersonNr);
    if (index != -1)
    {
        CustomersArray[index]->setPassword(newPassword);
    }
}

void CustomerRegister::Expand()
{
    capacity = capacity *2;
    Customers** temp = new Customers*[capacity];
    for (int i=0; i < counter; i++)
    {
        temp[i]=CustomersArray[i];
    }
    delete[] CustomersArray;
    CustomersArray = temp;
}

