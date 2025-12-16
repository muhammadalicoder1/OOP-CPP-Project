#ifndef DATASUMMARY_H
#define DATASUMMARY_H

#include "CentralTendency.h"
#include "Dispersion.h"
#include "Matrix.h"

/**
 * @class DataSummary
 * @brief Comprehensive statistical summary using multiple inheritance
 * 
 * This class demonstrates:
 * - Multiple inheritance (from CentralTendency and Dispersion)
 * - Virtual inheritance solution to the Diamond Problem
 * - Only one instance of StatisticalTool base class exists
 * - Combining functionality from multiple base classes
 * 
 * Diamond Problem Visualization:
 *           StatisticalTool
 *           /            \
 *          /              \
 *   CentralTendency    Dispersion
 *          \              /
 *           \            /
 *            DataSummary
 * 
 * Virtual inheritance ensures only one StatisticalTool base
 */
class DataSummary : public CentralTendency, public Dispersion {
public:
    // Constructor
    DataSummary();
    
    // Destructor
    ~DataSummary();
    
    // Generate comprehensive statistical report
    void generateReport(const Matrix& data);
    
    // Display the summary
    void displaySummary() const;
    
    // Implementation of calculate (required by StatisticalTool)
    void calculate() override;
};

#endif // DATASUMMARY_H
