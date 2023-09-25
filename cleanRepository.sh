# This file will be used to clean the compiled code inside the various libraries that have been compiled

#!/bin/bash

# Deleting the CMakeFiles folder in the root of the directory
rm -rf CMakeFiles/

# Deleting the compiled files inside linear_algebra folder
rm -rf ./linear_algebra/CMakeFiles
rm -rf ./linear_algebra/cmake_install.cmake
rm -rf ./linear_algebra/liblinear_algebra.a
rm -rf ./linear_algebra/Makefile

# Deleting the compiled files inside project_management folder
rm -rf ./project_management/CMakeFiles
rm -rf ./project_management/cmake_install.cmake
rm -rf ./project_management/libproject_management.a
rm -rf ./project_management/Makefile

# Deleting the compiled files insid the solver folder
rm -rf ./solver/CMakeFiles
rm -rf ./solver/cmake_install.cmake
rm -rf ./solver/libsolver.a
rm -rf ./solver/Makefile
