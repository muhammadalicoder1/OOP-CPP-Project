#ifndef STATISTICALTOOL_H
#define STATISTICALTOOL_H

#include "Matrix.h"

/**
 * @class StatisticalTool
 * @brief Abstract base class for statistical operations
 * 
 * This class demonstrates:
 * - Abstract base class pattern with pure virtual methods
 * - Interface definition for statistical tools
 * - Foundation for virtual inheritance (to solve diamond problem)
 */
class StatisticalTool {
public:
    // Virtual destructor for proper cleanup in inheritance hierarchy
    virtual ~StatisticalTool() {}
    
    // Pure virtual method - must be implemented by derived classes
    virtual void calculate() = 0;
};

#endif // STATISTICALTOOL_H
