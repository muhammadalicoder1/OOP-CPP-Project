#ifndef MODEL_H
#define MODEL_H

#include "Matrix.h"
#include "Vector.h"

/**
 * @class Model
 * @brief Abstract interface for machine learning models
 * 
 * This class demonstrates:
 * - Interface pattern with pure virtual methods
 * - Polymorphism for different model implementations
 * - Contract definition for all ML models
 * - Dynamic polymorphism through virtual dispatch
 */
class Model {
public:
    // Virtual destructor
    virtual ~Model() {}
    
    // Pure virtual methods - must be implemented by derived classes
    virtual void train(const Matrix& X, const Vector& y) = 0;  // Train the model
    virtual Vector predict(const Matrix& X) = 0;               // Make predictions
    
    // Optional methods with default implementation
    virtual void displayInfo() const {
        std::cout << "Generic Model" << std::endl;
    }
};

#endif // MODEL_H
