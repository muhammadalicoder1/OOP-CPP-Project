#include "DataSummary.h"
#include <iostream>
#include <iomanip>

// Constructor
DataSummary::DataSummary() : CentralTendency(), Dispersion() {}

// Destructor
DataSummary::~DataSummary() {}

// Generate comprehensive statistical report
void DataSummary::generateReport(const Matrix& data) {
    std::cout << "\n========== STATISTICAL SUMMARY REPORT ==========" << std::endl;
    std::cout << "Dataset dimensions: " << data.getRows() << " rows x " 
              << data.getCols() << " columns" << std::endl;
    std::cout << "================================================\n" << std::endl;
    
    // Calculate statistics for each column (feature)
    for (int col = 0; col < data.getCols(); col++) {
        std::cout << "Feature " << (col + 1) << " Statistics:" << std::endl;
        std::cout << "----------------------------------------" << std::endl;
        
        // Extract column data into a vector
        Vector columnData(data.getRows());
        for (int row = 0; row < data.getRows(); row++) {
            columnData[row] = data.getValue(row, col);
        }
        
        // Calculate central tendency
        double meanVal = calculateMean(columnData);
        double medianVal = calculateMedian(columnData);
        
        // Calculate dispersion
        double varianceVal = calculateVariance(columnData, meanVal);
        double stdDevVal = calculateStandardDeviation(columnData, meanVal);
        
        // Get min and max
        double minVal = columnData.min();
        double maxVal = columnData.max();
        
        // Display results
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "  Count:              " << columnData.getSize() << std::endl;
        std::cout << "  Mean:               " << meanVal << std::endl;
        std::cout << "  Median:             " << medianVal << std::endl;
        std::cout << "  Std Deviation:      " << stdDevVal << std::endl;
        std::cout << "  Variance:           " << varianceVal << std::endl;
        std::cout << "  Min:                " << minVal << std::endl;
        std::cout << "  Max:                " << maxVal << std::endl;
        std::cout << std::endl;
    }
    
    std::cout << "================================================\n" << std::endl;
}

// Display the summary
void DataSummary::displaySummary() const {
    std::cout << "Summary Statistics:" << std::endl;
    std::cout << "  Mean: " << getMean() << std::endl;
    std::cout << "  Median: " << getMedian() << std::endl;
    std::cout << "  Variance: " << getVariance() << std::endl;
    std::cout << "  Standard Deviation: " << getStandardDeviation() << std::endl;
}

// Implementation of calculate method
void DataSummary::calculate() {
    std::cout << "Performing comprehensive statistical analysis..." << std::endl;
    // Both base class implementations are available through virtual inheritance
    CentralTendency::calculate();
    Dispersion::calculate();
}
