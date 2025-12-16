#ifndef LOGISTICREGRESSION_H
#define LOGISTICREGRESSION_H

#include "Model.h"
#include "Matrix.h"
#include "Vector.h"

// Forward declaration for friend class
class Evaluation;

/**
 * @class LogisticRegression
 * @brief Binary classification using logistic regression
 * 
 * This class demonstrates:
 * - Inheritance from Model interface
 * - Implementation of pure virtual methods
 * - Encapsulation of model parameters (private weights)
 * - Friend class (Evaluation) for controlled access
 * - Gradient descent optimization algorithm
 * 
 * Mathematical foundation:
 * - Sigmoid function: σ(z) = 1 / (1 + e^(-z))
 * - Cost function: J(θ) = -1/m * Σ[y*log(h) + (1-y)*log(1-h)]
 * - Gradient: ∇J(θ) = 1/m * X^T * (h - y)
 */
class LogisticRegression : public Model {
private:
    Vector weights;         // Model weights (parameters)
    double bias;            // Bias term
    double learningRate;    // Learning rate for gradient descent
    int epochs;             // Number of training iterations
    bool isTrained;         // Training status flag
    
    // Private helper methods
    double sigmoid(double z) const;              // Sigmoid activation function
    Vector sigmoidVector(const Vector& z) const; // Apply sigmoid to vector
    
public:
    // Constructors
    LogisticRegression();
    LogisticRegression(double lr, int numEpochs);
    
    // Destructor
    ~LogisticRegression();
    
    // Implementation of Model interface
    void train(const Matrix& X, const Vector& y) override;
    Vector predict(const Matrix& X) override;
    
    // Additional methods
    Vector predictProba(const Matrix& X);  // Get probability predictions
    void displayInfo() const override;
    
    // Getters
    Vector getWeights() const;
    double getBias() const;
    double getLearningRate() const;
    int getEpochs() const;
    bool getIsTrained() const;
    
    // Setters
    void setLearningRate(double lr);
    void setEpochs(int numEpochs);
    
    // Friend class declaration
    friend class Evaluation;  // Evaluation can access private members
};

#endif // LOGISTICREGRESSION_H
