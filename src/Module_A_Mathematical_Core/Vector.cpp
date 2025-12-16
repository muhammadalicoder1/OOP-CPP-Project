#include "Vector.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Default constructor
Vector::Vector() : Tensor(), size(0) {}

// Size-only constructor
Vector::Vector(int s) : Tensor(s, 1), size(s) {}

// Constructor with default value
Vector::Vector(int s, double defaultValue) : Tensor(s, 1), size(s) {
    for (int i = 0; i < size; i++) {
        data[i][0] = defaultValue;
    }
}

// Copy constructor
Vector::Vector(const Vector& other) : Tensor(other), size(other.size) {}

// Destructor
Vector::~Vector() {
    // Base class destructor handles cleanup
}

// Assignment operator
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        Tensor::operator=(other);
        size = other.size;
    }
    return *this;
}

// Get size
int Vector::getSize() const {
    return size;
}

// Element access operator
double& Vector::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Vector index out of bounds");
    }
    return data[index][0];
}

const double& Vector::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Vector index out of bounds");
    }
    return data[index][0];
}

// Sum of all elements
double Vector::sum() const {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += data[i][0];
    }
    return total;
}

// Mean of all elements
double Vector::mean() const {
    if (size == 0) return 0.0;
    return sum() / size;
}

// Maximum element
double Vector::max() const {
    if (size == 0) {
        throw std::runtime_error("Cannot find max of empty vector");
    }
    double maxVal = data[0][0];
    for (int i = 1; i < size; i++) {
        if (data[i][0] > maxVal) {
            maxVal = data[i][0];
        }
    }
    return maxVal;
}

// Minimum element
double Vector::min() const {
    if (size == 0) {
        throw std::runtime_error("Cannot find min of empty vector");
    }
    double minVal = data[0][0];
    for (int i = 1; i < size; i++) {
        if (data[i][0] < minVal) {
            minVal = data[i][0];
        }
    }
    return minVal;
}

// Display method override
void Vector::display() const {
    std::cout << "Vector [" << size << "]:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << data[i][0] << " ";
    }
    std::cout << std::endl;
}
