#ifndef BOOKING_H
#define BOOKING_H
#include <string>

class Booking
{
public:
    Booking();
    Booking(int hairdresserID, int treatmentID, int dateOfTreatment, int time, int personNr);
    ~Booking();
    void setHairdresserID(int newID);
    void setTreatmentID(int newID);
    void setDate(int newDate);
    void setTime(int newTime);

    int getHairdresserID() const;
    int getDate() const;
    int getTime() const;
    int getPersonNr() const;
    int getTreatmentID() const;

    std::string ToString();

private:
    int hairdresserID;
    int treatmentID;
    int date;
    int time;
    int personNr;
};

#endif // BOOKING_H
