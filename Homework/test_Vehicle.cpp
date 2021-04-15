#include "catch2.hpp"
#include "Vehicle.h"

TEST_CASE ("Testing the constructors with parameteres")
{
    SECTION ("Testing with non-null value")
    {
        Vehicle vcle ( "A 7911 KH", "BMW x6", 1);
        REQUIRE(strcmp(vcle.getRegNum(), "A 7911 KH")==0);
        REQUIRE(strcmp(vcle.getDescription(), "BMW x6")==0);
        REQUIRE(vcle.getOccSpace()==1);
    }

    SECTION("Testing with an empty string")
    {
        Vehicle vcle("", "", 1);
        REQUIRE(strcmp(vcle.getRegNum(), "")==0);
        REQUIRE(strcmp(vcle.getDescription(), "")==0);
        REQUIRE(vcle.getOccSpace()==1);
    }

    SECTION("Testing with a null pointer")
    {
        Vehicle vcle(nullptr, nullptr, 1);
        REQUIRE(vcle.getRegNum()==nullptr);
        REQUIRE(vcle.getDescription()==nullptr);
        REQUIRE(vcle.getOccSpace()==1);
    }
}