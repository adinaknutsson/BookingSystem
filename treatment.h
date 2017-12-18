#ifndef TREATMENT_H
#define TREATMENT_H
#include <QString>

class Treatment
{
public:
    Treatment(int price, int ID, std::string name);
    virtual ~Treatment();

    std::string ToString();

private:
    int price;
    //int timeOfTreatment;
    int treatmentID;
    std::string name;
    virtual std::string ToStringSpecific() const=0;
};

#endif // TREATMENT_H
