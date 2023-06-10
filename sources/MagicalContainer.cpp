/**
 * @file MagicalContainer.cpp
 * @author Maya Rom, ID: 207485251
 * @date June 10, 2023
 * @brief This file contains implementation for the MagicalContainer class and its nested iterator classes.
 * 
 * @details MagicalContainer is a custom container that supports different types of iterators: Ascending, SideCross, and Prime.
 */


#include "MagicalContainer.hpp"
#include "iostream"

using namespace ariel;
using namespace std;

// Default constructor for the MagicalContainer
MagicalContainer::MagicalContainer() {}

// Method to add an element to the MagicalContainer
void MagicalContainer::addElement(int element) {}

// Method to remove an element from the MagicalContainer
void MagicalContainer::removeElement(int element) {}

// AscendingIterator's constructor
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container, size_t index) : container(container), indx(index) {}

// Overloaded constructor for AscendingIterator
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &cont) : container(cont), indx(0) {}

// Copy constructor for AscendingIterator
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) : container(other.container), indx(other.indx) {}

// Overload of the assignment operator for AscendingIterator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    return *this;
}

// Overload of the dereference operator for AscendingIterator
int MagicalContainer::AscendingIterator::operator*() const
{
    return 0;
}

// Overload of the pre-increment operator for AscendingIterator
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    indx++;
    return *this;
}

// SideCrossIterator's constructor
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, size_t index) : container(container), indx(index) {}

// Overloaded constructor for SideCrossIterator
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &cont) : container(cont), indx(0) {}

// Copy constructor for SideCrossIterator
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) : container(other.container), indx(other.indx) {}

// Overload of the assignment operator for SideCrossIterator
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    return *this;
}

// Overload of the dereference operator for SideCrossIterator
int MagicalContainer::SideCrossIterator::operator*() const
{
    return 0;
}

// Overload of the pre-increment operator for SideCrossIterator
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    indx++;
    return *this;
}

// PrimeIterator's constructor
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, size_t index) : container(container), indx(index) {}

// Overloaded constructor for PrimeIterator
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &cont) : container(cont), indx(0) {}

// Copy constructor for PrimeIterator
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) : container(other.container), indx(other.indx) {}

// Overload of the assignment operator for PrimeIterator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    return *this;
}

// Overload of the dereference operator for PrimeIterator
int MagicalContainer::PrimeIterator::operator*() const
{
    return 0;
}

// Overload of the pre-increment operator for PrimeIterator
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    indx++;
    return *this;
}
