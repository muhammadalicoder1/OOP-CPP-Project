#include "Matrix.h"
#include <iostream>
#include <stdexcept>

// Default constructor
Matrix::Matrix() : Tensor() {}

// Parameterized constructor
Matrix::Matrix(int rows, int cols) : Tensor(rows, cols) {}

// Copy constructor
Matrix::Matrix(const Matrix& other) : Tensor(other) {}

// Destructor
Matrix::~Matrix() {
    // Base class destructor handles cleanup
}

// Assignment operator
Matrix& Matrix::operator=(const Matrix& other) {
    Tensor::operator=(other);
    return *this;
}

// Matrix addition - operator overloading
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for addition");
    }
    
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

// Matrix subtraction - operator overloading
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match for subtraction");
    }
    
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

// Matrix multiplication (dot product) - operator overloading
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions incompatible for multiplication");
    }
    
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            double sum = 0.0;
            for (int k = 0; k < cols; k++) {
                sum += data[i][k] * other.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

// Matrix transpose
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

// Element access with bounds checking
double& Matrix::at(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Matrix index out of bounds");
    }
    return data[row][col];
}

const double& Matrix::at(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Matrix index out of bounds");
    }
    return data[row][col];
}

// Display method override
void Matrix::display() const {
    std::cout << "Matrix [" << rows << "x" << cols << "]:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// Stream insertion operator - friend function
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << "Matrix [" << matrix.rows << "x" << matrix.cols << "]:" << std::endl;
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.data[i][j] << "\t";
        }
        os << std::endl;
    }
    return os;
}
