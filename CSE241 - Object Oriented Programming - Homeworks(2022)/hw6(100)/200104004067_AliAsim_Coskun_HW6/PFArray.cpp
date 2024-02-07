#include "PFArray.h"

// Constructors
template <typename T>
PFArray<T>::PFArray() : size_(0), capacitance(0), data_(nullptr) {}
template <typename T>
PFArray<T>::PFArray(size_t size) : size_(size), capacitance(size) {std::shared_ptr<T>temp (new T[capacitance]); data_ = temp;}
template <typename T>
PFArray<T>::PFArray(size_t size, T value) : PFArray(size) { std::fill(data_.get(), data_.get() + size, value); }
template <typename T>
PFArray<T>::PFArray(const PFArray& other) : size_(other.size_), capacitance(other.capacitance), data_(std::allocate_shared<T>(std::allocator<T>(), other.capacitance)) {
    std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
}

// Assignment operator
template <typename T>
PFArray<T>& PFArray<T>::operator=(const PFArray& other) {
    if (this != &other) {
        size_ = other.size_;
        capacitance = other.capacitance;
        data_ = std::make_shared<T[]>(capacitance);
        std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
    }
    return *this;
}


// Move assignment operator
template <typename T>
PFArray<T>& PFArray<T>::operator=(PFArray&& other) {
    this->data = std::move(other.data_);
    this->capacitance = other.capacitance;
    other.capacitance = 0;
    this->size_ = 0;
    other.size = 0;
}

// Move constructor
template <typename T>
PFArray<T>::PFArray(PFArray&& other) noexcept : size_(other.size_), capacitance(other.capacitance), data_(std::move(other.data_)) {
    other.size_ = 0;
    other.capacitance = 0;
}

// push_back function
template <typename T>
void PFArray<T>::push_back(const T& element) {
    if (size_ == capacitance) {
        if (capacitance == 0) {
            capacitance = 1;
        } else {
            capacitance *= 2;
        }
        std::shared_ptr<T> new_data(new T[capacitance]);
        std::copy(data_.get(), data_.get() + size_, new_data.get());
        data_ = new_data;
    }
    data_.get()[size_++] = element;
}

// pop_back function
template <typename T>
void PFArray<T>::pop_back() {
    if (size_ == 0) {
        throw std::out_of_range("PFArray is empty");
    }
    size_--;
}

// clear function
template <typename T>
void PFArray<T>::clear() {
    size_ = 0;
}

// swap function
template <typename T>
void PFArray<T>::swap(PFArray& other) {
    std::swap(size_, other.size_);
    std::swap(capacitance, other.capacitance);
    std::swap(data_, other.data_);
}

// empty function
template <typename T>
bool PFArray<T>::empty() const {
    return size_ == 0;
}

// size function
template <typename T>
size_t PFArray<T>::size() const {
    return size_;
}

// capacity function
template <typename T>
size_t PFArray<T>::capacity() const {
    return capacitance;
}

// erase function
template <typename T>
typename PFArray<T>::IterInner PFArray<T>::erase(IterInner position) {
    if (position + 1 != end()) {
        std::copy(position + 1, end(), position);
    }
    size_--;
    return position;
}

// begin function
template <typename T>
typename PFArray<T>::IterInner PFArray<T>::begin() {
    return IterInner(data_.get());
}

// end function
template <typename T>
typename PFArray<T>::IterInner PFArray<T>::end() {
    return IterInner(data_.get() + size_);
}

// cbegin function
template <typename T>
typename PFArray<T>::IterInner PFArray<T>::cbegin() const {
    return IterInner(data_.get());
}

// cbegin function
template <typename T>
typename PFArray<T>::IterInner PFArray<T>::cend() const {
    return IterInner(data_.get() + size_);
}

// access element at given index
template <typename T>
T& PFArray<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range("index out of bounds");
    }
    return data_.get()[index];
}

// access element at given index (constant version)
template <typename T>
const T& PFArray<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range("index out of bounds");
    }
    return data_.get()[index];
}