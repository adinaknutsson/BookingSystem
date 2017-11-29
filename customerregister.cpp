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

bool CustomerRegister::addCustomer(int personNr, QString name, QString email, QString address, QString password)
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
        CustomersArray[counter] = &toAdd;
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

QString CustomerRegister::ToString() const
{
    QString ret ="";
    int index;
    //SKA INTE VARA COUNTER DÄR!!
    //Får kolla vem som är inloggad och leta upp index.
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

