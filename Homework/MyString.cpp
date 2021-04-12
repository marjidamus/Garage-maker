#include <iostream>
#include "MyString.h"
#include <cstring>
#include <cassert>

void MyString::deallocate()
{
    if (this->string)
    {
        delete[] this->string;
    }
}

char *MyString::dynString(const char *str)
{
    char *newstr = new (std::nothrow) char[strlen(str) + 1];
    if (!newstr)
    {
        std::cout << " Cannot allocate memory ";
        return nullptr;
    }
    strcpy(newstr, str);
    return newstr;
}

void MyString::copy(const MyString &other)
{
    this->string = new (std::nothrow) char[other.length + 1];
    if (this->string)
    {
        strcpy(string, other.string);
        this->length = other.length;
    }
    else
    {
        std::cout << " Cannot allocate memory";
    }
}

MyString::MyString()
{
    this->string = nullptr;
    this->length = 0;
}

MyString::MyString(const char *str)
{
    this->string = dynString(str);
    this->length = strlen(string);
}

MyString::MyString(const MyString &other)
{
    this->copy(other);
}
MyString::~MyString()
{
    this->deallocate();
}

void MyString::setString(const char *str)
{
    this->string = dynString(str);
    this->length = strlen(str);
}

const char *MyString::getString() const
{
    return this->string;
}

size_t MyString::getLength() const
{
    return this->length;
}

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
    assert(this->empty());
    return this->string[0];
}

const char &MyString::front() const
{
    assert(this->empty());
    return this->string[0];
}

char &MyString::back()
{
    assert(this->empty());
    return this->string[this->length - 1];
}

const char &MyString::back() const
{
    assert(this->empty());
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
    char temp[this->length + 1];
    strcpy(temp, string);
    this->length++;
    temp[this->length - 1] = c;
    *string = *temp;
    delete[] temp;
}

void MyString::printString() const
{
    for (int i = 0; i < this->length; i++)
    {
        std::cout << string[i];
    }
    std::cout << std::endl;
}
