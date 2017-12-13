#ifndef HAIRDRESSERREGISTER_H
#define HAIRDRESSERREGISTER_H
#include "hairdresser.h"

class hairdresserRegister
{
public:
    hairdresserRegister();
    ~hairdresserRegister();
    bool addHairdresser(int hairdresserID, std::string nameOfHairdresser);
private:
   Hairdresser* hairdressers[5];
   int counter;
   int capacity =5;

};

#endif // HAIRDRESSERREGISTER_H
