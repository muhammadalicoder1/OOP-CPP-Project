#ifndef EVALUATION_H
#define EVALUATION_H

#include "Vector.h"
#include "LogisticRegression.h"

/**
 * @class Evaluation
 * @brief Model evaluation metrics and utilities
 * 
 * This class demonstrates:
 * - Friend class pattern for controlled access to private members
 * - Static methods for utility functions
 * - Encapsulation of evaluation logic
 * - Access to LogisticRegression private members for detailed analysis
 * 
 * Being a friend of LogisticRegression allows this class to:
 * - Access private weights for feature importance analysis
 * - Perform internal model diagnostics
 * - Implement evaluation metrics that need internal model state
 */
class Evaluation {
public:
    // Static evaluation metrics
    static double calculateAccuracy(const Vector& predictions, const Vector& actual);
    static double calculatePrecision(const Vector& predictions, const Vector& actual);
    static double calculateRecall(const Vector& predictions, const Vector& actual);
    static double calculateF1Score(const Vector& predictions, const Vector& actual);
    
    // Confusion matrix components
    static int truePositives(const Vector& predictions, const Vector& actual);
    static int trueNegatives(const Vector& predictions, const Vector& actual);
    static int falsePositives(const Vector& predictions, const Vector& actual);
    static int falseNegatives(const Vector& predictions, const Vector& actual);
    
    // Display confusion matrix
    static void displayConfusionMatrix(const Vector& predictions, const Vector& actual);
    
    // Friend function to access private members of LogisticRegression
    static void analyzeModel(const LogisticRegression& model);
};

#endif // EVALUATION_H
