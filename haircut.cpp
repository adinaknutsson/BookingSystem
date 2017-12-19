#include "haircut.h"

Haircut::Haircut(int price, int treatmentID, std::string name, std::string typeOfHaircutName)
    : Treatment(price, treatmentID, name)
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

std::string Haircut::getTypeNameOfTreatment() const
{
    return typeOfHaircutName;
}

