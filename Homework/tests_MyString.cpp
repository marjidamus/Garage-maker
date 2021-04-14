#include "catch2.hpp"
#include "MyString.h"

TEST_CASE("Testing constructors and getters")
{
    SECTION("Testing the deafult constructor")
    {
        MyString str;
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }

    SECTION("Testing the constructor with non-null parameters")
    {
        MyString str("string");
        REQUIRE(strcmp(str.c_str(), "string") == 0);
        REQUIRE(str.size() == 6);
    }

    SECTION("Testing the constructor with an empty string")
    {
        MyString str("");
        REQUIRE(strcmp(str.c_str(), "") == 0);
        REQUIRE(str.size() == 0);
    }

    SECTION("Testing the constructor with a null pointer")
    {
        MyString str(nullptr);
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }

    SECTION("Testing the copy constructor with a non-null parameteres")
    {
        MyString str1("string");
        MyString str2(str1);
        REQUIRE(strcmp(str2.c_str(), "string") == 0);
        REQUIRE(str2.size() == 6);
    }

    SECTION("Testing the copy constructor with an empty string")
    {
        MyString str1("");
        MyString str2(str1);
        REQUIRE(strcmp(str2.c_str(), "") == 0);
        REQUIRE(str2.size() == 0);
    }

    SECTION("Testing the copy constructor with a null pointer")
    {
        MyString null;
        MyString str(null);
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
}

TEST_CASE("Testing the setters")
{
    SECTION("Testing the setter with a non-null parameteres")
    {
        MyString str;
        str.setString("string");
        REQUIRE(strcmp(str.c_str(), "string") == 0);
        REQUIRE(str.size() == 6);
    }

    SECTION("Testing the setter with an empty string")
    {
        MyString str;
        str.setString("");
        REQUIRE(strcmp(str.c_str(), "") == 0);
        REQUIRE(str.size() == 0);
    }

    SECTION("Testing the setter with a null pointer")
    {
        MyString str;
        str.setString(nullptr);
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
}

TEST_CASE("Testing the at function and [] operator ")
{
    MyString str("string");
    SECTION(" Testing the function with valid position")
    {
        REQUIRE(str.at(3) == 'i');
    }

    SECTION(" Testing the function with an out of range position")
    {
        REQUIRE_THROWS(str.at(8));
    }

    SECTION("Testing the [] operator with a valid postion")
    {
        REQUIRE(str[3] == 'i');
    }
}

TEST_CASE("Testing the front funtion")
{
    SECTION("Testing with a valid position")
    {
        MyString str("string");
        REQUIRE(str.front() == 's');
    }
}

TEST_CASE("Testing the back funtion")
{
    SECTION("Testing with a valid position")
    {
        MyString str("string");
        REQUIRE(str.back() == 'g');
    }
}

TEST_CASE("Testing the empty function")
{
    SECTION("Testing with a non-null value")
    {
        MyString str("string");
        REQUIRE(str.empty() == 0);
    }

    SECTION("Testing with an empty string")
    {
        MyString str("");
        REQUIRE(str.empty() == 1);
    }

    SECTION("Testing with a null pointer")
    {
        MyString str(nullptr);
        REQUIRE(str.empty() == 1);
    }
}

TEST_CASE("Testing the clear function")
{
    SECTION("Testing with a non-null value")
    {
        MyString str("string");
        str.clear();
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
    SECTION("Testing with an empty string")
    {
        MyString str("");
        str.clear();
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
    SECTION("Testing with a null pointer")
    {
        MyString str(nullptr);
        str.clear();
        REQUIRE(str.c_str() == nullptr);
        REQUIRE(str.size() == 0);
    }
}

TEST_CASE("Testing the push back function")
{
    SECTION("Testing with a non-null value")
    {
        MyString str("strin");
        str.push_back('g');
        REQUIRE(str.back() == 'g');
        REQUIRE(str.size() == 6);
    }

    SECTION("Testing with an empty string")
    {
        MyString str("");
        str.push_back('M');
        REQUIRE(str.back() == 'M');
        REQUIRE(str.size() == 1);
    }

    SECTION("Testing with a nullpointer")
    {
        MyString str(nullptr);
        str.push_back('M');
        REQUIRE(str.back() == 'M');
        REQUIRE(str.size() == 1);
    }
}

TEST_CASE("Testing the pop back function")
{
    SECTION("Testing with a non-null value")
    {
        MyString str("string");
        str.pop_back();
        REQUIRE(str.size() == 5);
    }

    SECTION("Testing with a nullpointer")
    {
        MyString str(nullptr);
        str.pop_back();
        REQUIRE(str.size() == 0);
    }
}

TEST_CASE("Testing the = overloading operator")
{
    SECTION("Testing with a non-null value")
    {
        MyString str1("string");
        MyString str2;
        str2 = str1;
        REQUIRE(strcmp(str2.c_str(), "string") == 0);
        REQUIRE(str2.size() == 6);
    }

    SECTION("Testing with an empty string")
    {
        MyString str1("");
        MyString str2;
        str2 = str1;
        REQUIRE(strcmp(str2.c_str(), "") == 0);
        REQUIRE(str2.size() == 0);
    }

    SECTION("Testing with a nullpointer")
    {
        MyString str1(nullptr);
        MyString str2;
        str2 = str1;
        REQUIRE(str2.c_str() == nullptr);
        REQUIRE(str2.size() == 0);
    }
}

TEST_CASE("Testing the += char overloading operator")
{
    SECTION("Testing with a non-null value")
    {
        MyString str1("strin");
        str1 += 'g';
        REQUIRE(str1.back() == 'g');
        REQUIRE(str1.size() == 6);
    }

    SECTION("Testing with an empty string")
    {
        MyString str1("");
        str1 += 'g';
        REQUIRE(str1.back() == 'g');
        REQUIRE(str1.size() == 1);
    }

    SECTION("Testing with an empty string")
    {
        MyString str1(nullptr);
        str1 += 'g';
        REQUIRE(str1.back() == 'g');
        REQUIRE(str1.size() == 1);
    }
}

TEST_CASE("Testing the += string overloading operator")
{
    SECTION("Testing with a non-null value")
    {
        MyString str1("string ");
        MyString str2("operator");
        str1 += str2;
        REQUIRE(strcmp(str1.c_str(), "string operator") == 0);
        REQUIRE(str1.size() == 15);
    }

    SECTION("Testing with an empty string")
    {
        MyString str1("string");
        MyString str2("");
        MyString str3("operator");
        str1 += str2;
        str2 += str3;
        REQUIRE(strcmp(str1.c_str(), "string") == 0);
        REQUIRE(str1.size() == 6);
        REQUIRE(strcmp(str2.c_str(), "operator") == 0);
        REQUIRE(str2.size() == 8);
    }

    SECTION("Testing with a null pointer")
    {
        MyString str1("string");
        MyString str2(nullptr);
        MyString str3("operator");
        str1 += str2;
        str2 += str3;
        REQUIRE(strcmp(str1.c_str(), "string") == 0);
        REQUIRE(str1.size() == 6);
        REQUIRE(strcmp(str2.c_str(), "operator") == 0);
        REQUIRE(str2.size() == 8);
    }
}

TEST_CASE("Testing the < overloading operator")
{
    SECTION("Testing with non-null values")
    {
        MyString str1("hey");
        MyString str2("you");
        REQUIRE((str1 < str2) == 1);
    }

    SECTION("Testing with equal values")
    {
        MyString str1("hey");
        MyString str2("hey");
        REQUIRE((str1 < str2) == 0);
    }

    SECTION("Testing with an empty string")
    {
        MyString str1("hey");
        MyString str2("");
        REQUIRE((str1 < str2) == 0);
        REQUIRE((str2 < str1) == 1);
    }

    SECTION("Testing with a null pointer")
    {
        MyString str1("hey");
        MyString str2(nullptr);
        REQUIRE((str1 < str2) == 0);
        REQUIRE((str2 < str1) == 1);
    }
}

TEST_CASE("Testing the == overloading operator")
{
    SECTION("Testing with non-null values")
    {
        MyString str1("hey");
        MyString str2("you");
        REQUIRE((str1 == str2) == 0);
        MyString str3("hey");
        REQUIRE((str1 == str3) == 1);
    }

    SECTION("Testing with an empty string")
    {
        MyString str1("hey");
        MyString str2("");
        REQUIRE((str1 == str2) == 0);
        MyString str3("");
        REQUIRE((str2 == str3) == 1);
    }

    SECTION("Testing with a nullpointer")
    {
        MyString str1("hey");
        MyString str2(nullptr);
        REQUIRE((str1 == str2) == 0);
        MyString str3(nullptr);
        REQUIRE((str2 == str3) == 1);
    }
}