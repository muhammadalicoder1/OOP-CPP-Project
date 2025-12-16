#include <iostream>
#include <iomanip>

// Module A: Mathematical Core
#include "Tensor.h"
#include "Matrix.h"
#include "Vector.h"

// Module B: Statistical Analysis
#include "StatisticalTool.h"
#include "CentralTendency.h"
#include "Dispersion.h"
#include "DataSummary.h"

// Module C: Data Management
#include "Dataset.h"
#include "Scaler.h"
#include "MinMaxScaler.h"

// Module D: Model
#include "Model.h"
#include "LogisticRegression.h"
#include "Evaluation.h"

int main() {
    std::cout << "\n";
    std::cout << "======================================================" << std::endl;
    std::cout << "    TITAN-LEARN: C++ LOGISTIC REGRESSION ENGINE      " << std::endl;
    std::cout << "======================================================" << std::endl;
    std::cout << "University of Central Punjab - Fall 2025 Term Project" << std::endl;
    std::cout << "======================================================\n" << std::endl;
    
    try {
        // ==================== STEP 1: Load Dataset ====================
        std::cout << "STEP 1: Loading Dataset..." << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        
        Dataset dataset;
        if (!dataset.loadCSV("../data/sample_data.csv")) {
            // Try alternate path
            if (!dataset.loadCSV("data/sample_data.csv")) {
                std::cerr << "Failed to load dataset. Please check the file path." << std::endl;
                return 1;
            }
        }
        
        dataset.displayInfo();
        dataset.displayHead(5);
        
        // ==================== STEP 2: Statistical Analysis ====================
        std::cout << "\nSTEP 2: Performing Statistical Analysis..." << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        
        DataSummary summary;
        Matrix features = dataset.getFeatures();
        summary.generateReport(features);
        
        // ==================== STEP 3: Feature Scaling ====================
        std::cout << "\nSTEP 3: Scaling Features..." << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        
        MinMaxScaler scaler;
        scaler.fit(features);
        Matrix scaledFeatures = scaler.transform(features);
        
        std::cout << "Features scaled to range [0, 1]" << std::endl;
        std::cout << "First 3 rows of scaled data:" << std::endl;
        for (int i = 0; i < std::min(3, scaledFeatures.getRows()); i++) {
            std::cout << "Row " << i << ": ";
            for (int j = 0; j < scaledFeatures.getCols(); j++) {
                std::cout << std::fixed << std::setprecision(4) 
                          << scaledFeatures.getValue(i, j) << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
        
        // ==================== STEP 4: Split Data (Simple Approach) ====================
        std::cout << "\nSTEP 4: Preparing Training Data..." << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        
        // For this demo, we'll use the entire dataset for training
        // In practice, you would split into train/test sets
        Matrix X_train = scaledFeatures;
        Vector y_train = dataset.getLabels();
        
        std::cout << "Training samples: " << X_train.getRows() << std::endl;
        std::cout << "Features: " << X_train.getCols() << std::endl;
        std::cout << std::endl;
        
        // ==================== STEP 5: Train Model ====================
        std::cout << "\nSTEP 5: Training Logistic Regression Model..." << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        
        LogisticRegression model(0.1, 500);  // learning rate = 0.1, epochs = 500
        model.train(X_train, y_train);
        
        // ==================== STEP 6: Make Predictions ====================
        std::cout << "\nSTEP 6: Making Predictions..." << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        
        Vector predictions = model.predict(X_train);
        
        std::cout << "Predictions completed!" << std::endl;
        std::cout << "First 10 predictions vs actual:" << std::endl;
        for (int i = 0; i < std::min(10, predictions.getSize()); i++) {
            std::cout << "Sample " << i << ": Predicted = " << predictions[i] 
                      << ", Actual = " << y_train[i] << std::endl;
        }
        std::cout << std::endl;
        
        // ==================== STEP 7: Evaluate Model ====================
        std::cout << "\nSTEP 7: Evaluating Model Performance..." << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        
        double accuracy = Evaluation::calculateAccuracy(predictions, y_train);
        double precision = Evaluation::calculatePrecision(predictions, y_train);
        double recall = Evaluation::calculateRecall(predictions, y_train);
        double f1Score = Evaluation::calculateF1Score(predictions, y_train);
        
        std::cout << "\n========== MODEL PERFORMANCE METRICS ==========" << std::endl;
        std::cout << std::fixed << std::setprecision(4);
        std::cout << "Accuracy:  " << (accuracy * 100) << "%" << std::endl;
        std::cout << "Precision: " << (precision * 100) << "%" << std::endl;
        std::cout << "Recall:    " << (recall * 100) << "%" << std::endl;
        std::cout << "F1 Score:  " << (f1Score * 100) << "%" << std::endl;
        std::cout << "===============================================" << std::endl;
        
        Evaluation::displayConfusionMatrix(predictions, y_train);
        
        // ==================== STEP 8: Analyze Model ====================
        std::cout << "\nSTEP 8: Model Analysis (Using Friend Function)..." << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;
        
        Evaluation::analyzeModel(model);
        
        // ==================== DEMONSTRATION OF OOP CONCEPTS ====================
        std::cout << "\n======================================================" << std::endl;
        std::cout << "    OOP CONCEPTS DEMONSTRATED IN THIS PROJECT        " << std::endl;
        std::cout << "======================================================" << std::endl;
        std::cout << "\n1. ENCAPSULATION:" << std::endl;
        std::cout << "   - Private data members in Tensor, Matrix, Vector" << std::endl;
        std::cout << "   - Controlled access via getters/setters" << std::endl;
        std::cout << "   - Private weights in LogisticRegression" << std::endl;
        
        std::cout << "\n2. OPERATOR OVERLOADING:" << std::endl;
        std::cout << "   - Matrix +, -, * operators" << std::endl;
        std::cout << "   - Stream insertion operator <<" << std::endl;
        std::cout << "   - Vector [] operator for element access" << std::endl;
        
        std::cout << "\n3. DEEP COPYING:" << std::endl;
        std::cout << "   - Custom copy constructor in Tensor" << std::endl;
        std::cout << "   - Assignment operator overloading" << std::endl;
        std::cout << "   - Proper memory management" << std::endl;
        
        std::cout << "\n4. POLYMORPHISM:" << std::endl;
        std::cout << "   - Dynamic: Model interface (train, predict)" << std::endl;
        std::cout << "   - Static: Constructor overloading in Vector" << std::endl;
        std::cout << "   - Virtual method dispatch" << std::endl;
        
        std::cout << "\n5. INHERITANCE:" << std::endl;
        std::cout << "   - Multi-level: Vector -> Tensor" << std::endl;
        std::cout << "   - Multiple: DataSummary -> CentralTendency + Dispersion" << std::endl;
        std::cout << "   - Single: LogisticRegression -> Model" << std::endl;
        
        std::cout << "\n6. VIRTUAL INHERITANCE:" << std::endl;
        std::cout << "   - Solving Diamond Problem in DataSummary" << std::endl;
        std::cout << "   - Only one StatisticalTool base instance" << std::endl;
        
        std::cout << "\n7. FRIEND FUNCTIONS:" << std::endl;
        std::cout << "   - Evaluation class accesses private LogisticRegression members" << std::endl;
        std::cout << "   - Controlled violation of encapsulation" << std::endl;
        
        std::cout << "\n======================================================" << std::endl;
        std::cout << "          PROJECT COMPLETED SUCCESSFULLY!             " << std::endl;
        std::cout << "======================================================\n" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "\nError: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
