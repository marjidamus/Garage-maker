#include <iostream>
#include "MyString.h"
#include <cstring>
#include <cassert>

//Helper functions
void MyString::deallocate()
{

    if (this->string)
    {
        delete[] this->string;
        this->string = nullptr;
    }
}

char *MyString::dynString(const char *str)
{
    if (str == nullptr)
    {
        return nullptr;
    }

    char *newstr;
    try
    {
        newstr = new char[strlen(str) + 1];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << " Cannot allocate memory ";
        return nullptr;
    }
    strcpy(newstr, str);
    return newstr;
}

void MyString::copy(const MyString &other)
{
    if (other.string == nullptr)
    {
        this->string = nullptr;
        this->length = 0;
        return;
    }
    try
    {
        this->string = new char[other.length + 1];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << " Cannot allocate memory";
        return;
    }

    strcpy(string, other.string);
    this->length = other.length;
}

//Constructors
MyString::MyString()
{
    this->string = nullptr;
    this->length = 0;
}

MyString::MyString(const char *str)
{
    this->string = dynString(str);
    if (this->string == nullptr)
    {
        this->length = 0;
        return;
    }
    this->length = strlen(string);
}

MyString::MyString(const MyString &other)
{
    this->copy(other);
}

//Destructor
MyString::~MyString()
{
    this->deallocate();
}

//Setters
void MyString::setString(const char *str)
{
    this->string = dynString(str);
    if (this->string == nullptr)
    {
        this->length = 0;
        return;
    }
    this->length = strlen(str);
}

//Getters
const char *MyString::c_str() const
{
    return this->string;
}

size_t MyString::size() const
{
    return this->length;
}

//Class functions
char &MyString::at(size_t pos)
{
    if (pos >= this->length)
    {
        throw std::out_of_range("This position does not exist");
    }
    else
    {
        return this->string[pos];
    }
}

const char &MyString::at(size_t pos) const
{
    if (pos >= this->length)
    {
        throw std::out_of_range("This position does not exist");
    }
    else
    {
        return this->string[pos];
    }
}

char &MyString::operator[](size_t pos)
{
    assert(pos < this->length);
    return this->string[pos];
}

const char &MyString::operator[](size_t pos) const
{
    assert(pos < this->length);
    return this->string[pos];
}

char &MyString::front()
{
    assert(!this->empty());
    return this->string[0];
}

const char &MyString::front() const
{
    assert(!this->empty());
    return this->string[0];
}

char &MyString::back()
{
    assert(!this->empty());
    return this->string[this->length - 1];
}

const char &MyString::back() const
{
    assert(!this->empty());
    return this->string[this->length - 1];
}

bool MyString::empty() const
{
    return !length;
}

void MyString::clear()
{
    this->deallocate();
    this->length = 0;
}

void MyString::push_back(char c)
{
    if (!this->string)
    {
        try
        {
            this->string = new char[2];
        }
        catch (std::bad_alloc &e)
        {
            std::cout << "Cannot allocate memory" << std::endl;
            return;
        }
        this->string[0] = c;
        this->string[1] = '\0';
        this->length = 1;
        return;
    }
    char *temp;
    try
    {
        temp = new char(this->length + 2);
    }
    catch (std::bad_alloc &e)
    {
        std::cout << " Cannot allocate memory" << std::endl;
        return;
    }

    for (int i = 0; i < this->length; i++)
    {
        temp[i] = this->string[i];
    }
    temp[this->length] = c;
    temp[this->length + 1] = '\0';
    this->deallocate();
    this->setString(temp);
    delete[] temp;
}

void MyString::pop_back()
{
    if (this->string == nullptr || strcmp(this->string, "") == 0)
    {
        this->clear();
        return;
    }
    char *temp;
    try
    {
        temp = new char(this->length);
    }
    catch (std::bad_alloc &e)
    {
        std::cout << " Cannot allocate memory" << std::endl;
        return;
    }

    for (int i = 0; i < this->length - 1; i++)
    {
        temp[i] = this->string[i];
    }
    temp[length - 1] = '\0';
    this->setString(temp);
    delete[] temp;
}

//Overloading operators

MyString &MyString::operator=(const MyString &other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }
    return *this;
}

MyString &MyString::operator+=(char c)
{
    this->push_back(c);
    return *this;
}

MyString &MyString::operator+=(const MyString &rhs)
{
    if (!this->string || this->length == 0)
    {
        *this = rhs;
        return *this;
    }
    if (!rhs.string)
    {
        return *this;
    }

    size_t newLength = this->length + rhs.length;
    char *temp;
    try
    {
        temp = new char[newLength + 1];
    }
    catch (std::bad_alloc &e)
    {
        std::cout << " Cannot allocate memory" << std::endl;
        return *this;
    }
    strcpy(temp, string);
    strcat(temp, rhs.string);
    delete[] string;
    this->length = newLength;
    string = temp;
    return *this;
}

MyString MyString::operator+(char c) const
{
    MyString newStr(this->string);
    newStr += c;
    return newStr;
}

MyString MyString::operator+(const MyString &rhs) const
{
    MyString newStr(this->string);
    newStr += rhs;
    return newStr;
}

bool MyString::operator==(const MyString &rhs) const
{
    if (this->length != rhs.length)
    {
        return 0;
    }
    if (!this->length)
    {
        return 1;
    }
    return !strcmp(this->string, rhs.c_str());
}

bool MyString::operator<(const MyString &rhs) const
{
    if (this->string == nullptr)
    {
        return 1;
    }
    if (rhs.string == nullptr)

    {
        return 0;
    }
    return strcmp(this->string, rhs.c_str()) < 0;
}

// void MyString::printString() const
// {
//     for (int i = 0; i < this->length; i++)
//     {
//         std::cout << string[i];
//     }
//     std::cout << std::endl;
// }
