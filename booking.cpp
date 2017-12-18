#include "booking.h"

Booking::Booking()
{
    //behövs denna?
    hairdresserID =-1;
    treatmentID = -1;
    date =0;
    time =0;
    personNr =0;
    //Aktuella personens personnr ska läggas in.
}

Booking::Booking(int hairdresserID, int treatmentID, int dateOfTreatment, int time, int personNr)
{
    this->hairdresserID = hairdresserID;
    this->treatmentID = treatmentID;
    this->date = dateOfTreatment;
    this->time = time;
    this->personNr = personNr;
}

Booking::~Booking()
{
    //Empty
}

void Booking::setHairdresserID(int newID)
{
    hairdresserID = newID;
}

void Booking::setTreatmentID(int newID)
{
    treatmentID = newID;
}

void Booking::setDate(int newDate)
{
    date = newDate;
}

void Booking::setTime(int newTime)
{
    time = newTime;
}

int Booking::getHairdresserID() const
{
    return hairdresserID;
}

int Booking::getDate() const
{
    return date;
}

int Booking::getTime() const
{
    return time;
}

int Booking::getPersonNr() const
{
    return personNr;
}

int Booking::getTreatmentID() const
{
    return treatmentID;
}

std::string Booking::ToString()
{
    std::string ret;
    ret += "Datum: " + std::to_string(date) + "\n";
    ret += "Tid: " + std::to_string(time) + "\n";
    return ret;
}
