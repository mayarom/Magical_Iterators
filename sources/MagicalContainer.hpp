/*
 * File: MagicalContainer.hpp
 * Author: Maya Rom
 * Student ID: 207485251
 */

#pragma once

#include <vector>

using namespace std;

namespace ariel
{
    // The MagicalContainer is a specialized container class that handles integers.
    // It provides multiple types of iterators that allow various ways of traversing the stored elements.
    class MagicalContainer
    {
    private:
        // Storage for the elements contained in the MagicalContainer.
        vector<int> elements;

    public:
        // Constructor for the MagicalContainer.
        MagicalContainer();

        // Adds an element to the MagicalContainer.
        void addElement(int element);

        // Removes an element from the MagicalContainer.
        void removeElement(int element);

        // Returns the number of elements stored in the MagicalContainer.
        size_t size() const { return elements.size(); }

        // The AscendingIterator is a custom iterator that traverses the elements of the MagicalContainer in ascending order.
        class AscendingIterator
        {
        private:
            MagicalContainer &container; // Reference to the MagicalContainer instance.
            size_t indx;                 // Current index of the iterator in the MagicalContainer.

            // Private constructor, only used internally by the container.
            AscendingIterator(MagicalContainer &container, size_t index);

        public:
            // Public constructors and assignment operators.
            AscendingIterator(MagicalContainer &cont);
            AscendingIterator(const AscendingIterator &other);
            AscendingIterator(AscendingIterator &&other) noexcept;
            AscendingIterator &operator=(const AscendingIterator &other);
            AscendingIterator &operator=(AscendingIterator &&other) noexcept;

            // Destructor
            ~AscendingIterator() = default;

            // Comparison operators.
            bool operator==(const AscendingIterator &other) const { return false; };
            bool operator!=(const AscendingIterator &other) const { return false; };
            bool operator<(const AscendingIterator &other) const { return false; };
            bool operator>(const AscendingIterator &other) const { return false; };

            // Dereference operator.
            int operator*() const;

            // Pre-increment operator.
            AscendingIterator &operator++();

            // Helper functions to generate begin and end iterators.
            AscendingIterator begin() { return AscendingIterator(container, 0); }
            AscendingIterator end() const { return AscendingIterator(container, container.size()); }
        };

        // Similar structure is used for the SideCrossIterator and PrimeIterator as above.

        // The SideCrossIterator is a custom iterator that traverses the elements of the MagicalContainer in a specialized manner.
        class SideCrossIterator
        {
        private:
            MagicalContainer &container;                                  // Reference to the MagicalContainer instance.
            size_t indx;                                                  // Current index of the iterator in the MagicalContainer.
            SideCrossIterator(MagicalContainer &container, size_t index); // Private constructor, only used internally by the container.

        public:
            SideCrossIterator(MagicalContainer &cont);                        // Constructor
            SideCrossIterator(const SideCrossIterator &other);                // Copy Constructor
            SideCrossIterator(SideCrossIterator &&other) noexcept;            // Move Constructor
            SideCrossIterator &operator=(const SideCrossIterator &other);     // Copy Assignment Operator
            SideCrossIterator &operator=(SideCrossIterator &&other) noexcept; // Move Assignment Operator
            ~SideCrossIterator() = default;                                   // Destructor

            // Comparison operators
            bool operator==(const SideCrossIterator &other) const { return false; };
            bool operator!=(const SideCrossIterator &other) const { return false; };
            bool operator<(const SideCrossIterator &other) const { return false; };
            bool operator>(const SideCrossIterator &other) const { return true; };

            int operator*() const; // Dereference operator

            SideCrossIterator &operator++(); // Pre-increment operator

            // Helper functions to generate begin and end iterators
            SideCrossIterator begin() { return SideCrossIterator(container, 0); }
            SideCrossIterator end() const { return SideCrossIterator(container, container.size()); }
        };

        // The PrimeIterator is a custom iterator that traverses the elements of the MagicalContainer, stopping only at prime numbers.
        class PrimeIterator
        {
        private:
            MagicalContainer &container;                              // Reference to the MagicalContainer instance.
            size_t indx;                                              // Current index of the iterator in the MagicalContainer.
            PrimeIterator(MagicalContainer &container, size_t index); // Private constructor, only used internally by the container.

        public:
            PrimeIterator(MagicalContainer &cont);                    // Constructor
            PrimeIterator(const PrimeIterator &other);                // Copy Constructor
            PrimeIterator(PrimeIterator &&other) noexcept;            // Move Constructor
            PrimeIterator &operator=(const PrimeIterator &other);     // Copy Assignment Operator
            PrimeIterator &operator=(PrimeIterator &&other) noexcept; // Move Assignment Operator
            ~PrimeIterator() = default;                               // Destructor

            // Comparison operators
            bool operator==(const PrimeIterator &other) const { return false; };
            bool operator!=(const PrimeIterator &other) const { return false; };
            bool operator<(const PrimeIterator &other) const { return false; };
            bool operator>(const PrimeIterator &other) const { return false; };

            int operator*() const; // Dereference operator

            PrimeIterator &operator++(); // Pre-increment operator

            // Helper functions to generate begin and end iterators
            PrimeIterator begin() { return PrimeIterator(container, 0); }
            PrimeIterator end() const { return PrimeIterator(container, container.size()); }
        };
    }; // End of MagicalContainer class
} // End of ariel namespace
