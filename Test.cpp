#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;


// Basic tests for the AscendingIterator class
TEST_CASE("AscendingIterator - Basic tests") {
    MagicalContainer container;
    container.addElement(2);
    container.addElement(5);
    container.addElement(1);
    container.addElement(4);

    SUBCASE("Dereference operator (*)") {
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
    }

    SUBCASE("Equality comparison (==)") {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("Inequality comparison (!=)") {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(!(it1 != it2));
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("GT comparison (>)") {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(!(it1 > it2));
        ++it1;
        CHECK(it1 > it2);
        CHECK(!(it2 > it1));
    }

    SUBCASE("LT comparison (<)") {
        MagicalContainer::AscendingIterator it1(container);
        MagicalContainer::AscendingIterator it2(container);
        CHECK(!(it1 < it2));
        ++it1;
        CHECK(!(it1 < it2));
        CHECK(it2 < it1);
    }

    SUBCASE("begin() and end()") {
        MagicalContainer::AscendingIterator it(container);
        MagicalContainer::AscendingIterator endIt(container);
        ++endIt; // Pointing to the end
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 4);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == endIt);
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
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 5);
    }

    SUBCASE("Equality comparison (==)") {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("Inequality comparison (!=)") {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(!(it1 != it2));
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("GT comparison (>)") {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(!(it1 > it2));
        ++it1;
        CHECK(it1 > it2);
        CHECK(!(it2 > it1));
    }

    SUBCASE("LT comparison (<)") {
        MagicalContainer::SideCrossIterator it1(container);
        MagicalContainer::SideCrossIterator it2(container);
        CHECK(!(it1 < it2));
        ++it1;
        CHECK(!(it1 < it2));
        CHECK(it2 < it1);
    }

    SUBCASE("begin() and end()") {
        MagicalContainer::SideCrossIterator it(container);
        MagicalContainer::SideCrossIterator endIt(container);
        ++endIt; // Pointing to the end
        CHECK(*it == 1);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == endIt);
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
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
    }

    SUBCASE("Equality comparison (==)") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(it1 == it2);
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("Inequality comparison (!=)") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(!(it1 != it2));
        ++it1;
        CHECK(it1 != it2);
    }

    SUBCASE("GT comparison (>)") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(!(it1 > it2));
        ++it1;
        CHECK(it1 > it2);
        CHECK(!(it2 > it1));
    }

    SUBCASE("LT comparison (<)") {
        MagicalContainer::PrimeIterator it1(container);
        MagicalContainer::PrimeIterator it2(container);
        CHECK(!(it1 < it2));
        ++it1;
        CHECK(!(it1 < it2));
        CHECK(it2 < it1);
    }

    SUBCASE("begin() and end()") {
        MagicalContainer::PrimeIterator it(container);
        MagicalContainer::PrimeIterator endIt(container);
        ++endIt; // Pointing to the end
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 5);
        ++it;
        CHECK(it == endIt);
    }
}

// Advanced tests for the MagicalContainer class
TEST_CASE("MagicalContainer - Advanced tests") {
    MagicalContainer container;

    SUBCASE("Adding and removing elements") {

        CHECK(container.size() == 0);

        container.addElement(10);
        container.addElement(20);
        container.addElement(30);

        CHECK(container.size() == 3);

        container.removeElement(20);

         CHECK_THROWS_AS(container.removeElement(20), runtime_error);

        CHECK(container.size() == 2);

        container.addElement(40);

        CHECK(container.size() == 3);

        container.removeElement(10);

        CHECK(container.size() == 2);
    }

}

