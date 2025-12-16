#include "Dataset.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

// Constructor
Dataset::Dataset() : numSamples(0), numFeatures(0), filename("") {}

Dataset::Dataset(const std::string& filepath) : numSamples(0), numFeatures(0) {
    loadCSV(filepath);
}

// Destructor
Dataset::~Dataset() {}

// Load CSV file
bool Dataset::loadCSV(const std::string& filepath) {
    filename = filepath;
    std::ifstream file(filepath);
    
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filepath << std::endl;
        return false;
    }
    
    std::string line;
    std::vector<std::vector<double>> tempData;
    std::vector<double> tempLabels;
    bool firstLine = true;
    
    while (std::getline(file, line)) {
        // Skip header line
        if (firstLine) {
            firstLine = false;
            continue;
        }
        
        std::stringstream ss(line);
        std::string value;
        std::vector<double> row;
        
        // Parse comma-separated values
        while (std::getline(ss, value, ',')) {
            try {
                row.push_back(std::stod(value));
            } catch (const std::exception& e) {
                std::cerr << "Error parsing value: " << value << std::endl;
                continue;
            }
        }
        
        if (!row.empty()) {
            // Last column is the label
            tempLabels.push_back(row.back());
            row.pop_back();
            
            // Remaining columns are features
            if (!row.empty()) {
                tempData.push_back(row);
            }
        }
    }
    
    file.close();
    
    // Convert to Matrix and Vector
    numSamples = tempData.size();
    if (numSamples > 0) {
        numFeatures = tempData[0].size();
        
        // Create feature matrix
        features = Matrix(numSamples, numFeatures);
        for (int i = 0; i < numSamples; i++) {
            for (int j = 0; j < numFeatures; j++) {
                features.setValue(i, j, tempData[i][j]);
            }
        }
        
        // Create label vector
        labels = Vector(numSamples);
        for (int i = 0; i < numSamples; i++) {
            labels[i] = tempLabels[i];
        }
        
        std::cout << "Successfully loaded " << numSamples << " samples with " 
                  << numFeatures << " features" << std::endl;
        return true;
    }
    
    return false;
}

// Getters
Matrix Dataset::getFeatures() const {
    return features;
}

Vector Dataset::getLabels() const {
    return labels;
}

int Dataset::getNumSamples() const {
    return numSamples;
}

int Dataset::getNumFeatures() const {
    return numFeatures;
}

void Dataset::getShape() const {
    std::cout << "Dataset shape: (" << numSamples << ", " << numFeatures << ")" << std::endl;
}

// Display first n rows
void Dataset::displayHead(int n) const {
    std::cout << "\nFirst " << n << " rows of dataset:" << std::endl;
    std::cout << "Features:\n";
    for (int i = 0; i < std::min(n, numSamples); i++) {
        std::cout << "Row " << i << ": ";
        for (int j = 0; j < numFeatures; j++) {
            std::cout << features.getValue(i, j) << " ";
        }
        std::cout << "| Label: " << labels[i] << std::endl;
    }
    std::cout << std::endl;
}

// Display dataset information
void Dataset::displayInfo() const {
    std::cout << "\n========== DATASET INFORMATION ==========" << std::endl;
    std::cout << "File: " << filename << std::endl;
    std::cout << "Number of samples: " << numSamples << std::endl;
    std::cout << "Number of features: " << numFeatures << std::endl;
    std::cout << "========================================\n" << std::endl;
}
