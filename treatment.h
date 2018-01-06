#ifndef TREATMENT_H
#define TREATMENT_H
#include <string>

class Treatment
{
public:
    Treatment(int price, int ID, std::string name);
    virtual ~Treatment();

    std::string ToString();
    std::string getName();
    int getTreatmentID();
    int getPrice();
    virtual std::string getTypeNameOfTreatment() const =0;

private:
    int price;
    int treatmentID;
    std::string name;
    virtual std::string ToStringSpecific() const=0;
};

#endif // TREATMENT_H
