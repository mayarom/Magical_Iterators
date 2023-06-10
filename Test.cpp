// Test Cases for MagicalContainer Class
// Authored by: Maya Rom
// Student ID: 207485251
// These comprehensive tests ensure the proper functionality of the MagicalContainer class and its various iterators.

#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;

TEST_CASE("Prime Iterator with no primes")
{
    MagicalContainer cont;
    cont.addElement(4);
    cont.addElement(6);
    cont.addElement(8);
    cont.addElement(10);

    MagicalContainer::PrimeIterator pr(cont);

    CHECK(pr == pr.end());
}

TEST_CASE("Prime Iterator with all primes")
{
    MagicalContainer cont;
    cont.addElement(2);
    cont.addElement(3);
    cont.addElement(5);
    cont.addElement(7);

    MagicalContainer::PrimeIterator pr(cont);
    int expected[] = {2, 3, 5, 7};

    for (int i = 0; pr != pr.end(); ++pr, ++i)
    {
        CHECK(*pr == expected[i]);
    }
}

TEST_CASE("Ascending Iterator with reverse order")
{
    MagicalContainer cont;
    for (int i = 10; i >= 1; i--)
    {
        cont.addElement(i);
    }

    MagicalContainer::AscendingIterator asc(cont);
    for (int i = 1; asc != asc.end(); ++asc, ++i)
    {
        CHECK(*asc == i);
    }
}

TEST_CASE("SideCross Iterator skipping every other")
{
    MagicalContainer cont;
    for (int i = 1; i <= 10; i++)
    {
        cont.addElement(i);
    }

    MagicalContainer::SideCrossIterator cross(cont);
    for (int i = 1; cross != cross.end(); i += 2, ++cross)
    {
        CHECK(*cross == i);
    }
}
TEST_CASE("Adding and removing elements")
{
    MagicalContainer cont;
    for (int i = 1; i <= 100; ++i)
    {
        cont.addElement(i);
    }

    CHECK(cont.size() == 100);

    for (int i = 1; i <= 100; ++i)
    {
        cont.removeElement(i);
    }

    CHECK(cont.size() == 0);
}

TEST_CASE("Prime Iterator - Multiple of same prime")
{
    MagicalContainer cont;
    for (int i = 0; i < 5; ++i)
    {
        cont.addElement(3);
    }

    MagicalContainer::PrimeIterator pr(cont);

    for (int i = 0; i < 5; ++i, ++pr)
    {
        CHECK(*pr == 3);
    }

    CHECK(pr == pr.end());
}

TEST_CASE("Ascending Iterator - Negative and positive numbers")
{
    MagicalContainer cont;
    cont.addElement(-3);
    cont.addElement(-2);
    cont.addElement(-1);
    cont.addElement(0);
    cont.addElement(1);
    cont.addElement(2);
    cont.addElement(3);

    MagicalContainer::AscendingIterator asc(cont);

    for (int i = -3; i <= 3; ++i, ++asc)
    {
        CHECK(*asc == i);
    }

    CHECK(asc == asc.end());
}

TEST_CASE("SideCross Iterator - Single element")
{
    MagicalContainer cont;
    cont.addElement(1);

    MagicalContainer::SideCrossIterator cross(cont);

    CHECK(*cross == 1);
    ++cross;

    CHECK(cross == cross.end());
}
TEST_CASE("Check if empty container remains consistent")
{
    MagicalContainer cont;

    CHECK(cont.size() == 0);
    CHECK_THROWS(cont.removeElement(1)); // Removing from an empty container.

    // Check for all iterators.
    MagicalContainer::AscendingIterator asc(cont);
    CHECK(asc == asc.end());

    MagicalContainer::SideCrossIterator cross(cont);
    CHECK(cross == cross.end());

    MagicalContainer::PrimeIterator prime(cont);
    CHECK(prime == prime.end());
}

TEST_CASE("PrimeIterator on non-prime elements")
{
    MagicalContainer cont;
    cont.addElement(1);
    cont.addElement(4);
    cont.addElement(6);
    cont.addElement(8);
    cont.addElement(9);
    cont.addElement(10);

    MagicalContainer::PrimeIterator prime(cont);
    CHECK(prime == prime.end()); // Iterator should be at end since there are no prime numbers.
}

TEST_CASE("Large number of elements AscendingIterator")
{
    MagicalContainer cont;
    for (int i = 1000; i >= 1; i--)
    {
        cont.addElement(i);
    }

    MagicalContainer::AscendingIterator asc(cont);
    for (int i = 1; asc != asc.end(); ++asc, ++i)
    {
        CHECK(*asc == i);
    }
}

TEST_CASE("SideCrossIterator with non-consecutive numbers")
{
    MagicalContainer cont;
    for (int i = 2; i <= 20; i += 2)
    {
        cont.addElement(i);
    }

    MagicalContainer::SideCrossIterator cross(cont);
    for (int i = 2; cross != cross.end(); i += 4, ++cross)
    {
        CHECK(*cross == i);
    }
}

TEST_CASE("Remove non-existent element")
{
    MagicalContainer cont;
    cont.addElement(1);
    cont.addElement(2);
    cont.addElement(3);
    CHECK_THROWS(cont.removeElement(4)); // 4 is not present in the container.
}

