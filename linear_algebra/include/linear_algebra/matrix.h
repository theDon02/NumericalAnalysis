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

            /*
            This constructor will create Matrix instance filled with 0's with a dimension of c x r
            @param unsigned int r: The row size of the matrix
            @param unsigned int c: The column size of the matrix            
            */
            Matrix(unsigned int r, unsigned int c); 

            /*
            This constructor will create Matrix instance with a dimension of c x r
            @param unsigned int c: The row size of the matrix
            @param usigned int r: The column size of the matrix
            @param std::string f: The file name that has the values of the matrix, number of rows, and number of columns

            NOTE: The inputted "c", "r" need to match with the column and row value inside the inputted file
            */
            Matrix(unsigned int c, unsigned int r, std::string f);

            /*
            This constructor will create Matrix instance with a dimesion of c x r
            @param std::string f: The file name that has the value of the matrix, number of rows, and number of columns
            */
            Matrix(std::string f);

            /*
            This constructor will create Matrix instance with a dimension of c x r
            @param std::vector<std::vector<double>>& m: It is the 2D vector that we want to use for this Matrix instance.
            */
            Matrix(std::vector<std::vector<double>>& m);

            //Destructor
            ~Matrix(){};

            /*
            This function will return this Matrix's instance 2D vector.

            NOTE: This is a getter function
            */
            std::vector<std::vector<double>> getMatrix(){return _matrix;};

            /*
            This function will return this Matrix's instance row dimension

            NOTE: This is a getter function
            */
            unsigned int getRows(){return _rows;};

            /*
            This function will return this Matrix's instance column dimension

            NOTE: This is a getter function            
            */
            unsigned int getCols(){return _columns;};

            /*
            This function will set this Matrix's instance row dimension value
            @param unsigned int r: The inputted row value

            NOTE: This is a setter function
            */
            void setRows(unsigned int r){_rows = r;};

            /*
            This function will set this Matrix's instance column dimension value
            @param unsigned int c: The inputted column value

            NOTE: This is a setter function
            */
            void setColumns(unsigned int c){_columns = c;};

            /*
            This function will set this Matrix's instance 2D vector that holds the element of this Matrix object
            @param std::vector<std::vector<double>>& m: The inputted 2D vector that we want to use

            NOTE: This is a setter function
            */
            void setMatrix(std::vector<std::vector<double>>& m){_matrix = m;};

            /*
            This function will change the value of a specific element inside the matrix. 
            @param unsigned int r: The row location of the element that is going to be changed
            @param unsigned int c: The column location of the element that is going to be changed
            @param double v: The value that the specific element will be changed to
            */
            void setValueInMatrix(unsigned int r, unsigned int c, double v);

            /*
            This function will get the element value that is at location [c, r]
            @param unsigned int r: The row location of the element that we want to get
            @param unsigned int c: The column location of the element that we want to get
            */
            double getValueInMatrix(unsigned int r, unsigned int c);

            /*
            This function will multiply the current Matrix instance object against another Matrix object. And returns a result Matrix of the operation.
            @param linear_algebra::Matrix& i: It is the inputted Matrix that will be multiplied with.
            
            NOTE: This follows Matrix Multiplication algorithm.
            */
            linear_algebra::Matrix multiply(linear_algebra::Matrix& i);

            /*
            This function will read in a file that contains elements of the matrix.
            @param std::string f: The inputted file
            @param bool hasDim: This is used for the second constructor, to make sure that dimension parameters and the dimension inside the file match
            */
            void filloutMatrix(std::string, bool hasDim);

            /*
            This function will print the matrix to the console
            */
            void printMatrix();

            /*
            This function will return if the current Matrix instance is a square matrix
            */
            bool isSquare(){return _rows == _columns;};

            /*
            This function will return the transpose matrix of the current Matrix instance
            */
            linear_algebra::Matrix getTranspose();
    };
}

#endif