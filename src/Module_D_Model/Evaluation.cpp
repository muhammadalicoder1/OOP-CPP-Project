#include "Evaluation.h"
#include <iostream>
#include <iomanip>

// Calculate accuracy
double Evaluation::calculateAccuracy(const Vector& predictions, const Vector& actual) {
    if (predictions.getSize() != actual.getSize()) {
        throw std::invalid_argument("Prediction and actual vectors must have same size");
    }
    
    int n = predictions.getSize();
    int correct = 0;
    
    for (int i = 0; i < n; i++) {
        if (predictions[i] == actual[i]) {
            correct++;
        }
    }
    
    return (n > 0) ? (static_cast<double>(correct) / n) : 0.0;
}

// Calculate precision
double Evaluation::calculatePrecision(const Vector& predictions, const Vector& actual) {
    int tp = truePositives(predictions, actual);
    int fp = falsePositives(predictions, actual);
    
    if (tp + fp == 0) {
        return 0.0;  // No positive predictions
    }
    
    return static_cast<double>(tp) / (tp + fp);
}

// Calculate recall
double Evaluation::calculateRecall(const Vector& predictions, const Vector& actual) {
    int tp = truePositives(predictions, actual);
    int fn = falseNegatives(predictions, actual);
    
    if (tp + fn == 0) {
        return 0.0;  // No actual positives
    }
    
    return static_cast<double>(tp) / (tp + fn);
}

// Calculate F1 score
double Evaluation::calculateF1Score(const Vector& predictions, const Vector& actual) {
    double precision = calculatePrecision(predictions, actual);
    double recall = calculateRecall(predictions, actual);
    
    if (precision + recall == 0) {
        return 0.0;
    }
    
    return 2 * (precision * recall) / (precision + recall);
}

// True Positives
int Evaluation::truePositives(const Vector& predictions, const Vector& actual) {
    int count = 0;
    for (int i = 0; i < predictions.getSize(); i++) {
        if (predictions[i] == 1.0 && actual[i] == 1.0) {
            count++;
        }
    }
    return count;
}

// True Negatives
int Evaluation::trueNegatives(const Vector& predictions, const Vector& actual) {
    int count = 0;
    for (int i = 0; i < predictions.getSize(); i++) {
        if (predictions[i] == 0.0 && actual[i] == 0.0) {
            count++;
        }
    }
    return count;
}

// False Positives
int Evaluation::falsePositives(const Vector& predictions, const Vector& actual) {
    int count = 0;
    for (int i = 0; i < predictions.getSize(); i++) {
        if (predictions[i] == 1.0 && actual[i] == 0.0) {
            count++;
        }
    }
    return count;
}

// False Negatives
int Evaluation::falseNegatives(const Vector& predictions, const Vector& actual) {
    int count = 0;
    for (int i = 0; i < predictions.getSize(); i++) {
        if (predictions[i] == 0.0 && actual[i] == 1.0) {
            count++;
        }
    }
    return count;
}

// Display confusion matrix
void Evaluation::displayConfusionMatrix(const Vector& predictions, const Vector& actual) {
    int tp = truePositives(predictions, actual);
    int tn = trueNegatives(predictions, actual);
    int fp = falsePositives(predictions, actual);
    int fn = falseNegatives(predictions, actual);
    
    std::cout << "\n========== CONFUSION MATRIX ==========" << std::endl;
    std::cout << "                 Predicted" << std::endl;
    std::cout << "               0         1" << std::endl;
    std::cout << "Actual  0  " << std::setw(5) << tn << "  " << std::setw(5) << fp << std::endl;
    std::cout << "        1  " << std::setw(5) << fn << "  " << std::setw(5) << tp << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "True Positives:  " << tp << std::endl;
    std::cout << "True Negatives:  " << tn << std::endl;
    std::cout << "False Positives: " << fp << std::endl;
    std::cout << "False Negatives: " << fn << std::endl;
    std::cout << "======================================\n" << std::endl;
}

// Analyze model (friend function)
void Evaluation::analyzeModel(const LogisticRegression& model) {
    std::cout << "\n========== MODEL ANALYSIS ==========" << std::endl;
    
    // Access private members through friend relationship
    if (model.isTrained) {
        std::cout << "Model Status: Trained" << std::endl;
        std::cout << "Learning Rate: " << model.learningRate << std::endl;
        std::cout << "Training Epochs: " << model.epochs << std::endl;
        std::cout << "Bias: " << model.bias << std::endl;
        
        std::cout << "\nFeature Weights:" << std::endl;
        for (int i = 0; i < model.weights.getSize(); i++) {
            std::cout << "  Weight " << (i + 1) << ": " 
                      << std::fixed << std::setprecision(4) << model.weights[i] << std::endl;
        }
    } else {
        std::cout << "Model Status: Not Trained" << std::endl;
    }
    
    std::cout << "====================================\n" << std::endl;
}
