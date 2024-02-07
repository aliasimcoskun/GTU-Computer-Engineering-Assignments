#ifndef PFARRAY_H
#define PFARRAY_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
#include <iterator>
#include <algorithm>

template <typename T>
class PFArray
{
private:
    size_t size_;
    size_t capacitance;
    std::shared_ptr<T> data_;

public:
    // Iterator Inner class
    class IterInner
    {
    public:
        // Iterator traits
        using difference_type = std::ptrdiff_t;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;

        // Constructors
        IterInner(pointer ptr) : iterptr(ptr) {}
        IterInner(const IterInner& other) : iterptr(other.iterptr) {}

        // Operators
        T& operator*() { return *iterptr; }
        T* operator->() { return iterptr; }
        IterInner& operator++() { ++iterptr; return *this; }
        IterInner operator++(int) { IterInner tmp(*this); operator++(); return tmp; }
        IterInner& operator--() { --iterptr; return *this; }
        IterInner operator--(int) { IterInner tmp(*this); operator--(); return tmp; }
        IterInner& operator+=(difference_type n) { iterptr += n; return *this; }
        IterInner& operator-=(difference_type n) { iterptr -= n; return *this; }
        IterInner operator+(difference_type n) { return IterInner(iterptr + n); }
        IterInner operator-(difference_type n) { return IterInner(iterptr - n); }
        difference_type operator-(const IterInner& another) { return iterptr - another.iterptr; }
        bool operator==(const IterInner& another) { return iterptr == another.iterptr; }
        bool operator!=(const IterInner& another) { return iterptr != another.iterptr; }
        bool operator<(const IterInner& another) { return iterptr < another.iterptr; }
        bool operator>(const IterInner& another) { return iterptr > another.iterptr; }
        bool operator<=(const IterInner& another) { return iterptr <= another.iterptr; }
        bool operator>=(const IterInner& another) { return iterptr >= another.iterptr; }

    private:
        pointer iterptr;
    };

    // Constructors
    PFArray();
    PFArray(size_t size);
    PFArray(size_t size, T value);
    PFArray(const PFArray& other);

    // Destructor
    ~PFArray() = default;

    // Assignment operator
    PFArray& operator=(const PFArray& other);

    // Move assignment operator
    PFArray& operator=(PFArray&& other);
        
    // Move constructor
    PFArray(PFArray&& other) noexcept;

    // push_back function
    void push_back(const T& element);

    // pop_back function
    void pop_back();

    // clear function
    void clear();

    // swap function
    void swap(PFArray& other);

    // empty function
    bool empty() const;
    
    // size function
    size_t size() const;

    // capacity function
    size_t capacity() const;

    // erase function
    IterInner erase(IterInner position);
    
    // begin function
    IterInner begin();

    // end function
    IterInner end();

    // cbegin function
    IterInner cbegin() const;

    // cend function
    IterInner cend() const;

    // access element at given index
    T& operator[](size_t index);

    // access element at given index (constant version)
    const T& operator[](size_t index) const;
};

#endif