#ifndef TEST_LINEAR_ALGEBRA_MATRIX_H
#define TEST_LINEAR_ALGEBRA_MATRIX_H

#include <gtest/gtest.h>
#include "linear_algebra/matrix.h"

namespace test {
    class TestMatrix {
        public:
            //Default Constructor
            TestMatrix(){};

            //Destructor that will 
            ~TestMatrix(){};

            /*
            This function will test the FIRST constructor of the Matrix class, that isn't the default constructor
            @param unsigned int r: The number of rows
            @param unsigned int c: The number of columns
            */
            linear_algebra::Matrix& MatrixOne(unsigned int r, unsigned int c);

            /*
            This function will test the SECOND constructor of the Matrix class, that isn't the default constructor
            @param unsigned int c: The number of rows
            @param unsigned int r: The numeber of rows
            @param std::string f: The file name
            */
            linear_algebra::Matrix& MatrixTwo(unsigned int r, unsigned int c, std::string filename);

            /*
            This function will test the THIRD constructor of the Matrix class, that isn't the default constructor
            @param std::string filename: This is the file name that holds the matrix elements
            */
            linear_algebra::Matrix& MatrixThree(std::string filname);

            /*
            This function will test the FOURTH constructor of the Matrix class, that isn't the default contructor
            @param std::vector<std::vector<double>>& m: It is the 2D vector that we want to use for this Matrix instance
            */
            linear_algebra::Matrix& MatrixFour(std::vector<std::vector<double>>& m);

            /*
            
            */

    };
}

#endif