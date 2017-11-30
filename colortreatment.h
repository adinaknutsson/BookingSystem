#ifndef COLORTREATMENT_H
#define COLORTREATMENT_H
#include "treatment.h"
#include <string>


class ColorTreatment : public Treatment
{
public:
    ColorTreatment(int price, int timeOfTreatment, int treatmentID, std::string name, std::string color, int colortreatmentID);
    ~ColorTreatment();
private:
    std::string color;
    int colorTreatmentID;
    std::string ToStringSpecific() const override;
};

#endif // COLORTREATMENT_H
