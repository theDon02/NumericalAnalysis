# Defining my library
project(linear_algebra)

# Define sources files needed for this library and set them equal to SOURCES
set(SOURCES
src/matrix.cpp
src/vector.cpp)

# Define header files needed for this library adn set them equal to HEADERS
set(HEADERS
include/linear_algebra/linear_algebra.h)

#Create a library using .h and .cpp files
add_library(linear_algebra ${SOURCES})

#This will include all the header files into the library
target_include_directories(linear_algebra PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include)
