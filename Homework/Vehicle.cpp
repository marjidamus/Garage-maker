#include <iostream>
#include "MyString.h"
#include "Vehicle.h"

Vehicle::Vehicle(const char *_regNum, const char *_description, std::size_t _occSpace)
{
    regNum.setString(_regNum);
    description.setString(_description);
    occSpace = _occSpace;
}

const char *Vehicle::getRegNum() const
{
    return this->regNum.c_str();
}

const char *Vehicle::getDescription() const
{
    return this->description.c_str();
}

std::size_t Vehicle::getOccSpace() const
{
    return this->occSpace;
}
