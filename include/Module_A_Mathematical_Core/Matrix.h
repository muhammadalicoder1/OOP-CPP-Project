#ifndef MATRIX_H
#define MATRIX_H

#include "Tensor.h"
#include <iostream>

/**
 * @class Matrix
 * @brief Matrix operations with operator overloading
 * 
 * This class demonstrates:
 * - Inheritance from Tensor (multi-level when Vector also inherits)
 * - Operator overloading for mathematical operations (+, -, *, <<)
 * - Polymorphism through virtual method override
 * - Matrix-specific operations (transpose, dot product)
 */
class Matrix : public Tensor {
public:
    // Constructors
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);
    
    // Destructor
    ~Matrix();
    
    // Operator overloading
    Matrix operator+(const Matrix& other) const;     // Matrix addition
    Matrix operator-(const Matrix& other) const;     // Matrix subtraction
    Matrix operator*(const Matrix& other) const;     // Matrix multiplication (dot product)
    Matrix& operator=(const Matrix& other);          // Assignment operator
    
    // Friend function for stream insertion
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    
    // Matrix operations
    Matrix transpose() const;                        // Matrix transpose
    double& at(int row, int col);                    // Element access with bounds checking
    const double& at(int row, int col) const;        // Const version for read-only access
    
    // Override display method
    void display() const override;
};

#endif // MATRIX_H
