#include "haircut.h"

Haircut::Haircut(int price, int timeOfTreatment, int treatmentID, std::string name, std::string typeOfHaircutName)
    : Treatment(price, timeOfTreatment, treatmentID, name)
{
    this->typeOfHaircutName= typeOfHaircutName;
}

Haircut::~Haircut()
{
    //Empty
}

std::string Haircut::ToStringSpecific() const
{
    std::string retString="";
    retString += "Typ av klippning: " + typeOfHaircutName;
    return retString;
}

