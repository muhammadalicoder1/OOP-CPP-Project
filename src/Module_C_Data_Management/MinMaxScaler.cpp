#include "MinMaxScaler.h"
#include <iostream>
#include <stdexcept>

// Constructor
MinMaxScaler::MinMaxScaler() : isFitted(false) {}

// Destructor
MinMaxScaler::~MinMaxScaler() {}

// Fit method - learn min and max values for each feature
void MinMaxScaler::fit(const Matrix& data) {
    int numFeatures = data.getCols();
    int numSamples = data.getRows();
    
    if (numSamples == 0 || numFeatures == 0) {
        throw std::invalid_argument("Cannot fit scaler on empty data");
    }
    
    // Initialize min and max vectors
    minValues = Vector(numFeatures);
    maxValues = Vector(numFeatures);
    
    // Find min and max for each feature (column)
    for (int col = 0; col < numFeatures; col++) {
        double minVal = data.getValue(0, col);
        double maxVal = data.getValue(0, col);
        
        for (int row = 1; row < numSamples; row++) {
            double value = data.getValue(row, col);
            if (value < minVal) minVal = value;
            if (value > maxVal) maxVal = value;
        }
        
        minValues[col] = minVal;
        maxValues[col] = maxVal;
    }
    
    isFitted = true;
    std::cout << "MinMaxScaler fitted successfully" << std::endl;
}

// Transform method - apply min-max scaling
Matrix MinMaxScaler::transform(const Matrix& data) {
    if (!isFitted) {
        throw std::runtime_error("Scaler must be fitted before transform");
    }
    
    int numSamples = data.getRows();
    int numFeatures = data.getCols();
    
    if (numFeatures != minValues.getSize()) {
        throw std::invalid_argument("Number of features must match fitted data");
    }
    
    Matrix scaled(numSamples, numFeatures);
    
    // Apply min-max scaling: X_scaled = (X - X_min) / (X_max - X_min)
    for (int row = 0; row < numSamples; row++) {
        for (int col = 0; col < numFeatures; col++) {
            double value = data.getValue(row, col);
            double minVal = minValues[col];
            double maxVal = maxValues[col];
            
            // Avoid division by zero
            if (maxVal - minVal > 1e-10) {
                double scaledValue = (value - minVal) / (maxVal - minVal);
                scaled.setValue(row, col, scaledValue);
            } else {
                // If all values are the same, set to 0.5
                scaled.setValue(row, col, 0.5);
            }
        }
    }
    
    std::cout << "Data transformed successfully" << std::endl;
    return scaled;
}

// Getters
Vector MinMaxScaler::getMinValues() const {
    return minValues;
}

Vector MinMaxScaler::getMaxValues() const {
    return maxValues;
}

bool MinMaxScaler::getIsFitted() const {
    return isFitted;
}
