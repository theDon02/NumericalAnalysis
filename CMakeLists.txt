cmake_minimum_required(VERSION 3.0.0)

#Project name
project(Numerical_Analysis)

# Creating subdirectory for the libraries
add_subdirectory(linear_algebra) # linear algebra library
add_subdirectory(solver) # solver library
add_subdirectory(test) # testing library

#Creating an executable for the main program
add_executable(numerical_solver 
src/main.cpp)

#Linking the libraries that are needed for the executable program
target_link_libraries(numerical_solver
PRIVATE
linear_algebra
solver)