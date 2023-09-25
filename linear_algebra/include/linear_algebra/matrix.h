#ifndef LINEAR_ALGEBRA_MATRIX_H
#define LINEAR_ALGEBRA_MATRIX_H
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

namespace linear_algebra {
    class Matrix {
        private:
            unsigned int _rows, _columns;
            std::vector<std::vector<double>> _matrix;

        public:
            //Default constructor
            Matrix(){};

            //Creating a matrix of size r x c and filling them with 0's
            Matrix(unsigned int, unsigned int); 

            //Creating a matrix based on a text file input
            Matrix(unsigned int, unsigned int, std::string);

            //Creating a matrix based on the text file input only
            Matrix(std::string);

            //Destructor
            ~Matrix(){};

            //It will return the double _matrix vector
            std::vector<std::vector<double>> getMatrix(){return _matrix;};

            //It will return the number of rows in the matrix
            unsigned int getRows(){return _rows;};

            //It will return the number of columns in the matrix
            unsigned int getCols(){return _columns;};

            //It will set a value at a position based on the user
            void setValueInMatrix(unsigned int, unsigned int, double);

            //It will return the value of the matrix at a specific position
            double getValueInMatrix(unsigned int, unsigned int);

            //Multiplies the current matrix object with another matrix object
            linear_algebra::Matrix multiply(linear_algebra::Matrix*);

            // //Multiplies a vector of matricies together to get a resultant matrix
            // linear_algebra::Matrix multiply(std::vector<linear_algebra::Matrix*>*);

            // //Multiplies a matrix with an inputed vector
            // linear_algebra::Matrix multiply(linear_algebra::Vector*);

            //Checks if the order of matricies in the vector is good
            bool isMatrixCorrectOrder(std::vector<linear_algebra::Matrix*>*, bool*);

            // //Orders the order of matricies the best way possible
            // void reorderMatrixVector(std::vector<linear_algebra::Matrix*>*);

            //It will fill out the matrix based on the input file
            void filloutMatrix(std::string);

            //It will print out the matrix to console
            void printMatrix();

            //Returns true or false if the matrix is square or not
            bool isSquare();
    };
}

#endif