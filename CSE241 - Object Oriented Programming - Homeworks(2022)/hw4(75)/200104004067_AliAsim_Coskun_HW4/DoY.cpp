#include "DoY.h"

namespace DAY_OF_YEAR
{
    // Default constructor for DayOfYear class
    DayofYearSet::DayOfYear::DayOfYear() : day_(0), month_(0) {}

    // Constructor for DayOfYear class with input parameters for day and month
    DayofYearSet::DayOfYear::DayOfYear(int day, int month) : day_(day), month_(month){
        // Check if input day is valid for the given month
        dayOfMonth();
    }
    
    // Returns the name of the month for the DayOfYear object
    std::string DayofYearSet::DayOfYear::monthName() const {
        // Array of strings representing the names of the months
        static const std::array<std::string, 12> MONTHS = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
        // Return the month name based on the month value stored in the object
        return MONTHS[month_ - 1];
    }

    // Checks if the day value stored in the object is valid for the given month
    void DayofYearSet::DayOfYear::dayOfMonth() const {
        // Array of integers representing the number of days in each month
        static const std::array<int, 12> DAYS_IN_MONTH = {
            31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
        // If the day value is not valid for the given month, output an error message and exit the program
        if (day_ > DAYS_IN_MONTH[month() - 1]) {
            std::cout << "Invalid input. Program is over!\n" << std::endl;
            exit(1);
        }
    }

    // Returns the number of days in the given month
    int DayofYearSet::daysOfMonth(int monthofyear) const {
        static const std::array<int, 12> DAYS_IN_MONTH = {
            31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
        // Return the number of days for the given month
        return DAYS_IN_MONTH[monthofyear - 1];
    }

    // Default constructor for DayofYearSet class
    DayofYearSet::DayofYearSet() : size_(0), data_(nullptr) {}

    // Constructor for DayofYearSet class with an initializer list of DayOfYear objects
    DayofYearSet::DayofYearSet(std::initializer_list<DayOfYear> days) : size_(days.size()) {
        // Allocate memory for the data array and copy the elements from the initializer list to the array
        data_ = new DayOfYear[size_];
        std::copy(days.begin(), days.end(), data_);
    }

    // Copy constructor for DayofYearSet class
    DayofYearSet::DayofYearSet(const DayofYearSet& other) {
        // Copy the size value and allocate memory
        size_ = other.size_;
        data_ = new DayOfYear[size_];
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }

    // Destructor for DayofYearSet class
    DayofYearSet::~DayofYearSet() {
        // If the data array is not a null pointer, delete it to free up memory
        if (data_ != nullptr) {
            delete[] data_; 
        }
    }

    // Overloaded assignment operator for DayofYearSet class
    DayofYearSet& DayofYearSet::operator=(const DayofYearSet& other) {
        // Check for self-assignment
        if (this == &other) {
            return *this;
        }
        // Copy the size value and delete the current data array
        size_ = other.size_;
        delete[] data_;
        // Allocate new memory for the data array and copy the elements from the other DayofYearSet object
        data_ = new DayOfYear[size_];
        std::copy(other.data_, other.data_ + size_, data_);
        // Return the modified DayofYearSet object
        return *this;
    }

    // Overloaded output operator for DayofYearSet class
    std::ostream& operator<<(std::ostream& os, const DayofYearSet& set) {
        // Output the opening curly brace
        os << "{";
        // Output each DayOfYear object in the set, separated by commas
        for (int i = 0; i < set.size_; i++) {
            os << set.data_[i].monthName() << " " << set.data_[i].day();
            if (i != set.size_ - 1) {
                os << ", ";
            }
        }
        // Output the closing curly brace
        os << "}";
        // Return the output stream
        return os;
    }

    // Overloaded equality operator for DayofYearSet class
    bool operator==(const DayofYearSet& lhs, const DayofYearSet& rhs) {
        // If the sizes of the sets are different, they cannot be equal
        if (lhs.size_ != rhs.size_) {
            return false;
        }
        // Iterate through each DayOfYear object in the sets and compare their day values
        for (int i = 0; i < lhs.size_; i++) {
            if (lhs.data_[i].day() != rhs.data_[i].day()) {
                return false;
            }
        }
        // If all DayOfYear objects have matching day values, the sets are equal
        return true;
    }

    // Returns true if the given DayOfYear object is already in the set, false otherwise
    bool DayofYearSet::is_duplicated(const DayOfYear& other)
    {
        // Iterate through each DayOfYear object in the set and compare their day and month values
        for(int i=0; i<size_; i++)
        {
            if(data_[i].day() == other.day() && data_[i].month() == other.month() )
                return false;
        }
        // If no matching DayOfYear object is found, return false
        return true;
    }

    // Overloads the not equal operator for DayofYearSet objects.
    bool operator!=(const DayofYearSet& lhs, const DayofYearSet& rhs) {
        // Returns true if the two DayofYearSet objects are not equal, false otherwise.
        return !(lhs == rhs);
    }

    // Overloads the addition operator for DayofYearSet objects.
    // Returns a new DayofYearSet object that is the union of the two input sets, without duplicates.
    DayofYearSet DayofYearSet::operator+(const DayofYearSet& other) {
        DayofYearSet result;
        int i,j,k, number_of_duplicated=0;
        for(i=0; i<other.size_; i++)
        {
            if(!is_duplicated(other.data_[i]))
                number_of_duplicated += 1;
        }
        result.size_ = size_ + other.size_ - number_of_duplicated;
        result.data_= new DayOfYear[result.size_];
        
        for(i=0; i<other.size_; i++)
        {
            result.data_[i] = other.data_[i];
        }
        j=0;
        for(k=i; i<result.size_; k++)
        {
            if(!result.is_duplicated(data_[j]))
            {
                result.data_[k] = data_[j];
                j++;
            }

        }
        return result;
    }

    // Overloads the subtraction operator for DayofYearSet objects.
    // Returns a new DayofYearSet object that contains the elements in the first set that are not in the second set.
    DayofYearSet DayofYearSet::operator-(const DayofYearSet& other) {
        DayofYearSet result;
        for (int i = 0; i < size_; i++) {
            bool found = false;
            for (int j = 0; j < other.size_; j++) {
                if (data_[i].day() == other.data_[j].day()) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                result.add(data_[i]);
            }
        }
        return result;
    }

    // Overloads the indexing operator for DayofYearSet objects.
    // Returns a reference to the element at the specified index in the set.
    // Throws std::out_of_range exception if the index is out of range.
    DayofYearSet::DayOfYear& DayofYearSet::operator[](int index) {
        if (index < 0 || index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }

    // Overloads the addition assignment operator for DayofYearSet objects.
    // Adds a DayOfYear object to the set, if it is not already present.
    void DayofYearSet::operator+(const DayOfYear& other) {
        if(is_duplicated(other))
        {
            DayofYearSet another;
            another.size_ = size_ + 1;
            another.data_ = new DayOfYear[another.size_];
            int i = 0;
            for (i = 0; i < size_; i++) {
                another.data_[i] = data_[i];
            }
            another.data_[i]=other;
            delete[] (*this).data_;
            (*this).data_ = new DayOfYear[another.size_];
            for (i = 0; i < another.size_; i++)
            {
                (*this).data_[i]=another.data_[i];
            }
            size_=another.size_;
        }
    }

    // Overloads the bitwise XOR operator for DayofYearSet objects.
    // Returns a new DayofYearSet object that contains the elements that are present in one set, but not both.
    DayofYearSet DayofYearSet::operator^(const DayofYearSet& rhs) const {
        DayofYearSet intersection;
        for (int i = 0; i < size_; i++) {
            for (int j = 0; j < rhs.size_; j++) {
                if ((data_[i].day() == rhs.data_[j].day()) && (data_[i].month() == rhs.data_[j].month())) {
                    intersection.add(data_[i]);
                    break;
                }
            }
        }
        return intersection;
    }

    // Overloads the unary negation operator for DayofYearSet objects.
    // Returns a new DayofYearSet object that contains the elements that are not present in the original set.
    DayofYearSet DayofYearSet::operator!() const {
        DayofYearSet complement;
        int flag=0;
        for (int i = 1; i <= 12; i++) {
            for (int j = 1; j <= daysOfMonth(i); j++) {
                flag=0;
                for (int k = 0; k < size_; k++)
                {
                    if (((data_[k].day() == j) && (data_[k].month() == i)))
                    {   
                        flag=1;
                    }
                }
                if(flag==0) complement.add(DayOfYear(j, i));
            }
        }
        return complement;
    }

    // Adds a DayOfYear object to the set.
    void DayofYearSet::add(const DayOfYear& day) {
        DayOfYear* temp = new DayOfYear[size_ + 1];
        std::copy(data_, data_ + size_, temp);
        temp[size_] = day;
        delete[] data_;
        data_ = temp;
        size_++;
    }
}
