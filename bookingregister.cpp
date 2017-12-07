#include "bookingregister.h"

bookingRegister::bookingRegister()
{
    capacity =5;
    counter =0;
    bookings = new Booking*[capacity];
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

std::string bookingRegister::toString(int personNr)
{
    //Skriver ut alla bokningar för en person
    std::string ret;
    for(int i=0; i < counter; i++)
    {
        if (bookings[i]->getPersonNr() == personNr)
        {
            ret += bookings[i]->ToString();
        }
    }
    return ret;
}


/* Används ej!!
int bookingRegister::findBooking(int personNr)
{
    int index =-1;
    for (int i=0; i < counter; i++)
    {
        if (bookings[i]->getPersonNr() == personNr)
        {
            index = i;
            i = counter;
        }
    }
    return index;
}
*/
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
