cmake_minimum_required(VERSION 3.0.0)

#Project name
project(Numerical_Analysis)

# Creating subdirectory for the libraries
add_subdirectory(linear_algebra)
add_subdirectory(solver)

#Creating an executable
add_executable(numerical_solver 
src/main.cpp)

#Linking the libraries that were created above to the executable
target_link_libraries(numerical_solver
PRIVATE
linear_algebra
solver)