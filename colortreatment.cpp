#include "colortreatment.h"

ColorTreatment::ColorTreatment(int price, int treatmentID, std::string name, std::string color)
    : Treatment(price, treatmentID, name)
{
    this->color = color;
}

ColorTreatment::~ColorTreatment()
{
    //Empty
}

std::string ColorTreatment::ToStringSpecific() const
{
    std::string retString="";
    retString += "Färg: " + color;
    return retString;
}
/*
enum class coloring
{
    hairstrands, full
}
*/
