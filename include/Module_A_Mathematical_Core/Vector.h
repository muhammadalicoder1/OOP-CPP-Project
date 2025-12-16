#ifndef VECTOR_H
#define VECTOR_H

#include "Tensor.h"
#include <iostream>

/**
 * @class Vector
 * @brief 1D array specialized from Tensor
 * 
 * This class demonstrates:
 * - Inheritance from Tensor (specialization for 1D arrays)
 * - Constructor overloading (static polymorphism)
 * - Encapsulation of 1D array operations
 * - Reuse of base class functionality
 */
class Vector : public Tensor {
private:
    int size;  // Number of elements in the vector

public:
    // Constructors (demonstrating constructor overloading)
    Vector();                                        // Default constructor
    Vector(int size);                                // Size-only constructor
    Vector(int size, double defaultValue);           // Constructor with default value
    Vector(const Vector& other);                     // Copy constructor
    
    // Destructor
    ~Vector();
    
    // Assignment operator
    Vector& operator=(const Vector& other);
    
    // Vector-specific methods
    int getSize() const;
    double& operator[](int index);                   // Element access operator
    const double& operator[](int index) const;       // Const version
    
    // Statistical operations
    double sum() const;
    double mean() const;
    double max() const;
    double min() const;
    
    // Override display method
    void display() const override;
};

#endif // VECTOR_H
