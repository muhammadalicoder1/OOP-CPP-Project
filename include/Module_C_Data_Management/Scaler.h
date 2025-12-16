#ifndef SCALER_H
#define SCALER_H

#include "Matrix.h"

/**
 * @class Scaler
 * @brief Abstract base class for feature scaling
 * 
 * This class demonstrates:
 * - Abstract interface pattern for data transformation
 * - Polymorphism through pure virtual methods
 * - Template Method pattern for scaling operations
 * - Foundation for different scaling strategies
 */
class Scaler {
public:
    // Virtual destructor
    virtual ~Scaler() {}
    
    // Pure virtual methods - must be implemented by derived classes
    virtual void fit(const Matrix& data) = 0;           // Learn scaling parameters
    virtual Matrix transform(const Matrix& data) = 0;   // Apply scaling transformation
    
    // Convenience method combining fit and transform
    virtual Matrix fitTransform(const Matrix& data) {
        fit(data);
        return transform(data);
    }
};

#endif // SCALER_H
