#include "haircut.h"

Haircut::Haircut(int price, int timeOfTreatment, int treatmentID, std::string name, std::string typeOfHaircutName, int haircutType)
    : Treatment(price, timeOfTreatment, treatmentID, name)
{
    this->haircutType = haircutType;
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
/*
enum class cut
{
    longHair, shortHair, menCut
}
*/
