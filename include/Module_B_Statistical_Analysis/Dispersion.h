#ifndef DISPERSION_H
#define DISPERSION_H

#include "StatisticalTool.h"
#include "Vector.h"

/**
 * @class Dispersion
 * @brief Calculates measures of dispersion
 * 
 * This class demonstrates:
 * - Virtual inheritance from StatisticalTool (to prevent diamond problem)
 * - Implementation of variability measures (variance, standard deviation)
 * - Part of multiple inheritance hierarchy in DataSummary
 */
class Dispersion : virtual public StatisticalTool {
protected:
    double variance;
    double standardDeviation;

public:
    // Constructor
    Dispersion();
    
    // Destructor
    virtual ~Dispersion();
    
    // Statistical calculations
    double calculateVariance(const Vector& data, double mean);
    double calculateStandardDeviation(const Vector& data, double mean);
    
    // Implementation of pure virtual method
    void calculate() override;
    
    // Getters
    double getVariance() const;
    double getStandardDeviation() const;
};

#endif // DISPERSION_H
