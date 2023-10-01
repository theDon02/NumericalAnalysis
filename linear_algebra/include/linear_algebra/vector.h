#ifndef LINEAR_ALGEBRA_VECTOR_H
#define LINEAR_ALGEBRA_VECTOR_H
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <tuple>


namespace linear_algebra {
    class Vector{
        private:
            std::vector<double> _vector;
            std::tuple<unsigned int, unsigned int> _dimension;
        public:
            //Default constructor
            Vector(){};

            /*
            This function will create a COLUMN Vector of size "s". The vector will be filled with 0's
            @param unsigned int s: The size of the vector that we want
            */
            Vector(const unsigned int s);

            /*
            This function will create a COLUMN Vector or ROW Vector
            @param unsigned int s: The size of the vector that we want
            @param bool cVector: Determines if the vector is Column (true) or Row (false).
            */
            Vector(const unsigned int s, const bool cVector);

            //Destructor of this class
            ~Vector(){};

            /*
            This function will input a vector at the end of the vector instance.
            @param double val: This is the value that will be put inside the vector
            */
            void addEnd(const double val);

            /*
            This function will set an element inside the vector. 
            @param unsigned int p: This is the position that will set the value in the vector
            @param double val: This is the value that will be put inside
            */
            void setVal(const unsigned int p, const double val);

            /*
            This function will return the element inside the vector
            @param: unsigned int p: The postion in vector that we want to obtain.
            */
            double getVal(const unsigned int p);

            /*
            This function will return the number of elements inside the vector
            */
            unsigned int getSize(){return (unsigned int)_vector.size();};

            /*
            This function will return the dimension of this vector
            */
            std::tuple<unsigned int, unsigned int>& getDimensions(){return _dimension;};

            /*
            This function will add the current Vector instance object against another Vector object. And returns a result Vector of the operation.
            @param linear_algebra::Vector& i: It is the inputted Vector that will be added with

            NOTE: This follows the Vector Addition Rules
            */
            linear_algebra::Vector Add(linear_algebra::Vector& i);

            /*
            This function will subtract the current Vector instance object against another Vector object. And returns a result Vector of the operation.
            @param linear_algebra::Vector& i: It is the inputted Vector that will be subtracted with

            NOTE: This follows the Vector Subtraction Rules
            */
            linear_algebra::Vector Subtract(linear_algebra::Vector& i);

            /*
            This function will Multiply the current Vector with a Scalar, and return a result Vector of the operation.
            @param double val: It is the scalar to multiply the Vector by

            NOTE: This follows the Vector-Scalar Multiplication Rules
            */
            linear_algebra::Vector Multiply(double val);

            /*
            This function will compute the Dot Product between the current Vector instance with another Vector object and it will result a double value.
            @param linear_algebra::Vector& i: It is the inputted Vector that will be dotted with

            NOTE: This follows the Vector Dot Product Rules
            */
            double dotProduct(linear_algebra::Vector& i);

            /*
            This function will return if the Vector instance is a COLUMN Vector
            */
            bool isColumnVector();

            /*
            This function will return if the Vector instance is a ROW Vector
            */
            bool isRowVector();

            /*
            This function will transpose the Vector instance

            NOTE: If the vector instance was a row vector to begin with it will become a column vector and vice versa
            */
            void Transpose();

            /*
            This function will print the vector accoridingly. If the vector is a column vector then it will be printed that way. If the vector is a row vector then it will be printed that way.
            */
            void printVector();
    };
}

#endif