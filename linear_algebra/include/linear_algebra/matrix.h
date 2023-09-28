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

            //Creating a matrix based on a 2D vector input
            Matrix(std::vector<std::vector<double>>&);

            //Destructor
            ~Matrix(){};

            //It will return the double _matrix vector
            std::vector<std::vector<double>> getMatrix(){return _matrix;};

            //It will return the number of rows in the matrix
            unsigned int getRows(){return _rows;};

            //It will return the number of columns in the matrix
            unsigned int getCols(){return _columns;};

            //It will set the rows of the matrix
            void setRows(unsigned int r){_rows = r;};

            //It will set the columns of the matrix
            void setColumns(unsigned int c){_columns = c;};

            //It will set the value of the 2D vector
            void setMatrix(std::vector<std::vector<double>>& m){_matrix = m;};

            //It will set a value at a position based on the user
            void setValueInMatrix(unsigned int, unsigned int, double);

            //It will return the value of the matrix at a specific position
            double getValueInMatrix(unsigned int, unsigned int);

            //Multiplies the current matrix object with another matrix object
            linear_algebra::Matrix multiply(linear_algebra::Matrix&);

            //It will fill out the matrix based on the input file
            void filloutMatrix(std::string, bool);

            //It will print out the matrix to console
            void printMatrix();

            //Returns true or false if the matrix is square or not
            bool isSquare(){return _rows == _columns;};

            //Returns true or false if the inputted row and column of matrix is square
            bool isSquare(unsigned int r, unsigned int c){return r == c;};

            //Returns a transposed of the matrix
            linear_algebra::Matrix getTranspose();
    };
}

#endif