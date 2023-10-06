#ifndef LINEAR_ALGEBRA_OPERATIONS_H
#define LINEAR_ALGEBRA_OPERATIONS_h
#include "linear_algebra/vector.h"
#include "linear_algebra/matrix.h"

class LinearAlgebraOperations {
    public:
        //Default constructor
        LinearAlgebraOperations(){};

        //Destructor
        ~LinearAlgebraOperations(){};


        linear_algebra::Matrix& Multiply(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2);
};

#endif