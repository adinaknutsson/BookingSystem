#ifndef BOOKINGREGISTER_H
#define BOOKINGREGISTER_H
#include "booking.h"


class bookingRegister
{
public:
    bookingRegister();
    bool addBooking(int hairdresserID, int treatmentID, int date, int time, int personNr);
    bool checkTime(int hairdresserID, int date, int time);
    std::string toString(int personNr);
    //int findBooking(int personNr);

    //Get funktioner för allt?

private:
    Booking** bookings;
    int counter;
    int capacity;
    void Expand();
};

#endif // BOOKINGREGISTER_H
