#ifndef LINEAR_ALGEBRA_MATRIX_H
#define LINEAR_ALGEBRA_MATRIX_H
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

//Include header files
#include "linear_algebra/vector.h"
// #include <gtest/gtest.h>

namespace linear_algebra {
    class Matrix {
        private:
            std::vector<std::vector<double>> _matrix;
            std::tuple<unsigned int, unsigned int> _dimension;

        public:
            //Default constructor
            Matrix(){};

            /*
            This constructor will create Matrix instance filled with 0's with a dimension of c x r
            @param unsigned int r: The row size of the matrix
            @param unsigned int c: The column size of the matrix            
            */
            Matrix(const unsigned int r, const unsigned int c); 

            /*
            This constructor will create Matrix instance with a dimension of c x r
            @param unsigned int c: The row size of the matrix
            @param usigned int r: The column size of the matrix
            @param std::string f: The file name that has the values of the matrix, number of rows, and number of columns

            NOTE: The inputted "c", "r" need to match with the column and row value inside the inputted file
            */
            Matrix(const unsigned int c, const unsigned int r, const std::string f);

            /*
            This constructor will create Matrix instance with a dimesion of c x r
            @param std::string f: The file name that has the value of the matrix, number of rows, and number of columns
            */
            Matrix(const std::string f);

            /*
            This constructor will create Matrix instance with a dimension of c x r
            @param std::vector<std::vector<double>>& m: It is the 2D vector that we want to use for this Matrix instance.
            */
            Matrix(const std::vector<std::vector<double>>& m);

            //Destructor
            ~Matrix(){};

            /*
            This function will return this Matrix's instance 2D vector.

            NOTE: This is a getter function
            */
            std::vector<std::vector<double>>& getMatrix(){return _matrix;};

            /*
            This function will return this Matrix's instance row dimension

            NOTE: This is a getter function
            */
            unsigned int getRows(){return std::get<0>(_dimension);};

            /*
            This function will return the Matrix's instance dimension

            NOTE: This is a getter function
            */
            std::tuple<unsigned int, unsigned int>& getDimensions(){return _dimension;};

            /*
            This function will return this Matrix's instance column dimension

            NOTE: This is a getter function            
            */
            unsigned int getCols(){return std::get<1>(_dimension);};

            /*
            This function will set this Matrix's instance row dimension value
            @param unsigned int r: The inputted row value

            NOTE: This is a setter function
            */
            void setRows(const unsigned int r){std::get<0>(_dimension) = r;};

            /*
            This function will set this Matrix's instance column dimension value
            @param unsigned int c: The inputted column value

            NOTE: This is a setter function
            */
            void setColumns(const unsigned int c){std::get<1>(_dimension) = c;};

            /*
            This function will set this Matrix's instance 2D vector that holds the element of this Matrix object
            @param std::vector<std::vector<double>>& m: The inputted 2D vector that we want to use

            NOTE: This is a setter function
            */
            void setMatrix(const std::vector<std::vector<double>>& m){_matrix = m;};

            /*
            This function will change the value of a specific element inside the matrix. 
            @param unsigned int r: The row location of the element that is going to be changed
            @param unsigned int c: The column location of the element that is going to be changed
            @param double v: The value that the specific element will be changed to
            */
            void setVal(const unsigned int r, const unsigned int c, const double v);

            /*
            This function will get the element value that is at location [c, r]
            @param unsigned int r: The row location of the element that we want to get
            @param unsigned int c: The column location of the element that we want to get
            */
            double getVal(const unsigned int r, const unsigned int c);

            /*
            This function will return if the current Matrix instance is a square matrix
            */
            bool isSquare(){return std::get<0>(_dimension) == std::get<1>(_dimension);};

            /*
            This function will read in a file that contains elements of the matrix.
            @param std::string f: The inputted file
            @param bool hasDim: This is used for the second constructor, to make sure that dimension parameters and the dimension inside the file match
            */
            void filloutMatrix(const std::string, const bool hasDim);

            /*
            This function will print out the matrix to the console
            */
            void printMatrix();
    };
}

#endif