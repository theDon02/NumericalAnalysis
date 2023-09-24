# This file will be used to clean the compiled code inside the various libraries that have been compiled

#!/bin/bash

# Deleting the CMakeFiles folder in the root of the directory
rm -rf CMakeFiles/

# Deleting the compiled files inside linear_algebra folder
rm -rf ./linear_algebra/CMakeFiles
rm -rf cmake_install.cmake
rm -rf liblinear_algebra.a
rm -rf Makefile

# Deleting the compiled files inside the 