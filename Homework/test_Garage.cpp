#include "catch2.hpp"
#include "Garage.h"

TEST_CASE("Testing the constructor with parameteres")
{
    SECTION("Testing with non-nul value")
    {
        Garage gar(11);
        REQUIRE(gar.size() == 0);
        REQUIRE(gar.empty());
        REQUIRE_THROWS(gar.at(3), "This position does not exist in the garage");
    }

    SECTION("Testing with null value")
    {
        Garage gar(0);
        REQUIRE(gar.size() == 0);
        REQUIRE(gar.empty());
        REQUIRE_THROWS(gar.at(3), "This position does not exist in the garage");
    }
}

TEST_CASE("Testing the insert function")
{
    SECTION("Testing with non-null values")
    {
        Garage gar(20);
        Vehicle vcle1("A 7981 KH", "Black BMW", 2);
        Vehicle vcle2("SA 5637 EM", "white porsche", 1);
        Vehicle vcle3("PV 9932 KH", "black mazda", 3);
        REQUIRE_NOTHROW(gar.insert(vcle1));
        REQUIRE_NOTHROW(gar.insert(vcle2));
        REQUIRE_NOTHROW(gar.insert(vcle3));
        REQUIRE(gar.size() == 3);
        REQUIRE_THROWS(gar.at(5), "This position does not exist in the garage");
    }
}

TEST_CASE("Testing the erase function")
{
    SECTION("Testing with non-null values")
    {
        Garage gar(20);
        Vehicle vcle1("A 7981 KH", "Black BMW", 2);
        Vehicle vcle2("SA 5637 EM", "white porsche", 1);
        Vehicle vcle3("PV 9932 KH", "black mazda", 3);

        gar.insert(vcle1);
        gar.insert(vcle2);
        gar.insert(vcle3);

        gar.erase("A 7981 KH");
        REQUIRE(gar.size() == 2);

        gar.erase("A 7981 KH");
        REQUIRE(gar.size() == 2);

        gar.erase("SA 5637 EM");
        REQUIRE(gar.size() == 1);

        gar.erase("PV 9932 KH");
        REQUIRE(gar.size() == 0);

        REQUIRE(gar.empty());

        REQUIRE_THROWS(gar.at(0), "This position does not exist in the garage");
    }
}

TEST_CASE("Testing the clear function")
{
    SECTION("Testing woth a non-null value")
    {
        Garage gar(15);

        Vehicle vcle1("A 7981 KH", "Black BMW", 2);
        Vehicle vcle2("SA 5637 EM", "white porsche", 1);
        Vehicle vcle3("PV 9932 KH", "black mazda", 3);

        gar.insert(vcle1);
        gar.insert(vcle2);
        gar.insert(vcle3);

        gar.clear();
        REQUIRE(gar.size() == 0);
    }

    SECTION("Testing with an empty garage")
    {
        Garage gar(0);
        gar.clear();
        REQUIRE(gar.size() == 0);
    }
}

TEST_CASE("Testing the find function")
{
    SECTION("Testing with non-null value")
    {
        Garage gar(15);

        Vehicle vcle1("A 7981 KH", "Black BMW", 2);
        Vehicle vcle2("SA 5637 EM", "white porsche", 1);
        Vehicle vcle3("PV 9932 KH", "black mazda", 3);

        gar.insert(vcle1);
        gar.insert(vcle2);
        gar.insert(vcle3);

        REQUIRE(strcmp(gar.find("A 7981 KH")->getRegNum(), "A 7981 KH")==0);
        REQUIRE(gar.find("A 7281 KH")==nullptr);
    }

    SECTION("Testing with an empty string")
    {
        Garage gar(15);

        Vehicle vcle1("A 7981 KH", "Black BMW", 2);
        Vehicle vcle2("SA 5637 EM", "white porsche", 1);
        Vehicle vcle3("PV 9932 KH", "black mazda", 3);

        gar.insert(vcle1);
        gar.insert(vcle2);
        gar.insert(vcle3);

        REQUIRE(gar.find("")==nullptr);
    }

    SECTION("Testing with a null pointer")
    {
        Garage gar(15);

        Vehicle vcle1("A 7981 KH", "Black BMW", 2);
        Vehicle vcle2("SA 5637 EM", "white porsche", 1);
        Vehicle vcle3("PV 9932 KH", "black mazda", 3);

        gar.insert(vcle1);
        gar.insert(vcle2);
        gar.insert(vcle3);

        REQUIRE(gar.find(nullptr)==nullptr);
    }
}