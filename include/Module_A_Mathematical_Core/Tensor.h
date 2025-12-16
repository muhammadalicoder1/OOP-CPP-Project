#ifndef TENSOR_H
#define TENSOR_H

#include <iostream>

/**
 * @class Tensor
 * @brief Base class for 2D dynamic array management
 * 
 * This class demonstrates:
 * - Dynamic memory management with proper allocation/deallocation
 * - Deep copy semantics (copy constructor and assignment operator)
 * - Encapsulation with private data members and public interface
 * - Foundation for inheritance hierarchy (Matrix and Vector derive from this)
 */
class Tensor {
protected:
    double** data;  // 2D dynamic array
    int rows;       // Number of rows
    int cols;       // Number of columns
    
    // Protected helper methods for memory management
    void allocateMemory(int r, int c);
    void deallocateMemory();
    void copyData(const Tensor& other);

public:
    // Constructors
    Tensor();                                    // Default constructor
    Tensor(int rows, int cols);                  // Parameterized constructor
    Tensor(const Tensor& other);                 // Copy constructor (deep copy)
    
    // Destructor
    virtual ~Tensor();                           // Virtual destructor for proper cleanup in inheritance
    
    // Assignment operator
    Tensor& operator=(const Tensor& other);      // Deep copy assignment
    
    // Getters
    int getRows() const;
    int getCols() const;
    double getValue(int row, int col) const;
    
    // Setters
    void setValue(int row, int col, double value);
    
    // Display method
    virtual void display() const;
};

#endif // TENSOR_H
