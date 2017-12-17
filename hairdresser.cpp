#include "hairdresser.h"

Hairdresser::Hairdresser()
{

}
Hairdresser::Hairdresser(int hairdresserID, std::string hairdresserName)
{
    this->name = hairdresserName;
    this->ID = hairdresserID;
}
Hairdresser::~Hairdresser()
{
    //Empty
}

std::string Hairdresser::getName()
{
    return name;
}

bool Hairdresser::operator==(Hairdresser &other)
{
    bool same = false;
    if (this->name == other.name && this->ID == other.ID)
    {
        same = true;
    }
    return same;
}
