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
    for(int i =0; i < counter; i++)
    {
        if (personNr == CustomersArray[i]->getPersonNr())
        {
           index = i;
           i = counter;
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

