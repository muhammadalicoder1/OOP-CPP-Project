# Titan-Learn: A C++ Logistic Regression Engine

![University Badge](https://img.shields.io/badge/University%20of%20Central%20Punjab-Fall%202025%20Term%20Project-blue)

## Introduction

**Titan-Learn** is a custom-built Machine Learning engine developed entirely in C++ without external libraries. This project demonstrates the implementation of a complete logistic regression pipeline from scratch, emphasizing Object-Oriented Programming (OOP) principles and modern C++ practices.

This academic project showcases how raw data can be processed, analyzed, and used for binary classification using strict OOP design patterns, including inheritance, polymorphism, operator overloading, and virtual inheritance.

## Problem Statement

The goal of this project is to build a machine learning system that can:
- Load and parse CSV data files
- Perform statistical analysis on datasets
- Normalize features using custom scaling algorithms
- Train a logistic regression model using gradient descent
- Make predictions on binary classification problems
- Evaluate model performance with accuracy and precision metrics

All functionality is implemented from scratch without external ML libraries, demonstrating deep understanding of both OOP principles and machine learning algorithms.

## System Architecture

The project is organized into four main modules:

### Module A: Mathematical Core
Foundation for all numerical operations:
- **Tensor**: Base class managing 2D dynamic arrays with deep copy semantics
- **Matrix**: Derived class with operator overloading for mathematical operations (+, -, *, <<)
- **Vector**: Specialized 1D array implementation derived from Tensor

### Module B: Statistical Analysis
Statistical computation engine using multiple and virtual inheritance:
- **StatisticalTool**: Abstract base class defining the statistical interface
- **CentralTendency**: Virtual base class for mean and median calculations
- **Dispersion**: Virtual base class for variance and standard deviation
- **DataSummary**: Combines both using virtual inheritance to solve the Diamond Problem

### Module C: Data Management
Data handling and preprocessing pipeline:
- **Dataset**: CSV parser and data container
- **Scaler**: Abstract interface for feature scaling
- **MinMaxScaler**: Concrete implementation for min-max normalization

### Module D: Model
Machine learning model implementation:
- **Model**: Abstract interface defining train() and predict() methods
- **LogisticRegression**: Concrete implementation with gradient descent training
- **Evaluation**: Friend class for model performance metrics

## Features

✅ **Custom CSV Parser** - Load and parse CSV files without external libraries  
✅ **Automated Statistical Report** - Generate comprehensive statistics using multiple inheritance  
✅ **Matrix Arithmetic Engine** - Full matrix operations with operator overloading  
✅ **Training Loop with Gradient Descent** - Custom implementation of optimization algorithm  
✅ **Binary Classification Prediction System** - Sigmoid activation and threshold-based predictions  
✅ **Model Evaluation** - Calculate accuracy and precision metrics  

## OOP Concepts Demonstrated

### 1. Encapsulation
- Private data members in all classes
- Public getter/setter methods for controlled access
- Information hiding in Tensor, Matrix, and LogisticRegression classes

### 2. Operator Overloading
- Matrix addition (+), subtraction (-), multiplication (*)
- Stream insertion operator (<<) for easy output
- Assignment operator (=) with deep copy semantics

### 3. Deep Copying
- Custom copy constructors in Tensor-based classes
- Assignment operator overloading to prevent shallow copies
- Proper memory management to avoid memory leaks

### 4. Polymorphism
- **Dynamic Polymorphism**: Model interface with virtual methods
- **Static Polymorphism**: Constructor overloading in Vector class
- Virtual method dispatch in Model hierarchy

### 5. Inheritance
- **Multi-level Inheritance**: Vector → Tensor
- **Multiple Inheritance**: DataSummary inherits from CentralTendency and Dispersion
- **Virtual Inheritance**: Solving the Diamond Problem in statistical analysis module

### 6. Virtual Inheritance
- Both CentralTendency and Dispersion virtually inherit from StatisticalTool
- DataSummary inherits from both, creating only one StatisticalTool base instance
- Eliminates ambiguity in the diamond inheritance pattern

### 7. Friend Functions
- Evaluation class declared as friend of LogisticRegression
- Direct access to private weights for evaluation purposes
- Demonstrates controlled violation of encapsulation when necessary

## Build Instructions

### Prerequisites
- C++ compiler with C++17 support (GCC 7+, Clang 5+, or MSVC 2017+)
- CMake 3.10 or higher

### Building the Project

```bash
# Clone the repository
git clone https://github.com/muhammadalicoder1/OOP-CPP-Project.git
cd OOP-CPP-Project

# Create build directory
mkdir build
cd build

# Generate build files
cmake ..

# Compile the project
cmake --build .

# Run the executable
./TitanLearn
```

## Usage Example

```cpp
#include "Dataset.h"
#include "MinMaxScaler.h"
#include "LogisticRegression.h"
#include "Evaluation.h"
#include "DataSummary.h"

int main() {
    // 1. Load dataset
    Dataset dataset;
    dataset.loadCSV("../data/sample_data.csv");
    
    // 2. Display statistical summary
    DataSummary summary;
    summary.generateReport(dataset.getFeatures());
    
    // 3. Scale features
    MinMaxScaler scaler;
    scaler.fit(dataset.getFeatures());
    Matrix scaledData = scaler.transform(dataset.getFeatures());
    
    // 4. Train model
    LogisticRegression model(0.01, 1000);  // learning rate, epochs
    model.train(scaledData, dataset.getLabels());
    
    // 5. Make predictions
    Vector predictions = model.predict(scaledData);
    
    // 6. Evaluate performance
    double accuracy = Evaluation::calculateAccuracy(predictions, dataset.getLabels());
    double precision = Evaluation::calculatePrecision(predictions, dataset.getLabels());
    
    std::cout << "Accuracy: " << accuracy << std::endl;
    std::cout << "Precision: " << precision << std::endl;
    
    return 0;
}
```

## Project Information

**Submitted by:**  
- Student Name  
- Roll Number  
- Section  

**Submitted to:** Instructor Hamza Rasheed  
**Course:** Object-Oriented Programming  
**Institution:** University of Central Punjab - Faculty of Information Technology  
**Submission Date:** 10th January 2026

## Future Improvements

🔹 Add support for multi-class classification  
🔹 Implement cross-validation for better model evaluation  
🔹 Add regularization (L1/L2) to prevent overfitting  
🔹 Implement additional ML algorithms (SVM, Decision Trees)  
🔹 Add data visualization capabilities  
🔹 Improve CSV parser to handle missing values and different formats  
🔹 Implement parallel processing for faster training  
🔹 Add serialization for model saving and loading  

## License

This is an academic project for educational purposes.

---

**Note:** This project is part of the Fall 2025 term coursework at the University of Central Punjab. It demonstrates the application of Object-Oriented Programming principles in building a machine learning system from scratch.
