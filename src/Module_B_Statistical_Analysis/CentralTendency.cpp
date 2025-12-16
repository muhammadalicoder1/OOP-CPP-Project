#include "CentralTendency.h"
#include <algorithm>
#include <vector>
#include <iostream>

// Constructor
CentralTendency::CentralTendency() : mean(0.0), median(0.0) {}

// Destructor
CentralTendency::~CentralTendency() {}

// Calculate mean
double CentralTendency::calculateMean(const Vector& data) {
    int n = data.getSize();
    if (n == 0) {
        mean = 0.0;
        return mean;
    }
    
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    mean = sum / n;
    return mean;
}

// Calculate median
double CentralTendency::calculateMedian(const Vector& data) {
    int n = data.getSize();
    if (n == 0) {
        median = 0.0;
        return median;
    }
    
    // Copy data to a vector for sorting
    std::vector<double> values;
    for (int i = 0; i < n; i++) {
        values.push_back(data[i]);
    }
    
    // Sort the values
    std::sort(values.begin(), values.end());
    
    // Calculate median
    if (n % 2 == 0) {
        // Even number of elements - average of middle two
        median = (values[n/2 - 1] + values[n/2]) / 2.0;
    } else {
        // Odd number of elements - middle element
        median = values[n/2];
    }
    
    return median;
}

// Implementation of pure virtual method
void CentralTendency::calculate() {
    // This is a placeholder - actual calculation done in specific methods
    std::cout << "Calculating central tendency measures..." << std::endl;
}

// Getters
double CentralTendency::getMean() const {
    return mean;
}

double CentralTendency::getMedian() const {
    return median;
}
