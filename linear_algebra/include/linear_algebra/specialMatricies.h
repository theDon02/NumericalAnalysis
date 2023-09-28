#ifndef LINEAR_ALGEBRA_SPECIAL_MATRICIES_H
#define LINEAR_ALGEBRA_SPECIAL_MATRICIES_H

#include "matrix.h"

namespace linear_algebra {
    class SquareMatrix : public Matrix {
        public:
            //Default constructor
            SquareMatrix(){};

            //New constructor to create a square matrix that is filled with 0's
            SquareMatrix(unsigned int, unsigned int);

            //New constructor to create a square matrix
            SquareMatrix(unsigned int, unsigned int, std::string);

            //New constructor to create a square matrix
            SquareMatrix(std::string f) : Matrix(f){};

            //New constructor to create a square matrix based on a 2D input
            SquareMatrix(std::vector<std::vector<double>>& i);

            //Destructor
            ~SquareMatrix(){};
    };

    class IdentityMatrix : public SquareMatrix {
        public:
            //Default constructor
            IdentityMatrix(){};

            //New constuctor to create identity matrix
            IdentityMatrix(unsigned int c, unsigned int r); 

            //New constructor to create identity matrix
            IdentityMatrix(std::vector<std::vector<double>>& i);

            //Destructor
            ~IdentityMatrix(){};
    };

}

#endif