#ifndef HAIRDRESSER_H
#define HAIRDRESSER_H
#include <string>
class Hairdresser
{
public:
    Hairdresser();
    Hairdresser(int hairdresserID, std::string hairdresserName);
    ~Hairdresser();

    std::string getName();
    bool operator==(Hairdresser other);

private:
    int ID;
    std::string name;
};

#endif // HAIRDRESSER_H
