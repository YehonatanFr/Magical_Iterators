#include "sources/MagicalContainer.hpp"

#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace ariel;

#include "doctest.h"

// Basic tests for the AscendingIterator class
TEST_CASE("AscendingIterator - Basic tests") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(5);
    container.addElement(1);
    container.addElement(4);

    SUBCASE("Dereference operator (*)") {
        auto it = container.begin();
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
    }

    // SUBCASE("Pre-increment operator (++)") {
    //     auto it = container.begin();
    //     CHECK(*it++ == 1);
    //     CHECK(*it == 2);
    // }

    SUBCASE("Equality comparison (==)") {
        auto it1 = container.begin();
        auto it2 = container.begin();
        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("Inequality comparison (!=)") {
        auto it1 = container.begin();
        auto it2 = container.begin();
        CHECK(!(it1 != it2));
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("GT comparison (>)") {
        auto it1 = container.begin();
        auto it2 = container.begin();
        CHECK(!(it1 > it2));
        ++it1;
        CHECK(it1 > it2);
        CHECK(!(it2 > it1));
    }

    SUBCASE("LT comparison (<)") {
        auto it1 = container.begin();
        auto it2 = container.begin();
        CHECK(!(it1 < it2));
        ++it1;
        CHECK(!(it1 < it2));
        CHECK(it2 < it1);
    }

    SUBCASE("begin() and end()") {
        auto it = container.begin();
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == container.end());
    }
}

// Basic tests for the SideCrossIterator class
TEST_CASE("SideCrossIterator - Basic tests") {
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(4);
    container.addElement(5);

    SUBCASE("Dereference operator (*)") {
        auto it = container.beginSideCross();
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 5);
    }

    // SUBCASE("Pre-increment operator (++)") {
    //     auto it = container.beginSideCross();
    //     CHECK(*it++ == 1);
    //     CHECK(*it == 5);
    // }

    SUBCASE("Equality comparison (==)") {
        auto it1 = container.beginSideCross();
        auto it2 = container.beginSideCross();
        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("Inequality comparison (!=)") {
        auto it1 = container.beginSideCross();
        auto it2 = container.beginSideCross();
        CHECK(!(it1 != it2));
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("GT comparison (>)") {
        auto it1 = container.beginSideCross();
        auto it2 = container.beginSideCross();
        CHECK(!(it1 > it2));
        ++it1;
        CHECK(!(it1 > it2));
        CHECK(it2 > it1);
    }

    SUBCASE("LT comparison (<)") {
        auto it1 = container.beginSideCross();
        auto it2 = container.beginSideCross();
        CHECK(!(it1 < it2));
        ++it1;
        CHECK(it1 < it2);
        CHECK(!(it2 < it1));
    }

    SUBCASE("begin() and end()") {
        auto it = container.beginSideCross();
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(it == container.endSideCross());
    }
}

// Basic tests for the PrimeIterator class
TEST_CASE("PrimeIterator - Basic tests") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(5);
    container.addElement(1);
    container.addElement(4);

    SUBCASE("Dereference operator (*)") {
        auto it = container.beginPrime();
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
    }

    // SUBCASE("Pre-increment operator (++)") {
    //     auto it = container.beginPrime();
    //     CHECK(*it++ == 2);
    //     CHECK(*it == 5);
    // }

    SUBCASE("Equality comparison (==)") {
        auto it1 = container.beginPrime();
        auto it2 = container.beginPrime();
        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("Inequality comparison (!=)") {
        auto it1 = container.beginPrime();
        auto it2 = container.beginPrime();
        CHECK(!(it1 != it2));
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("GT comparison (>)") {
        auto it1 = container.beginPrime();
        auto it2 = container.beginPrime();
        CHECK(!(it1 > it2));
        ++it1;
        CHECK(!(it1 > it2));
        CHECK(it2 > it1);
    }

    SUBCASE("LT comparison (<)") {
        auto it1 = container.beginPrime();
        auto it2 = container.beginPrime();
        CHECK(!(it1 < it2));
        ++it1;
        CHECK(it1 < it2);
        CHECK(!(it2 < it1));
    }

    SUBCASE("begin() and end()") {
        auto it = container.beginPrime();
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == container.endPrime());
    }
}

// Advanced tests for the MagicalContainer class
TEST_CASE("MagicalContainer - Advanced tests") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(5);
    container.addElement(1);
    container.addElement(4);
    container.addElement(14);

    SUBCASE("Test iterator traversal") {
        std::string traversal;
        for (auto it = container.begin(); it != container.end(); ++it) {
            traversal += std::to_string(*it) + " ";
        }
        CHECK(traversal == "1 2 4 5 14 ");

        traversal.clear();
        for (auto it = container.beginSideCross(); it != container.endSideCross(); ++it) {
            traversal += std::to_string(*it) + " ";
        }
        CHECK(traversal == "1 14 2 5 4 ");

        traversal.clear();
        for (auto it = container.beginPrime(); it != container.endPrime(); ++it) {
            traversal += std::to_string(*it) + " ";
        }
        CHECK(traversal == "2 5 ");
    }

    SUBCASE("Test container size") {
        CHECK(container.getSize() == 5);
        container.addElement(7);
        CHECK(container.getSize() == 6);
        container.removeElement(4);
        CHECK(container.getSize() == 5);
    }
}
