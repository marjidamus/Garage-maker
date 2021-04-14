#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString
{
private:
    char *string;
    size_t length;
    void deallocate();
    char *dynString(const char *str);
    void copy(const MyString &other);

public:
    //constructors
    MyString();
    MyString(const char *str);
    MyString(const MyString &other);

    //Setters
    void setString(const char *str);

    //Getters
    const char *c_str() const;
    size_t size() const;

    //Functions
    char &at(size_t pos);
    const char &at(size_t pos) const;
    char &operator[](size_t pos);
    const char &operator[](size_t pos) const;
    char &front();
    const char &front() const;
    char &back();
    const char &back() const;
    bool empty() const;
    void clear();
    void push_back(char c);
    void pop_back();

    //Overloading operators
    MyString &operator=(const MyString& other);
    MyString &operator+=(char c);
    MyString &operator+=(const MyString &rhs);
    MyString operator+(char c) const;
    MyString operator+(const MyString &rhs) const;
    bool operator==(const MyString &rhs) const;
    bool operator<(const MyString &rhs) const;

    //Destructor
    ~MyString();
}; 

#endif