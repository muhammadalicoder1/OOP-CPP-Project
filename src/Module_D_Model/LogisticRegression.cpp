#include "LogisticRegression.h"
#include <cmath>
#include <iostream>
#include <iomanip>

// Default constructor
LogisticRegression::LogisticRegression() 
    : bias(0.0), learningRate(0.01), epochs(1000), isTrained(false) {}

// Parameterized constructor
LogisticRegression::LogisticRegression(double lr, int numEpochs)
    : bias(0.0), learningRate(lr), epochs(numEpochs), isTrained(false) {}

// Destructor
LogisticRegression::~LogisticRegression() {}

// Sigmoid activation function
double LogisticRegression::sigmoid(double z) const {
    // Clip z to prevent overflow
    if (z > 500) z = 500;
    if (z < -500) z = -500;
    return 1.0 / (1.0 + std::exp(-z));
}

// Apply sigmoid to vector
Vector LogisticRegression::sigmoidVector(const Vector& z) const {
    Vector result(z.getSize());
    for (int i = 0; i < z.getSize(); i++) {
        result[i] = sigmoid(z[i]);
    }
    return result;
}

// Train the model using gradient descent
void LogisticRegression::train(const Matrix& X, const Vector& y) {
    int numSamples = X.getRows();
    int numFeatures = X.getCols();
    
    if (numSamples != y.getSize()) {
        throw std::invalid_argument("Number of samples must match labels");
    }
    
    // Initialize weights
    weights = Vector(numFeatures, 0.0);
    bias = 0.0;
    
    std::cout << "\n========== TRAINING LOGISTIC REGRESSION ==========" << std::endl;
    std::cout << "Samples: " << numSamples << ", Features: " << numFeatures << std::endl;
    std::cout << "Learning Rate: " << learningRate << ", Epochs: " << epochs << std::endl;
    std::cout << "==================================================\n" << std::endl;
    
    // Gradient descent
    for (int epoch = 0; epoch < epochs; epoch++) {
        // Forward pass: compute predictions
        Vector predictions(numSamples);
        for (int i = 0; i < numSamples; i++) {
            double z = bias;
            for (int j = 0; j < numFeatures; j++) {
                z += weights[j] * X.getValue(i, j);
            }
            predictions[i] = sigmoid(z);
        }
        
        // Compute gradients
        Vector dw(numFeatures, 0.0);
        double db = 0.0;
        
        for (int i = 0; i < numSamples; i++) {
            double error = predictions[i] - y[i];
            db += error;
            for (int j = 0; j < numFeatures; j++) {
                dw[j] += error * X.getValue(i, j);
            }
        }
        
        // Update weights and bias
        for (int j = 0; j < numFeatures; j++) {
            weights[j] -= learningRate * (dw[j] / numSamples);
        }
        bias -= learningRate * (db / numSamples);
        
        // Print progress every 100 epochs
        if ((epoch + 1) % 100 == 0 || epoch == 0) {
            // Compute loss (binary cross-entropy)
            double loss = 0.0;
            for (int i = 0; i < numSamples; i++) {
                double p = predictions[i];
                // Clip to prevent log(0)
                if (p < 1e-7) p = 1e-7;
                if (p > 1 - 1e-7) p = 1 - 1e-7;
                loss += y[i] * std::log(p) + (1 - y[i]) * std::log(1 - p);
            }
            loss = -loss / numSamples;
            
            std::cout << "Epoch " << std::setw(4) << (epoch + 1) 
                      << " - Loss: " << std::fixed << std::setprecision(4) << loss << std::endl;
        }
    }
    
    isTrained = true;
    std::cout << "\nTraining completed!" << std::endl;
    std::cout << "==================================================\n" << std::endl;
}

// Make predictions
Vector LogisticRegression::predict(const Matrix& X) {
    if (!isTrained) {
        throw std::runtime_error("Model must be trained before prediction");
    }
    
    int numSamples = X.getRows();
    int numFeatures = X.getCols();
    
    if (numFeatures != weights.getSize()) {
        throw std::invalid_argument("Number of features must match trained model");
    }
    
    Vector predictions(numSamples);
    
    for (int i = 0; i < numSamples; i++) {
        double z = bias;
        for (int j = 0; j < numFeatures; j++) {
            z += weights[j] * X.getValue(i, j);
        }
        double prob = sigmoid(z);
        predictions[i] = (prob >= 0.5) ? 1.0 : 0.0;  // Threshold at 0.5
    }
    
    return predictions;
}

// Get probability predictions
Vector LogisticRegression::predictProba(const Matrix& X) {
    if (!isTrained) {
        throw std::runtime_error("Model must be trained before prediction");
    }
    
    int numSamples = X.getRows();
    int numFeatures = X.getCols();
    
    Vector probabilities(numSamples);
    
    for (int i = 0; i < numSamples; i++) {
        double z = bias;
        for (int j = 0; j < numFeatures; j++) {
            z += weights[j] * X.getValue(i, j);
        }
        probabilities[i] = sigmoid(z);
    }
    
    return probabilities;
}

// Display model information
void LogisticRegression::displayInfo() const {
    std::cout << "Logistic Regression Model" << std::endl;
    std::cout << "Learning Rate: " << learningRate << std::endl;
    std::cout << "Epochs: " << epochs << std::endl;
    std::cout << "Trained: " << (isTrained ? "Yes" : "No") << std::endl;
    if (isTrained) {
        std::cout << "Number of features: " << weights.getSize() << std::endl;
        std::cout << "Bias: " << bias << std::endl;
    }
}

// Getters
Vector LogisticRegression::getWeights() const {
    return weights;
}

double LogisticRegression::getBias() const {
    return bias;
}

double LogisticRegression::getLearningRate() const {
    return learningRate;
}

int LogisticRegression::getEpochs() const {
    return epochs;
}

bool LogisticRegression::getIsTrained() const {
    return isTrained;
}

// Setters
void LogisticRegression::setLearningRate(double lr) {
    learningRate = lr;
}

void LogisticRegression::setEpochs(int numEpochs) {
    epochs = numEpochs;
}
