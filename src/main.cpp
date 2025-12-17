#include <iomanip>
#include <iostream>

using namespace std;

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

int main()
{
    cout << "\n";
    cout << "======================================================" << endl;
    cout << "    TITAN-LEARN: C++ LOGISTIC REGRESSION ENGINE      " << endl;
    cout << "======================================================" << endl;
    cout << "University of Central Punjab - Fall 2025 Term Project" << endl;
    cout << "======================================================\n"
         << endl;

    try
    {
        // ==================== STEP 1: Load Dataset ====================
        cout << "STEP 1: Loading Dataset..." << endl;
        cout << "----------------------------------------------------" << endl;

        Dataset dataset;
        if (!dataset.loadCSV("../data/sample_data.csv"))
        {
            // Try alternate path
            if (!dataset.loadCSV("data/sample_data.csv"))
            {
                cerr << "Failed to load dataset. Please check the file path." << endl;
                return 1;
            }
        }

        dataset.displayInfo();
        dataset.displayHead(5);

        // ==================== STEP 2: Statistical Analysis ====================
        cout << "\nSTEP 2: Performing Statistical Analysis..." << endl;
        cout << "----------------------------------------------------" << endl;

        DataSummary summary;
        Matrix features = dataset.getFeatures();
        summary.generateReport(features);

        // ==================== STEP 3: Feature Scaling ====================
        cout << "\nSTEP 3: Scaling Features..." << endl;
        cout << "----------------------------------------------------" << endl;

        MinMaxScaler scaler;
        scaler.fit(features);
        Matrix scaledFeatures = scaler.transform(features);

        cout << "Features scaled to range [0, 1]" << endl;
        cout << "First 3 rows of scaled data:" << endl;
        for (int i = 0; i < min(3, scaledFeatures.getRows()); i++)
        {
            cout << "Row " << i << ": ";
            for (int j = 0; j < scaledFeatures.getCols(); j++)
            {
                cout << fixed << setprecision(4)
                     << scaledFeatures.getValue(i, j) << " ";
            }
            cout << endl;
        }
        cout << endl;

        // ==================== STEP 4: Split Data (Simple Approach) ====================
        cout << "\nSTEP 4: Preparing Training Data..." << endl;
        cout << "----------------------------------------------------" << endl;

        // For this demo, we'll use the entire dataset for training
        // In practice, you would split into train/test sets
        Matrix X_train = scaledFeatures;
        Vector y_train = dataset.getLabels();

        cout << "Training samples: " << X_train.getRows() << endl;
        cout << "Features: " << X_train.getCols() << endl;
        cout << endl;

        // ==================== STEP 5: Train Model ====================
        cout << "\nSTEP 5: Training Logistic Regression Model..." << endl;
        cout << "----------------------------------------------------" << endl;

        LogisticRegression model(0.1, 500); // learning rate = 0.1, epochs = 500
        model.train(X_train, y_train);

        // ==================== STEP 6: Make Predictions ====================
        cout << "\nSTEP 6: Making Predictions..." << endl;
        cout << "----------------------------------------------------" << endl;

        Vector predictions = model.predict(X_train);

        cout << "Predictions completed!" << endl;
        cout << "First 10 predictions vs actual:" << endl;
        for (int i = 0; i < min(10, predictions.getSize()); i++)
        {
            cout << "Sample " << i << ": Predicted = " << predictions[i]
                 << ", Actual = " << y_train[i] << endl;
        }
        cout << endl;

        // ==================== STEP 7: Evaluate Model ====================
        cout << "\nSTEP 7: Evaluating Model Performance..." << endl;
        cout << "----------------------------------------------------" << endl;

        double accuracy = Evaluation::calculateAccuracy(predictions, y_train);
        double precision = Evaluation::calculatePrecision(predictions, y_train);
        double recall = Evaluation::calculateRecall(predictions, y_train);
        double f1Score = Evaluation::calculateF1Score(predictions, y_train);

        cout << "\n========== MODEL PERFORMANCE METRICS ==========" << endl;
        cout << fixed << setprecision(4);
        cout << "Accuracy:  " << (accuracy * 100) << "%" << endl;
        cout << "Precision: " << (precision * 100) << "%" << endl;
        cout << "Recall:    " << (recall * 100) << "%" << endl;
        cout << "F1 Score:  " << (f1Score * 100) << "%" << endl;
        cout << "===============================================" << endl;

        Evaluation::displayConfusionMatrix(predictions, y_train);

        // ==================== STEP 8: Analyze Model ====================
        cout << "\nSTEP 8: Model Analysis (Using Friend Function)..." << endl;
        cout << "----------------------------------------------------" << endl;

        Evaluation::analyzeModel(model);

        // ==================== DEMONSTRATION OF OOP CONCEPTS ====================
        cout << "\n======================================================" << endl;
        cout << "    OOP CONCEPTS DEMONSTRATED IN THIS PROJECT        " << endl;
        cout << "======================================================" << endl;
        cout << "\n1. ENCAPSULATION:" << endl;
        cout << "   - Private data members in Tensor, Matrix, Vector" << endl;
        cout << "   - Controlled access via getters/setters" << endl;
        cout << "   - Private weights in LogisticRegression" << endl;

        cout << "\n2. OPERATOR OVERLOADING:" << endl;
        cout << "   - Matrix +, -, * operators" << endl;
        cout << "   - Stream insertion operator <<" << endl;
        cout << "   - Vector [] operator for element access" << endl;

        cout << "\n3. DEEP COPYING:" << endl;
        cout << "   - Custom copy constructor in Tensor" << endl;
        cout << "   - Assignment operator overloading" << endl;
        cout << "   - Proper memory management" << endl;

        cout << "\n4. POLYMORPHISM:" << endl;
        cout << "   - Dynamic: Model interface (train, predict)" << endl;
        cout << "   - Static: Constructor overloading in Vector" << endl;
        cout << "   - Virtual method dispatch" << endl;

        cout << "\n5. INHERITANCE:" << endl;
        cout << "   - Multi-level: Vector -> Tensor" << endl;
        cout << "   - Multiple: DataSummary -> CentralTendency + Dispersion" << endl;
        cout << "   - Single: LogisticRegression -> Model" << endl;

        cout << "\n6. VIRTUAL INHERITANCE:" << endl;
        cout << "   - Solving Diamond Problem in DataSummary" << endl;
        cout << "   - Only one StatisticalTool base instance" << endl;

        cout << "\n7. FRIEND FUNCTIONS:" << endl;
        cout << "   - Evaluation class accesses private LogisticRegression members" << endl;
        cout << "   - Controlled violation of encapsulation" << endl;

        cout << "\n======================================================" << endl;
        cout << "          PROJECT COMPLETED SUCCESSFULLY!             " << endl;
        cout << "======================================================\n"
             << endl;
    }
    catch (const exception &e)
    {
        cerr << "\nError: " << e.what() << endl;
        return 1;
    }

    return 0;
}