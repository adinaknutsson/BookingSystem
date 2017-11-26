#include "hairdresser.h"

Hairdresser::Hairdresser(int hairdresserID, QString hairdresserName)
{
    this->name = hairdresserName;
    this->ID = hairdresserID;
}
Hairdresser::~Hairdresser()
{
    //Empty
}

QString Hairdresser::getName()
{
   return name;
}
