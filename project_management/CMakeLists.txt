# Defining my library
project(project_management)

# Define sources files needed for this library and set them equal to SOURCES
set(SOURCES
src/project.cpp
src/projectInput.cpp)

#Adding a library
add_library(project_management ${SOURCES})

#This will include all the header files into the library
target_include_directories(project_management PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include)

#Linking other libraries to this one
target_link_libraries(project_management PRIVATE
linear_algebra
solver)
