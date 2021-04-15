#ifndef GARAGE_H
#define GARAGE_H
#include "Vehicle.h"

class Garage
{
private:
    std::size_t capcty; //capacity of the garage
    std::size_t occpd; // occupied spaces of the garage
    std::size_t numVcles; //number of vehicles in the garage
    Vehicle **vehicles;

    void deallocate();
    void copy(const Garage &other);

public:
    //Constructors
    Garage(std::size_t size); // creates a garage with max capacity size
    Garage(const Garage &other);

    //Getter
    std::size_t size() const; // vehicles num

    //Class functions
    void insert(Vehicle &vcle);                     // adds a vehicle to the garage
    void erase(const char *_regNum);                //removes a vehicle with such license plate
    const Vehicle &at(size_t pos);                  // getting the element of pos, exception out_of_range;
    bool empty() const;                             // isEmpty?
    void clear();                                   // removes the vehicles from the garage, the capacity remains the same
    const Vehicle *find(const char *_regNum) const; //finds and returns a vehicle in the garage

    //Overloading operators
    const Vehicle &operator[](std::size_t pos) const; // assert validation
    Garage &operator=(const Garage &other);
    

    //Destructor
    ~Garage();
};

#endif