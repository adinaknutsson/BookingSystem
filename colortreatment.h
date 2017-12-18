#ifndef COLORTREATMENT_H
#define COLORTREATMENT_H
#include "treatment.h"
#include <string>


class ColorTreatment : public Treatment
{
public:
    ColorTreatment(int price, int treatmentID, std::string name, std::string color);
    ~ColorTreatment();
private:
    std::string color;
    std::string ToStringSpecific() const override;
};

#endif // COLORTREATMENT_H
