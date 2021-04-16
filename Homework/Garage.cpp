#include "Garage.h"
#include <cstring>
#include <cassert>

void Garage::deallocate()
{
    if (this->vehicles)
    {
        for (int i = 0; i < this->capcty; i++)
        {
            this->vehicles == nullptr;
        }
        delete[] this->vehicles;
    }
}

void Garage::copy(const Garage &other)
{
    if (other.vehicles == nullptr)
    {
        this->vehicles == nullptr;
        this->capcty == 0;
        this->occpd = 0;
        this->numVcles = 0;
        return;
    }
    try
    {
        this->vehicles = new Vehicle *[other.capcty];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << "Cannot allocate memory";
        return;
    }
    for (int i = 0; i < other.capcty; i++)
    {
        this->vehicles[i] = other.vehicles[i];
    }
    this->capcty = other.capcty;
    this->numVcles = other.numVcles;
    this->occpd = other.occpd;
}

Garage::Garage(std::size_t size)
{
    if (size)
    {
        try
        {
            this->vehicles = new Vehicle *[size];
        }
        catch (std::bad_alloc &e)
        {
            std::cout << "Cannot allocate memory";
            return;
        }
        this->capcty = size;
        this->occpd = 0;
        this->numVcles = 0;

        for (int i = 0; i < this->capcty; i++)
        {
            vehicles[i] = nullptr;
        }
        std::cout << " You have created a garage with " << size << "parking lots" << std::endl;
    }
    else
    {
        this->capcty = 0;
        this->numVcles = 0;
        this->occpd = 0;
        this->vehicles = nullptr;
    }
}

Garage::Garage(const Garage &other)
{
    this->copy(other);
}

std::size_t Garage::size() const
{
    return this->numVcles;
}

Garage::~Garage()
{
    this->deallocate();
}

void Garage::insert(Vehicle &vcle)
{
    try
    {
        if (this->find(vcle.getRegNum()))
        {
            throw std::invalid_argument("Vehicle with such license plate already exists in the garage!");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
    try
    {
        if ((this->occpd + vcle.getOccSpace()) > this->capcty)
        {
            throw std::overflow_error("Not enough space for you vehicle in the garage!");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    this->occpd += vcle.getOccSpace();
    this->vehicles[this->numVcles++] = &vcle;

    std::cout << "Your vehicle is added to the garage!" << std::endl;
}

void Garage::erase(const char *_regNum)
{
    if (this->empty())
    {
        std::cout << "Garage is already empty";
        return;
    }
    int vcleIndex = -1;
    for (int i = 0; i < this->numVcles; i++)
    {
        if (strcmp(this->vehicles[i]->getRegNum(), _regNum) == 0)
        {
            vcleIndex = i;
            break;
        }
    }

    if (vcleIndex = -1)
    {
        std::cout << "Vehicle with such license plate does not exist" << std::endl;
        return;
    }
    this->occpd -= this->vehicles[vcleIndex]->getOccSpace();
    this->vehicles[vcleIndex]=this->vehicles[this->numVcles - 1];
    this->vehicles[this->numVcles - 1]=nullptr;
    this->numVcles -=1;

    std::cout<<" Your vehicle is removed from the garage"<<std::endl;
}

const Vehicle &Garage::at(size_t pos)
{
    if (pos < this->numVcles)
    {
        return *(this->vehicles[pos]);
    }
    else
    {
        throw std::out_of_range("This postion does not exist in the garage");
    }
}
bool Garage::empty() const
{
    return this->numVcles == 0;
}
void Garage::clear()
{
    if (this->numVcles == 0)
    {
        return;
    }
    for (int i = 0; i < this->numVcles; i++)
    {
        this->vehicles = nullptr;
    }
    this->occpd = 0;
    this->numVcles = 0;

    std::cout << "Your garage is cleared!" << std::endl;
}
const Vehicle *Garage::find(const char *_regNum) const
{
    if (_regNum == nullptr || strcmp(_regNum, "")==0)
    {
        return nullptr;
    }
    int vcleIndex = -1;
    for (int i = 0; i < this->numVcles; i++)
    {
        if (strcmp(_regNum, this->vehicles[i]->getRegNum()) == 0)
        {
            vcleIndex = i;
            break;
        }
    }
    if (vcleIndex = -1)
    {
        return nullptr;
    }
    return this->vehicles[vcleIndex];
}

//Overloading operators
const Vehicle &Garage::operator[](std::size_t pos) const
{
    assert(pos < this->numVcles);
    return *(this->vehicles[pos]);
}

Garage &Garage::operator=(const Garage &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }
    return *this;
}
