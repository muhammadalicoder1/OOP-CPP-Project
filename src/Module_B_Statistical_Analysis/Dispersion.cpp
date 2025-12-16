#include "Dispersion.h"
#include <cmath>
#include <iostream>

// Constructor
Dispersion::Dispersion() : variance(0.0), standardDeviation(0.0) {}

// Destructor
Dispersion::~Dispersion() {}

// Calculate variance
double Dispersion::calculateVariance(const Vector& data, double mean) {
    int n = data.getSize();
    if (n == 0) {
        variance = 0.0;
        return variance;
    }
    
    double sumSquaredDiff = 0.0;
    for (int i = 0; i < n; i++) {
        double diff = data[i] - mean;
        sumSquaredDiff += diff * diff;
    }
    
    variance = sumSquaredDiff / n;
    return variance;
}

// Calculate standard deviation
double Dispersion::calculateStandardDeviation(const Vector& data, double mean) {
    variance = calculateVariance(data, mean);
    standardDeviation = std::sqrt(variance);
    return standardDeviation;
}

// Implementation of pure virtual method
void Dispersion::calculate() {
    // This is a placeholder - actual calculation done in specific methods
    std::cout << "Calculating dispersion measures..." << std::endl;
}

// Getters
double Dispersion::getVariance() const {
    return variance;
}

double Dispersion::getStandardDeviation() const {
    return standardDeviation;
}
