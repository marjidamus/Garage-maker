#ifndef VEHICLE_H
#define VEHICLE_H
#include "MyString.h"

class Vehicle
{
    private:
    MyString regNum;
    MyString description;
    std::size_t occSpace;

    public:
    Vehicle (const char* _regNum, const char* _description, std::size_t _occSpace);
    const char* getRegNum () const;
    const char* getDescription() const;
    std::size_t getOccSpace() const;

    friend std::ostream& operator<<(std::ostream &out,Vehicle &vcle);

};

#endif
