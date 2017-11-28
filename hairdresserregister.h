#ifndef HAIRDRESSERREGISTER_H
#define HAIRDRESSERREGISTER_H
#include "hairdresser.h"

class hairdresserRegister
{
public:
    hairdresserRegister()
    bool addHairdresser(int hairdresserID, QString nameOfHairdresser);
private:
   Hairdresser* hairdressers[7];
   int counter;
   //Ska ju inte lägga till några frisöer,
   //Kan vara statisk?

};

#endif // HAIRDRESSERREGISTER_H
