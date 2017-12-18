#ifndef BOOKINGREGISTER_H
#define BOOKINGREGISTER_H
#include "booking.h"


class bookingRegister
{
public:
    bookingRegister();
    ~bookingRegister();
    bool addBooking(int hairdresserID, int treatmentID, int date, int time, int personNr);
    bool checkTime(int hairdresserID, int date, int time);
    std::string freeTimesToString(int date, int hairdresserID);
    std::string toString(int index);

    //Get funktioner för allt?
    int getCounter();
    int gethairdresserIDAtIndex(int index);
    int getTreatmentIDAtIndex(int index);
    int getPersonNr(int index);

private:
    Booking** bookings;
    int counter;
    int capacity;
    void Expand();
};

#endif // BOOKINGREGISTER_H
