#include "colortreatment.h"

ColorTreatment::ColorTreatment(int price, int timeOfTreatment, int treatmentID, std::string name, std::string color, int colortreatmentID)
    : Treatment(price, timeOfTreatment, treatmentID, name)
{
    this->color = color;
    this->colorTreatmentID = colorTreatmentID;
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
