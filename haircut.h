#ifndef HAIRCUT_H
#define HAIRCUT_H
#include "treatment.h"

class Haircut : public Treatment
{
public:
    Haircut(int price, int timeOfTreatment, int treatmentID, std::string name, std::string typeOfHaircutName, int haircutType);
    ~Haircut();
private:
    std::string typeOfHaircutName;
    int haircutType;
    std::string ToStringSpecific() const override;

};

#endif // HAIRCUT_H
