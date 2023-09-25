#ifndef LINEAR_ALGEBRA_VECTOR_H
#define LINEAR_ALGEBRA_VECTOR_H
#include <vector>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

namespace linear_algebra {
    class Vector{
        private:
            unsigned int _size;
            std::vector<double> _vector;
        public:
            //Constructor of this class
            Vector(unsigned int);

            //Constructor of this class
            Vector(unsigned int, std::string);

            //Destructor of this class
            ~Vector(){};

            //Print the vector
            void printVector();
    };
}

#endif