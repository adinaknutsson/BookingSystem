#include "treatment.h"

Treatment::Treatment(int price, int time, int ID, std::string name)
{
    this->price = price;
    timeOfTreatment = time;
    treatmentID = ID;
    this->name = name;
}

Treatment::~Treatment()
{

}

std::string Treatment::ToString()
{
    std::string retString = "";
    //QString intConverter;
    retString += ToStringSpecific() + "\n";
    retString += "Pris: " + std::to_string(price) + "\n";
    retString += "Tidåtgång: " + std::to_string(timeOfTreatment) + "\n";
    return retString;
}
