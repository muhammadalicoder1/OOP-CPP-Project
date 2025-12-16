#ifndef MINMAXSCALER_H
#define MINMAXSCALER_H

#include "Scaler.h"
#include "Vector.h"

/**
 * @class MinMaxScaler
 * @brief Scales features to a fixed range [0, 1]
 * 
 * This class demonstrates:
 * - Inheritance from abstract Scaler class
 * - Implementation of pure virtual methods
 * - Polymorphism in action
 * - Feature normalization algorithm
 * 
 * Formula: X_scaled = (X - X_min) / (X_max - X_min)
 */
class MinMaxScaler : public Scaler {
private:
    Vector minValues;  // Minimum value for each feature
    Vector maxValues;  // Maximum value for each feature
    bool isFitted;     // Flag to check if scaler has been fitted

public:
    // Constructor
    MinMaxScaler();
    
    // Destructor
    ~MinMaxScaler();
    
    // Implementation of pure virtual methods
    void fit(const Matrix& data) override;           // Learn min and max values
    Matrix transform(const Matrix& data) override;   // Apply min-max scaling
    
    // Getters
    Vector getMinValues() const;
    Vector getMaxValues() const;
    bool getIsFitted() const;
};

#endif // MINMAXSCALER_H
