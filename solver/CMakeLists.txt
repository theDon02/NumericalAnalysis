# Defining my library
project(solver)

# Define sources files needed for this library and set them equal to SOURCES
set(SOURCES
src/solver.cpp)

#Create a library using .h and .cpp files
add_library(solver ${SOURCES})

#This will include all the header files into the library
target_include_directories(solver PUBLIC 
${CMAKE_CURRENT_SOURCE_DIR}/include)

# Since there is no need of using other LIBRARIES, we dont have to link anything here. But this might change!