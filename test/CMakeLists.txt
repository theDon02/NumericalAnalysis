# This CMakeLists.txt will be used to do the testing of the application
cmake_minimum_required(VERSION 3.0.0)
find_package(GTest REQUIRED)

# This is where the gtest libraries is at
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# Folder that has all the src files
set(SOURCES
"src/"
)

# The source files
set(TEST_SOURCES
${SOURCES}main_test.cpp
${SOURCES}test_linear_algebra.cpp
${SOURCES}test_solver.cpp)

# Linking all the files to the executable
add_executable(numerical_solver_test ${TEST_SOURCES})

# Linking other libraries that are used in this project
target_link_libraries(numerical_solver_test
linear_algebra
solver
${GTEST_LIBRARIES})