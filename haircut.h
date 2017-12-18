#ifndef HAIRCUT_H
#define HAIRCUT_H
#include "treatment.h"

class Haircut : public Treatment
{
public:
    Haircut(int price, int treatmentID, std::string name, std::string typeOfHaircutName);
    ~Haircut();
private:
    std::string typeOfHaircutName;
    std::string ToStringSpecific() const override;

};

#endif // HAIRCUT_H
