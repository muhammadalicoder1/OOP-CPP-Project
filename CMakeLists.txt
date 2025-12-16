cmake_minimum_required(VERSION 3.10)
project(TitanLearn VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/include/Module_A_Mathematical_Core
    ${PROJECT_SOURCE_DIR}/include/Module_B_Statistical_Analysis
    ${PROJECT_SOURCE_DIR}/include/Module_C_Data_Management
    ${PROJECT_SOURCE_DIR}/include/Module_D_Model
)

# Source files
set(SOURCES
    src/Module_A_Mathematical_Core/Tensor.cpp
    src/Module_A_Mathematical_Core/Matrix.cpp
    src/Module_A_Mathematical_Core/Vector.cpp
    src/Module_B_Statistical_Analysis/CentralTendency.cpp
    src/Module_B_Statistical_Analysis/Dispersion.cpp
    src/Module_B_Statistical_Analysis/DataSummary.cpp
    src/Module_C_Data_Management/Dataset.cpp
    src/Module_C_Data_Management/MinMaxScaler.cpp
    src/Module_D_Model/LogisticRegression.cpp
    src/Module_D_Model/Evaluation.cpp
    src/main.cpp
)

# Create executable
add_executable(TitanLearn ${SOURCES})
