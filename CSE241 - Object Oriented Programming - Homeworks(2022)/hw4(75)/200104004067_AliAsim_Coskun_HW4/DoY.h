#ifndef DOY_H
#define DOY_H

#include <iostream>
#include <array>
#include <fstream>
#include <initializer_list>

namespace DAY_OF_YEAR
{
    class DayofYearSet {
    public:
        class DayOfYear {
        public:
            DayOfYear();    // Default constructor for DayOfYear class
            DayOfYear(int day, int month);  // Constructor for DayOfYear class with input parameters for day and month

            int day() const { return day_; }    // Getter for DayOfYear class's private variable named day_
            int month() const { return month_; }    // Getter for DayOfYear class's private variable named month_
            
            std::string monthName() const;  // Returns the name of the month for the DayOfYear object
            void dayOfMonth() const;    // Checks if the day value stored in the object is valid for the given month

        private:
            int day_; // Private variable of DayOfYear that keeps days
            int month_; // Private variable of DayOfYear that keeps months
        };

        int daysOfMonth(int monthofyear) const; // Returns the number of days in the given month

        DayofYearSet(); // Default constructor for DayofYearSet class
        DayofYearSet(std::initializer_list<DayOfYear> days);    // Constructor for DayofYearSet class with an initializer list of DayOfYear objects
        DayofYearSet(const DayofYearSet& other);    // Copy constructor for DayofYearSet class
        ~DayofYearSet();    // Destructor for DayofYearSet class

        DayofYearSet& operator=(const DayofYearSet& other); // Overloaded assignment operator for DayofYearSet class
        friend std::ostream& operator<<(std::ostream& os, const DayofYearSet& set); // Overloaded output operator for DayofYearSet class
        friend bool operator==(const DayofYearSet& lhs, const DayofYearSet& rhs);   // Overloaded equality operator for DayofYearSet class
        friend bool operator!=(const DayofYearSet& lhs, const DayofYearSet& rhs);   // Overloads the not equal operator for DayofYearSet objects.
        DayofYearSet operator+(const DayofYearSet& other);  // Overloads the addition operator for DayofYearSet objects.
        DayofYearSet operator-(const DayofYearSet& other);  // Overloads the subtraction operator for DayofYearSet objects.
        DayOfYear& operator[](int index);   // Overloads the indexing operator for DayofYearSet objects.
        void operator+(const DayOfYear& other); // Overloads the addition assignment operator for DayofYearSet objects.
        DayofYearSet operator^(const DayofYearSet& rhs) const;  // Overloads the bitwise XOR operator for DayofYearSet objects.
        DayofYearSet operator!() const; // Overloads the unary negation operator for DayofYearSet objects.

        bool is_duplicated(const DayOfYear& other); // Returns true if the given DayOfYear object is already in the set, false otherwise
        void add(const DayOfYear& day); // Adds a DayOfYear object to the set.
        int size() const { return size_; }  // Getter for DayofYearSet class's private variable named size_

    private:
        int size_;
        DayOfYear* data_;
    };
}

#endif