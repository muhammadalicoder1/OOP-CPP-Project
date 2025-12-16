#ifndef CENTRALTENDENCY_H
#define CENTRALTENDENCY_H

#include "StatisticalTool.h"
#include "Vector.h"
#include <vector>

/**
 * @class CentralTendency
 * @brief Calculates measures of central tendency
 * 
 * This class demonstrates:
 * - Virtual inheritance from StatisticalTool (to prevent diamond problem)
 * - Implementation of statistical measures (mean, median)
 * - Part of multiple inheritance hierarchy in DataSummary
 */
class CentralTendency : virtual public StatisticalTool {
protected:
    double mean;
    double median;

public:
    // Constructor
    CentralTendency();
    
    // Destructor
    virtual ~CentralTendency();
    
    // Statistical calculations
    double calculateMean(const Vector& data);
    double calculateMedian(const Vector& data);
    
    // Implementation of pure virtual method
    void calculate() override;
    
    // Getters
    double getMean() const;
    double getMedian() const;
};

#endif // CENTRALTENDENCY_H
