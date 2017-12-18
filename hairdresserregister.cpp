#include "hairdresserregister.h"

hairdresserRegister::hairdresserRegister()
{
    counter =0;
}

hairdresserRegister::~hairdresserRegister()
{
    //Empty
}
bool hairdresserRegister::addHairdresser(int hairdresserID, std::string nameOfHairdresser)
{
bool add = false;
Hairdresser *toAdd = new Hairdresser(hairdresserID, nameOfHairdresser);
hairdressers[counter] = toAdd;
counter++;
/*
if (counter == capacity)
{
}
else
{
   Hairdresser *toAdd = new Hairdresser(hairdresserID, nameOfHairdresser);

   if(counter == 0)
   {
       hairdressers[counter] = toAdd;
       counter++;
       add = true;
   }
   else
   {
   for (int i=0; i < counter; i++)
   {
       if (*toAdd == *hairdressers[i])
       {}
       else
       {
           hairdressers[counter] = toAdd;
           counter++;
           add = true;
       }
   }

   }
}
*/
return add;
}

int hairdresserRegister::getNrOfHairdressers() const
{
    return counter;
}

std::string hairdresserRegister::getNameToComboBox(int index) const
{
    return hairdressers[index]->getName();
}

int hairdresserRegister::gethairdresserID(int index)
{
    return hairdressers[index]->getID();
}


