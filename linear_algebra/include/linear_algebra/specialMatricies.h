#ifndef LINEAR_ALGEBRA_SPECIAL_MATRICIES_H
#define LINEAR_ALGEBRA_SPECIAL_MATRICIES_H

#include "matrix.h"

namespace linear_algebra {
    class SquareMatrix : public Matrix {
        public:
            //Default constructor
            SquareMatrix(){};

            /*
            This constructor will create a SQUARE Matrix instance filled with 0's with a dimension of c x r.
            @param unsgined int r: The row size of the matrix
            @param unsigned int c: The columns size of the matrix
            */
            SquareMatrix(unsigned int r, unsigned int c);

            /*
            This constructor will create a SQUARE Matrix instance with dimensions of c x r and the elements of the matrix will be provided by an input file
            @param unsigned int r: The row size of the matrix
            @param unsigned int c: The columns size of the matrix
            @param std::string f: The file input that contains the elements of the matrix 

            NOTE: It is important the dimensions passed in as parameters match the parameters in the file
            */
            SquareMatrix(unsigned int c, unsigned int r, std::string f);

            /*
            This constructor will create a SQUARE Matrix instance with dimensions c x r and the elements of the matrix like the dimension will be inside the file
            @param std::string f: The input file
            */
            SquareMatrix(std::string f) : Matrix(f){};

            /*
            This constructor will create a SQUARE Matrix instance with a dimension of c x r
            @param std::vector<std::vector<double>>& m: It is the 2D vector that we want to use for this Matrix instance
            */
            SquareMatrix(std::vector<std::vector<double>>& m);

            //Destructor
            ~SquareMatrix(){};
    };

    class IdentityMatrix : public SquareMatrix {
        public:
            //Default constructor
            IdentityMatrix(){};

            /*
            This constructor will create an IDENTITY Matrix instance with a dimension of c x r
            @param unsigned int r: The row size of the matrix
            @param unsigned int c: The column size of the matrix 

            NOTE: It is important that this special Matrix is a SQUARE matrix
            */
            IdentityMatrix(unsigned int r, unsigned int c); 

            /*
            This constructor will create an IDENTITY Matrix instance with a dimension of c x r 
            @param std::vector<std::vector<double>>& m: This is the 2D vector matrix that holds the elements
            */
            IdentityMatrix(std::vector<std::vector<double>>& m);

            //Destructor
            ~IdentityMatrix(){};
    };

}

#endif