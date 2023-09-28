# Defining my library
project(linear_algebra)

# Define sources files needed for this library and set them equal to SOURCES
set(SOURCES
src/matrix.cpp
src/vector.cpp
src/specialMatricies.cpp)

# Define a library target
add_library(linear_algebra ${SOURCES})

#Include all the header files. Look at the files inside the src folder to see what header files are included
target_include_directories(linear_algebra PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include)

# Since there is no need of using other LIBRARIES, we dont have to link anything here. But this might change!
