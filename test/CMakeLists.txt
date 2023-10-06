include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

# Folder that has all the src files
set(SOURCES
"src/"
)

# The source files
set(TEST_SOURCES
${SOURCES}main_test.cpp
${SOURCES}test_linear_algebra_operations.cpp
${SOURCES}test_solver.cpp
${SOURCES}test_matrix.cpp
${SOURCES}test_vector.cpp)

# Linking all the files to the executable
add_executable(numerical_solver_test ${TEST_SOURCES})

# Linking other libraries that are used in this project
target_link_libraries(numerical_solver_test
PRIVATE
linear_algebra
solver
gtest
gtest_main)