#include "hairdresserregister.h"

hairdresserRegister::hairdresserRegister()
{
    counter =0;
}
bool hairdresserRegister::addHairdresser(int hairdresserID, QString nameOfHairdresser)
{
bool add = false;
if (counter == capacity)
{
}
else
{
   Hairdresser toAdd(hairdresserID, nameOfHairdresser);
   for (int i=0; i < counter; i++)
   {
       if (toAdd == *hairdressers[i])
       {}
       else
       {
           hairdressers[counter] = &toAdd;
           counter++;
       }
   }
}
   return add;
}
