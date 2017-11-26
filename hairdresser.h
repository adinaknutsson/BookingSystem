#ifndef HAIRDRESSER_H
#define HAIRDRESSER_H
#include <QString>
class Hairdresser
{
public:
    Hairdresser(int hairdresserID, QString hairdresserName);
    ~Hairdresser();
    QString getName();

private:
    int ID;
    QString name;
};

#endif // HAIRDRESSER_H
