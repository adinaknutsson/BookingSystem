#include "bookingregister.h"

bookingRegister::bookingRegister()
{
    capacity =5;
    counter =0;
    bookings = new Booking*[capacity];
}

bookingRegister::~bookingRegister()
{
    for(int i=0; i < counter; i++)
    {
        delete bookings[i];
    }
    delete[] bookings;
}

bool bookingRegister::addBooking(int hairdresserID, int treatmentID, int date, int time, int personNr)
{
    bool add=false;
    if (capacity == counter)
        Expand();
    add = checkTime(hairdresserID, date, time);
    if (add == false)
    {
        Booking toAdd(hairdresserID,treatmentID, date, time, personNr);
        bookings[counter]= new Booking(toAdd);
        counter++;
        add = true;
    }
    return add;
}

bool bookingRegister::checkTime(int hairdresserID, int date, int time)
{
    bool bookedTime = false;
    for (int i =0; i < counter; i++)
    {
        if (hairdresserID == bookings[i]->getHairdresserID()
                && date == bookings[i]->getDate() && time == bookings[i]->getTime())
        {
            bookedTime = true;
            i = counter;
        }
    }
    return bookedTime;
}

std::string bookingRegister::freeTimesToString(int date, int hairdresserID)
{
    std::string ret ="";
    if (counter ==0)
    {
        for (int i=900; i < 1800; i =i +100)
        {
                 ret = ret + std::to_string(i) + "\n";
        }
    }
    else
    {
        int arr[9] ={};
        for (int i=0; i < counter; i++)
        {
            for (int n=900; n < 1800; n =n +100)
            {
                int index = (n/100 ) -9;
                if (arr[index] != -1)
                {
                    if (date == bookings[i]->getDate() && hairdresserID == bookings[i]->getHairdresserID() && n == bookings[i]->getTime())
                    {
                        arr[index] = -1;
                    }
                    else
                    {
                        arr[index]=n;
                    }
                }
            }

        }
        for(int i=0; i < 9; i++)
        {
            if (arr[i] == -1)
            {

            }
            else
            {
                ret = ret + std::to_string(arr[i]) + "\n";
            }
        }
    }
    return ret;
}

std::string bookingRegister::toString(int index)
{
    return bookings[index]->ToString();
}

int bookingRegister::bookingToRemove(int date, int time)
{
    int index = -1;
    for (int i=0; i < counter; i++)
    {
        if (date == bookings[i]->getDate() && time == bookings[i]->getTime())
        {
            index =i;
            i = counter;
        }
    }
    return index;
}

void bookingRegister::removeBooking(int index)
{
    if (counter ==1)
        {
           delete bookings[index];
           counter--;
        }
    else
        {
            bookings[index] = bookings[counter];
            delete bookings[counter];
            counter--;
        }
}

int bookingRegister::getCounter()
{
    return counter;
}

int bookingRegister::gethairdresserIDAtIndex(int index)
{
    return bookings[index]->getHairdresserID();
}

int bookingRegister::getTreatmentIDAtIndex(int index)
{
   return bookings[index]->getTreatmentID();
}

int bookingRegister::getPersonNr(int index)
{
    return bookings[index]->getPersonNr();
}

int bookingRegister::getDateAtIndex(int index) const
{
    return bookings[index]->getDate();
}

int bookingRegister::getTimeAtIndex(int index) const
{
    return bookings[index]->getTime();
}

void bookingRegister::Expand()
{
    capacity = capacity*2;
    Booking** temp = new Booking*[capacity];
    for(int i=0; i < counter; i++)
    {
        temp[i] = bookings[i];
    }
    delete[] bookings;
    bookings = temp;
}
