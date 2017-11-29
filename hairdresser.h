#ifndef HAIRDRESSER_H
#define HAIRDRESSER_H
#include <QString>
class Hairdresser
{
public:
    Hairdresser();
    Hairdresser(int hairdresserID, QString hairdresserName);
    ~Hairdresser();

    QString getName();
    bool operator==(Hairdresser other);

private:
    int ID;
    QString name;
};

#endif // HAIRDRESSER_H
