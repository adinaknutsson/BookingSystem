#include "hairdresserregister.h"

hairdresserRegister::hairdresserRegister()
{
    counter =0;
}


bool hairdresserRegister::addHairdresser(int hairdresserID, QString nameOfHairdresser)
{
   bool add = false;
   Hairdresser temp;
   temp = Hairdresser(int hairdresserID, QString nameOfHairdresser);
   hairdressers[counter] = temp;
   counter++;

   return add;
}
