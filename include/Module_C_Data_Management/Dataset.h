#ifndef DATASET_H
#define DATASET_H

#include <string>
#include "Matrix.h"
#include "Vector.h"

/**
 * @class Dataset
 * @brief CSV file handler and data container
 * 
 * This class demonstrates:
 * - File I/O operations for CSV parsing
 * - Encapsulation of data and labels
 * - Data structure management
 * - String manipulation for parsing
 */
class Dataset {
private:
    Matrix features;      // Feature matrix (X)
    Vector labels;        // Label vector (y)
    std::string filename; // Source file path
    int numSamples;       // Number of data samples
    int numFeatures;      // Number of features

public:
    // Constructor
    Dataset();
    Dataset(const std::string& filename);
    
    // Destructor
    ~Dataset();
    
    // File operations
    bool loadCSV(const std::string& filepath);
    
    // Getters
    Matrix getFeatures() const;
    Vector getLabels() const;
    int getNumSamples() const;
    int getNumFeatures() const;
    void getShape() const;  // Display dataset dimensions
    
    // Display methods
    void displayHead(int n = 5) const;  // Show first n rows
    void displayInfo() const;            // Show dataset information
};

#endif // DATASET_H
