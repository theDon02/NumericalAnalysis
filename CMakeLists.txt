cmake_minimum_required(VERSION 3.0.0)

#Project name
project(Numerical_Analysis VERSION 1.0.0)

#Include directories for the main project
include_directories(include)

#Creating a subdirectory for Linear Algebra Library
add_subdirectory(linear_algebra)

#Creating a subdirectory for Solver Library
add_subdirectory(solver)

#Creating a subdirectory for project_management
add_subdirectory(project_management)

#Creating an executable
add_executable(numerical_solver 
src/main.cpp)

#Linking the libraries that were created above to the executable
target_link_libraries(numerical_solver
PRIVATE
project_management)