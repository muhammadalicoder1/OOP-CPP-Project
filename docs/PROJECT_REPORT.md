# UNIVERSITY OF CENTRAL PUNJAB
## FACULTY OF INFORMATION TECHNOLOGY

---

# PROJECT REPORT

## Titan-Learn: A C++ Logistic Regression Engine

---

**Submitted by:**  
Name: [Student Name]  
Roll Number: [Roll Number]  
Section: [Section]

**Submitted to:**  
Instructor Hamza Rasheed  

**Course:** Object-Oriented Programming  
**Submission Date:** 10th of January, 2026

---

## Table of Contents

1. [Introduction and Problem Statement](#1-introduction-and-problem-statement)
2. [System Architecture](#2-system-architecture)
3. [Feature List](#3-feature-list)
4. [OOP Concepts Used](#4-oop-concepts-used)
5. [UML Diagram Description](#5-uml-diagram-description)
6. [Conclusion & Future Improvements](#6-conclusion--future-improvements)

---

## 1. Introduction and Problem Statement

### 1.1 Introduction

Titan-Learn is a custom-built Machine Learning engine developed entirely in C++ without relying on external ML libraries. This project demonstrates the implementation of a complete logistic regression pipeline from scratch, emphasizing Object-Oriented Programming (OOP) principles and modern C++ practices.

The project serves as an educational tool to understand both the mathematical foundations of machine learning and the practical application of OOP design patterns in building complex software systems.

### 1.2 Problem Statement

The primary objective of this project is to build a machine learning system capable of:

- **Data Loading**: Parse CSV files containing numerical data and labels
- **Statistical Analysis**: Compute descriptive statistics (mean, median, variance, standard deviation)
- **Data Preprocessing**: Normalize features using min-max scaling
- **Model Training**: Implement logistic regression with gradient descent optimization
- **Prediction**: Classify binary outcomes based on learned patterns
- **Evaluation**: Assess model performance using accuracy, precision, recall, and F1 score

All functionality must be implemented from scratch without using external machine learning libraries (such as TensorFlow, PyTorch, scikit-learn equivalents), demonstrating deep understanding of both OOP principles and ML algorithms.

### 1.3 Objectives

1. Implement a robust mathematical foundation using custom Tensor, Matrix, and Vector classes
2. Apply strict OOP principles including encapsulation, inheritance, and polymorphism
3. Demonstrate advanced OOP concepts like virtual inheritance and friend functions
4. Create a modular, maintainable, and extensible codebase
5. Build a functional binary classification system using logistic regression

---

## 2. System Architecture

The project is organized into four main modules, each responsible for specific functionality:

### 2.1 Module A: Mathematical Core

This module provides the foundation for all numerical operations in the system.

#### 2.1.1 Tensor Class
- **Purpose**: Base class for 2D dynamic array management
- **Key Features**:
  - Dynamic memory allocation and deallocation
  - Deep copy semantics (copy constructor and assignment operator)
  - Encapsulation with private data members
  - Virtual destructor for proper inheritance cleanup
- **Memory Management**: Implements proper resource management to prevent memory leaks
- **Design Pattern**: Template for derived classes (Matrix, Vector)

#### 2.1.2 Matrix Class
- **Purpose**: Derived from Tensor, implements matrix operations
- **Key Features**:
  - Operator overloading: `+`, `-`, `*` (dot product), `<<` (stream insertion)
  - Matrix transpose operation
  - Element access with bounds checking
  - Polymorphic display method
- **Mathematical Operations**: Full support for matrix arithmetic required by ML algorithms

#### 2.1.3 Vector Class
- **Purpose**: Specialized 1D array implementation
- **Key Features**:
  - Constructor overloading (default, size-only, with default value)
  - Element access via `[]` operator
  - Statistical operations: sum, mean, max, min
  - Efficient storage using Tensor base class
- **Use Cases**: Feature vectors, label vectors, weight vectors

### 2.2 Module B: Statistical Analysis

This module implements statistical computations using multiple and virtual inheritance.

#### 2.2.1 StatisticalTool (Abstract Base Class)
- **Purpose**: Define interface for all statistical tools
- **Key Features**:
  - Pure virtual `calculate()` method
  - Virtual destructor
  - Foundation for virtual inheritance pattern
- **Design Pattern**: Abstract interface

#### 2.2.2 CentralTendency Class
- **Purpose**: Compute measures of central tendency
- **Key Features**:
  - Virtual inheritance from StatisticalTool
  - Calculate mean and median
  - Protected member variables for derived classes
- **Methods**: `calculateMean()`, `calculateMedian()`

#### 2.2.3 Dispersion Class
- **Purpose**: Compute measures of variability
- **Key Features**:
  - Virtual inheritance from StatisticalTool
  - Calculate variance and standard deviation
  - Protected member variables
- **Methods**: `calculateVariance()`, `calculateStandardDeviation()`

#### 2.2.4 DataSummary Class
- **Purpose**: Comprehensive statistical reporting
- **Key Features**:
  - Multiple inheritance from CentralTendency and Dispersion
  - Virtual inheritance solves the Diamond Problem
  - Only one StatisticalTool base instance exists
  - Generate complete statistical reports
- **Diamond Problem Solution**: Uses virtual inheritance to ensure single base class instance

**Inheritance Diagram:**
```
        StatisticalTool
        /             \
   (virtual)       (virtual)
      /                 \
CentralTendency     Dispersion
      \                 /
       \               /
         DataSummary
```

### 2.3 Module C: Data Management

This module handles data loading, storage, and preprocessing.

#### 2.3.1 Dataset Class
- **Purpose**: CSV file parser and data container
- **Key Features**:
  - File I/O operations
  - String parsing for CSV format
  - Separate storage for features and labels
  - Display methods for data inspection
- **Methods**: `loadCSV()`, `getFeatures()`, `getLabels()`, `getShape()`, `displayHead()`

#### 2.3.2 Scaler (Abstract Base Class)
- **Purpose**: Define interface for feature scaling
- **Key Features**:
  - Pure virtual methods: `fit()`, `transform()`
  - Template Method pattern with `fitTransform()`
  - Foundation for different scaling strategies
- **Design Pattern**: Abstract interface for polymorphism

#### 2.3.3 MinMaxScaler Class
- **Purpose**: Normalize features to [0, 1] range
- **Key Features**:
  - Inheritance from Scaler
  - Learn min/max values during fit
  - Apply scaling transformation
  - Prevent division by zero
- **Formula**: `X_scaled = (X - X_min) / (X_max - X_min)`

### 2.4 Module D: Model

This module implements the machine learning model and evaluation tools.

#### 2.4.1 Model (Abstract Interface)
- **Purpose**: Define interface for all ML models
- **Key Features**:
  - Pure virtual methods: `train()`, `predict()`
  - Virtual destructor
  - Optional `displayInfo()` with default implementation
- **Design Pattern**: Interface for polymorphism

#### 2.4.2 LogisticRegression Class
- **Purpose**: Binary classification using logistic regression
- **Key Features**:
  - Inheritance from Model interface
  - Sigmoid activation function
  - Gradient descent optimization
  - Encapsulated weights (private)
  - Friend class (Evaluation) for model analysis
- **Mathematical Foundation**:
  - Sigmoid: `σ(z) = 1 / (1 + e^(-z))`
  - Cost function: `J(θ) = -1/m * Σ[y*log(h) + (1-y)*log(1-h)]`
  - Gradient: `∇J(θ) = 1/m * X^T * (h - y)`

#### 2.4.3 Evaluation Class
- **Purpose**: Model performance evaluation
- **Key Features**:
  - Friend of LogisticRegression
  - Static methods for metrics
  - Access to private model members
  - Confusion matrix display
- **Metrics**: Accuracy, Precision, Recall, F1 Score
- **Friend Function**: `analyzeModel()` accesses private weights

---

## 3. Feature List

### 3.1 Data Processing Features

✅ **Custom CSV Parser**
- No external libraries required
- Handles comma-separated values
- Skips header row
- Error handling for malformed data

✅ **Automated Statistical Report**
- Mean, median, variance, standard deviation
- Min and max values
- Per-feature analysis
- Formatted output display

✅ **Feature Scaling**
- Min-max normalization to [0, 1]
- Learn parameters from training data
- Apply transformation consistently
- Handle edge cases (constant features)

### 3.2 Mathematical Operations

✅ **Matrix Arithmetic Engine**
- Matrix addition and subtraction
- Matrix multiplication (dot product)
- Matrix transpose
- Operator overloading for intuitive syntax

✅ **Vector Operations**
- Element-wise access
- Statistical computations
- Sum, mean, max, min functions
- Constructor overloading

### 3.3 Machine Learning Features

✅ **Training Loop with Gradient Descent**
- Iterative weight updates
- Configurable learning rate and epochs
- Loss tracking during training
- Binary cross-entropy loss function

✅ **Binary Classification Prediction System**
- Sigmoid activation for probabilities
- Threshold-based classification (0.5)
- Batch prediction support
- Probability output option

✅ **Model Evaluation**
- Accuracy calculation
- Precision and recall
- F1 score
- Confusion matrix display
- Model parameter analysis (via friend function)

### 3.4 Software Engineering Features

✅ **Proper Memory Management**
- Dynamic memory allocation
- Deep copy semantics
- Destructor cleanup
- No memory leaks

✅ **Error Handling**
- Dimension mismatch checks
- Bounds checking for array access
- Meaningful error messages
- Exception throwing and catching

✅ **Modular Design**
- Four independent modules
- Clear separation of concerns
- Reusable components
- Extensible architecture

---

## 4. OOP Concepts Used

### 4.1 Encapsulation

**Definition**: Bundling data and methods that operate on that data within a single unit (class), while hiding internal implementation details.

**Implementation in Project**:

1. **Tensor Class**:
   ```cpp
   class Tensor {
   private:
       double** data;  // Hidden from external access
       int rows, cols;
   protected:
       void allocateMemory(int r, int c);
   public:
       double getValue(int row, int col) const;
       void setValue(int row, int col, double value);
   };
   ```
   - Private data members prevent direct access
   - Public methods provide controlled interface
   - Protected helpers available to derived classes

2. **LogisticRegression Class**:
   ```cpp
   class LogisticRegression : public Model {
   private:
       Vector weights;
       double bias;
       double learningRate;
   public:
       void train(const Matrix& X, const Vector& y) override;
       Vector predict(const Matrix& X) override;
   };
   ```
   - Private weights ensure model integrity
   - Training algorithm hidden from users
   - Public interface for training and prediction

**Benefits**:
- Data protection
- Implementation flexibility
- Interface stability
- Reduced complexity for users

### 4.2 Operator Overloading

**Definition**: Giving special meaning to operators when they operate on user-defined types.

**Implementation in Project**:

1. **Matrix Arithmetic Operators**:
   ```cpp
   Matrix operator+(const Matrix& other) const;  // Matrix addition
   Matrix operator-(const Matrix& other) const;  // Matrix subtraction
   Matrix operator*(const Matrix& other) const;  // Matrix multiplication
   ```
   - Natural mathematical syntax: `C = A * B`
   - Dimension checking included
   - Returns new Matrix (immutable operation)

2. **Stream Insertion Operator**:
   ```cpp
   friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
   ```
   - Usage: `std::cout << matrix;`
   - Friend function for accessing private members
   - Formatted output

3. **Vector Element Access**:
   ```cpp
   double& operator[](int index);
   const double& operator[](int index) const;
   ```
   - Array-like syntax: `vector[i] = 5.0;`
   - Const overload for read-only access
   - Bounds checking included

**Benefits**:
- Intuitive syntax
- Code readability
- Mathematical elegance

### 4.3 Deep Copying

**Definition**: Creating a new object with its own copy of dynamically allocated resources.

**Implementation in Project**:

1. **Copy Constructor**:
   ```cpp
   Tensor::Tensor(const Tensor& other) : rows(other.rows), cols(other.cols) {
       allocateMemory(rows, cols);
       copyData(other);  // Deep copy of data
   }
   ```

2. **Assignment Operator**:
   ```cpp
   Tensor& Tensor::operator=(const Tensor& other) {
       if (this != &other) {
           deallocateMemory();      // Clean up existing resources
           rows = other.rows;
           cols = other.cols;
           allocateMemory(rows, cols);
           copyData(other);          // Deep copy
       }
       return *this;
   }
   ```

**Why Deep Copy is Essential**:
- Prevents shallow copy problems (double deletion, data corruption)
- Each object owns its resources
- Safe object assignment and passing
- Proper memory management

### 4.4 Polymorphism

**Definition**: Ability of objects to take multiple forms, allowing different implementations through a common interface.

#### 4.4.1 Dynamic Polymorphism (Runtime)

**Model Interface**:
```cpp
class Model {
public:
    virtual ~Model() {}
    virtual void train(const Matrix& X, const Vector& y) = 0;
    virtual Vector predict(const Matrix& X) = 0;
};

class LogisticRegression : public Model {
public:
    void train(const Matrix& X, const Vector& y) override;
    Vector predict(const Matrix& X) override;
};
```

**Usage**:
```cpp
Model* model = new LogisticRegression(0.01, 1000);
model->train(X, y);  // Calls LogisticRegression::train()
Vector predictions = model->predict(X);  // Runtime dispatch
```

#### 4.4.2 Static Polymorphism (Compile-time)

**Constructor Overloading in Vector**:
```cpp
class Vector : public Tensor {
public:
    Vector();                              // Default
    Vector(int size);                      // Size only
    Vector(int size, double defaultValue); // Size with default
    Vector(const Vector& other);           // Copy constructor
};
```

**Usage**:
```cpp
Vector v1;              // Default constructor
Vector v2(10);          // Creates vector of size 10
Vector v3(10, 5.0);     // Size 10, all elements = 5.0
Vector v4(v2);          // Copy constructor
```

**Benefits**:
- Code reusability
- Extensibility
- Interface uniformity

### 4.5 Inheritance

#### 4.5.1 Single Inheritance

**Example**: LogisticRegression inherits from Model
```cpp
class Model { /* ... */ };
class LogisticRegression : public Model { /* ... */ };
```

#### 4.5.2 Multi-level Inheritance

**Example**: Vector inherits from Tensor (which could have its own base)
```cpp
class Tensor { /* ... */ };
class Vector : public Tensor { /* ... */ };
```

#### 4.5.3 Multiple Inheritance

**Example**: DataSummary inherits from both CentralTendency and Dispersion
```cpp
class DataSummary : public CentralTendency, public Dispersion {
    // Combines functionality from both base classes
};
```

**Benefits of Inheritance**:
- Code reuse
- Hierarchical organization
- Polymorphic behavior
- IS-A relationships

### 4.6 Virtual Inheritance

**Problem: The Diamond Problem**

Without virtual inheritance:
```
      StatisticalTool
      /             \
CentralTendency   Dispersion
      \             /
       DataSummary
```
Result: Two instances of StatisticalTool in DataSummary (ambiguous)

**Solution: Virtual Inheritance**

```cpp
class CentralTendency : virtual public StatisticalTool { /* ... */ };
class Dispersion : virtual public StatisticalTool { /* ... */ };
class DataSummary : public CentralTendency, public Dispersion { /* ... */ };
```

Result: Only one instance of StatisticalTool (no ambiguity)

**Benefits**:
- Solves ambiguity in multiple inheritance
- Single base class instance
- Efficient memory usage
- Clear inheritance hierarchy

### 4.7 Friend Functions

**Definition**: Non-member functions that have access to private and protected members of a class.

**Implementation in Project**:

```cpp
class LogisticRegression : public Model {
private:
    Vector weights;
    double bias;
    
    friend class Evaluation;  // Grant access to Evaluation
};

class Evaluation {
public:
    static void analyzeModel(const LogisticRegression& model) {
        // Can access model.weights and model.bias directly
        std::cout << "Bias: " << model.bias << std::endl;
    }
};
```

**Use Case**: Model Analysis
- Evaluation needs access to private weights
- Maintains encapsulation for other classes
- Controlled violation of information hiding

**Benefits**:
- Fine-grained access control
- Maintains encapsulation elsewhere
- Cleaner API design

---

## 5. UML Diagram Description

### 5.1 Module A: Mathematical Core

```
┌─────────────┐
│   Tensor    │ (Base Class)
├─────────────┤
│ - data**    │
│ - rows      │
│ - cols      │
├─────────────┤
│ + Tensor()  │
│ + ~Tensor() │
│ + getValue()│
│ + setValue()│
└──────┬──────┘
       │
       ├──────────┬──────────┐
       │          │          │
   ┌───▼────┐ ┌──▼─────┐    │
   │ Matrix │ │ Vector │    │
   └────────┘ └────────┘    │
```

**Relationships**:
- Matrix inherits from Tensor
- Vector inherits from Tensor
- Both use Tensor's memory management

### 5.2 Module B: Statistical Analysis

```
┌───────────────────┐
│ StatisticalTool   │ (Abstract)
├───────────────────┤
│ + calculate() = 0 │
└─────────┬─────────┘
          │ (virtual inheritance)
    ┌─────┴─────┐
    │           │
┌───▼────────┐ ┌▼─────────┐
│Central-    │ │Dispersion│
│Tendency    │ │          │
└────┬───────┘ └─────┬────┘
     │               │
     └───────┬───────┘
         ┌───▼────────┐
         │DataSummary │
         └────────────┘
```

**Relationships**:
- Virtual inheritance prevents diamond problem
- DataSummary has access to both base classes
- Only one StatisticalTool instance

### 5.3 Module C: Data Management

```
┌──────────┐     ┌─────────┐
│ Dataset  │     │ Scaler  │ (Abstract)
└──────────┘     └────┬────┘
                      │
                 ┌────▼────────┐
                 │MinMaxScaler │
                 └─────────────┘
```

**Relationships**:
- Dataset is standalone
- MinMaxScaler implements Scaler interface

### 5.4 Module D: Model

```
┌───────────┐
│   Model   │ (Abstract)
└─────┬─────┘
      │
┌─────▼──────────────┐     ┌─────────────┐
│LogisticRegression  │◄────│ Evaluation  │
└────────────────────┘     └─────────────┘
        friend                (Friend Class)
```

**Relationships**:
- LogisticRegression implements Model interface
- Evaluation is friend of LogisticRegression
- Friend relationship for private access

---

## 6. Conclusion & Future Improvements

### 6.1 Conclusion

This project successfully demonstrates the implementation of a complete machine learning pipeline using pure C++ without external ML libraries. Through the development of Titan-Learn, we have:

1. **Achieved Technical Goals**:
   - Built a functional logistic regression engine from scratch
   - Implemented mathematical operations (Matrix, Vector) with proper memory management
   - Created a statistical analysis framework using multiple inheritance
   - Developed data preprocessing tools (CSV parser, feature scaler)
   - Achieved model training and evaluation capabilities

2. **Demonstrated OOP Mastery**:
   - Applied all major OOP concepts: encapsulation, inheritance, polymorphism
   - Solved the Diamond Problem using virtual inheritance
   - Implemented operator overloading for mathematical elegance
   - Used friend functions for controlled access
   - Maintained proper memory management with deep copying

3. **Educational Value**:
   - Deepened understanding of ML algorithms by implementing from scratch
   - Practiced software engineering principles (modularity, separation of concerns)
   - Gained experience with C++ memory management
   - Learned to balance abstraction with performance

### 6.2 Achievements

- ✅ 12 well-designed classes across 4 modules
- ✅ Compile-ready code with proper CMake configuration
- ✅ Comprehensive documentation and comments
- ✅ Working binary classification system
- ✅ Statistical analysis capabilities
- ✅ Extensible architecture for future enhancements

### 6.3 Future Improvements

#### Short-term Enhancements

1. **Multi-class Classification**
   - Extend to softmax regression
   - One-vs-rest strategy
   - Confusion matrix for multiple classes

2. **Cross-validation**
   - K-fold cross-validation
   - Train/test split functionality
   - Validation set support

3. **Additional Metrics**
   - ROC curve and AUC
   - Matthews correlation coefficient
   - Cohen's kappa

#### Medium-term Enhancements

4. **Regularization**
   - L1 regularization (Lasso)
   - L2 regularization (Ridge)
   - Elastic Net
   - Help prevent overfitting

5. **Optimization Algorithms**
   - Stochastic Gradient Descent (SGD)
   - Mini-batch gradient descent
   - Adam optimizer
   - Learning rate scheduling

6. **Feature Engineering**
   - Polynomial features
   - Feature selection
   - PCA for dimensionality reduction

#### Long-term Enhancements

7. **Additional ML Algorithms**
   - Support Vector Machines (SVM)
   - Decision Trees
   - Random Forests
   - K-Nearest Neighbors (KNN)
   - Neural Networks

8. **Data Visualization**
   - Plot training loss curves
   - Decision boundary visualization
   - Feature importance plots
   - Correlation matrices

9. **Performance Optimization**
   - Parallel processing with OpenMP
   - SIMD instructions for matrix operations
   - GPU acceleration (CUDA)
   - Memory pool for allocation

10. **Serialization**
    - Save trained models to disk
    - Load pre-trained models
    - JSON/Binary format support
    - Model versioning

#### Advanced Features

11. **Data Handling**
    - Handle missing values (imputation)
    - Categorical feature encoding
    - Data augmentation
    - Online learning support

12. **Model Interpretability**
    - SHAP values
    - Feature importance ranking
    - Partial dependence plots
    - Local interpretable model explanations

### 6.4 Lessons Learned

1. **Memory Management**: Deep understanding of resource management is crucial in C++
2. **Design Patterns**: Abstract interfaces and inheritance hierarchies improve code organization
3. **Documentation**: Well-commented code is essential for maintenance and collaboration
4. **Testing**: Incremental testing during development catches bugs early
5. **Modularity**: Separating concerns into modules makes the codebase manageable

### 6.5 Final Remarks

Titan-Learn represents a comprehensive demonstration of Object-Oriented Programming principles applied to a real-world problem domain. The project not only implements a functional machine learning system but also serves as an educational resource for understanding both OOP concepts and ML algorithms.

The modular architecture ensures that the codebase can be extended with new features and algorithms in the future, making it a solid foundation for continued learning and development in both C++ programming and machine learning.

---

## References

1. Bishop, C. M. (2006). *Pattern Recognition and Machine Learning*. Springer.
2. Stroustrup, B. (2013). *The C++ Programming Language* (4th ed.). Addison-Wesley.
3. Goodfellow, I., Bengio, Y., & Courville, A. (2016). *Deep Learning*. MIT Press.
4. Meyers, S. (2014). *Effective Modern C++*. O'Reilly Media.

---

**End of Report**
