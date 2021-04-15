#ifndef VEHICLE_H
#define VEHICLE_H
#include "MyString.h"

class Vehicle
{
private:
    MyString regNum;      // license plate of the vehicle
    MyString description; //description of the vehicle
    std::size_t occSpace; //spaces, occupied by the vehicle

public:
    Vehicle(const char *_regNum, const char *_description, std::size_t _occSpace);
    const char *getRegNum() const;
    const char *getDescription() const;
    std::size_t getOccSpace() const;
};

#endif
