#include "linear_algebra/linear_algebra.h"

linear_algebra::Vector::Vector(unsigned int size) {
    _size = size;
    _vector = std::vector<double>(size, 0.);
}

void linear_algebra::Vector::printVector() {
    std::cout << "\nPrinting Vector\n";
    for(unsigned int i = 0; i < _size; i++){
        std::cout << "| " << std::fixed << std::setw(10) << std::setprecision(5) << this->_vector[i] << " |\n";
    }
}