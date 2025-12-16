#include "Tensor.h"
#include <iostream>
#include <stdexcept>

// Default constructor
Tensor::Tensor() : data(nullptr), rows(0), cols(0) {}

// Parameterized constructor
Tensor::Tensor(int r, int c) : rows(r), cols(c) {
    allocateMemory(r, c);
    // Initialize to zeros
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = 0.0;
        }
    }
}

// Copy constructor - demonstrates deep copy
Tensor::Tensor(const Tensor& other) : rows(other.rows), cols(other.cols) {
    allocateMemory(rows, cols);
    copyData(other);
}

// Destructor
Tensor::~Tensor() {
    deallocateMemory();
}

// Assignment operator - demonstrates deep copy
Tensor& Tensor::operator=(const Tensor& other) {
    if (this != &other) {
        // Deallocate existing memory
        deallocateMemory();
        
        // Copy dimensions
        rows = other.rows;
        cols = other.cols;
        
        // Allocate new memory and copy data
        allocateMemory(rows, cols);
        copyData(other);
    }
    return *this;
}

// Protected helper: Allocate memory
void Tensor::allocateMemory(int r, int c) {
    data = new double*[r];
    for (int i = 0; i < r; i++) {
        data[i] = new double[c];
    }
}

// Protected helper: Deallocate memory
void Tensor::deallocateMemory() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
}

// Protected helper: Copy data from another tensor
void Tensor::copyData(const Tensor& other) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Getters
int Tensor::getRows() const {
    return rows;
}

int Tensor::getCols() const {
    return cols;
}

double Tensor::getValue(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Tensor index out of bounds");
    }
    return data[row][col];
}

// Setters
void Tensor::setValue(int row, int col, double value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Tensor index out of bounds");
    }
    data[row][col] = value;
}

// Display method
void Tensor::display() const {
    std::cout << "Tensor [" << rows << "x" << cols << "]:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
