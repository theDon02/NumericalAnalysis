#ifndef LINEAR_ALGEBRA_OPERATIONS_H
#define LINEAR_ALGEBRA_OPERATIONS_h
#include "linear_algebra/vector.h"
#include "linear_algebra/matrix.h"
#include "linear_algebra/linear_algebra_exceptions.h"

class LinearAlgebraOperations {
    public:

        //Default constructor
        LinearAlgebraOperations(){};

        //Destructor
        ~LinearAlgebraOperations(){};

        /*
        This function will multiply Matrix 1 against Matrix 2. And return a resulting Matrix of the operation
        @param linear_algebra::Matrix& m1: This is the first matrix in question
        @param linear_algebra::Matrix& m2: This is the second matrix in question

        NOTE: This follows the Matrix Multiplication algorithm
        */
        linear_algebra::Matrix Multiply(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2);

        /*
        This function will multiply the Matrix 1 with a Vector object. And returns a resulting Matrix of the operation
        @param linear_algebra::Matrix& m1: This is the matrix in question
        @param linear_algebra::Vector& v2: This is the vector in question

        NOTE: The vector will be considered as a Matrix. Except one dimesion of the vector will be 1
        */
        linear_algebra::Matrix Multiply(linear_algebra::Matrix& m1, linear_algebra::Vector& v2);

        /*
        This function will subtract Matrix 1 with Matrix 2. And return a resulting Matrix of the operation.
        @param linear_algebra::Matrix& m1: This is the first matrix in question
        @param linear_algebra::Matrix& m2: This is the second matrixs in question
        */
        linear_algebra::Matrix Subtract(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2);

        /*
        This function will add Matrix 1 with Matrix 2. And return a resulting Matrix of the operation.
        @param linear_algebra::Matrix& m1: This is the first matrix in question
        @param linear_algebra::Matrix& m2: This is the second matrix in question
        */
        linear_algebra::Matrix Add(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2);

        /*
        This function will return the transpose of the Matrix that was inputted
        @param linear_algebra::Matrix& m: This is the matrix in question
        */
        linear_algebra::Matrix Transpose(linear_algebra::Matrix& m);

        /*
        This function will add Vector 1 with Vector 2. And return a resulting Vector of the operation
        @param linear_algebra::Vector& v1: This is the first Vector in question
        @param linear_algebra::Vector& v2: This is the second Vector in question
        */
        linear_algebra::Vector Add(linear_algebra::Vector& v1, linear_algebra::Vector& v2);

        /*
        This function will subtract Vector 1 with Vector 2. And return a resulting Vector of the operation
        @param linear_algebra::Vector& v1: This is the first Vector in question
        @param linear_algebra::Vector& v2: This is the second Vector in question
        */
        linear_algebra::Vector Subtract(linear_algebra::Vector& v1, linear_algebra::Vector& v2);

        /*
        This function will Multiply a Vector with a scalar value. And return a resulting Vector of the operation
        @param linear_algebra::Vector& v1: This is the first Vector in question
        @param double val: This is the scalar to multiply the Vector by
        */
        linear_algebra::Vector Multiply(linear_algebra::Vector& v1, double val);

        /*
        This function will compute the Dot Product between Vector 1 and Vector 2. It will return a double value
        @param linear_algebra::Vector& v1: This is the first Vector in question
        @param linear_algebra::Vector& v2: This is the second Vector in question
        */
        double dotProduct(linear_algebra::Vector& v1, linear_algebra::Vector& v2);


};

#endif