#include "linear_algebra/linear_algebra_exceptions.h"
#include "linear_algebra/vector.h"

linear_algebra::Vector::Vector(const unsigned int size) {
    _dimension = std::make_tuple(size, 1);
    _vector = std::vector<double>(size, 0.);
}

linear_algebra::Vector::Vector(const unsigned int size, const bool cVector){
    if(cVector){
        _dimension = std::make_tuple(size, 1);
    }else{
        _dimension = std::make_tuple(1, size);
    }

    _vector = std::vector<double>(size, 0.);
}

void linear_algebra::Vector::addEnd(const double val){
    if(isColumnVector()){
        (std::get<0>(_dimension))++;
    }else{
        (std::get<1>(_dimension))++;
    }

    _vector.push_back(val);
}

void linear_algebra::Vector::setVal(const unsigned int p, const double val){
    try {
        if(p < 0 || p > _vector.size()){
            throw LinearAlgebraRunTimeException("Vector::setVal: The inputted index for the vector is out of bounds", 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        e.printMessage();
        std::exit(1);
    }

    _vector[p] = val;
}

double linear_algebra::Vector::getVal(const unsigned int p){
    try {
        if(p < 0 || p > _vector.size()){
            throw LinearAlgebraRunTimeException("Vector::getVal: The inputted index for the vector is out of bounds", 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        e.printMessage();
        std::exit(1);
    }

    return _vector[p];
}

linear_algebra::Vector linear_algebra::Vector::Add(linear_algebra::Vector& i){
    try {
        if(isColumnVector() && !i.isColumnVector()){
            throw LinearAlgebraRunTimeException("Vector::Add: The first vector is a column vector and the second vector is a row vector. They need to have the same shape", 3);
        }

        if(isRowVector() && !i.isRowVector()){
            throw LinearAlgebraRunTimeException("Vector::Add: The first vector is a row vector and the second vector is a column vector. They need to have the same shape", 3);
        }

        if(getSize() != i.getSize()){
            throw LinearAlgebraRunTimeException ("Vector::Add: The number of elements in the vectors dont match each other", 3);
        }

    } catch(LinearAlgebraRunTimeException& e) {
        e.printMessage();
        std::exit(1);
    }

    linear_algebra::Vector result(getSize());

    for(unsigned int j = 0; j < getSize(); j++){
        result.setVal(j, (getVal(j) + i.getVal(j)));
    }

    return result;
}


linear_algebra::Vector linear_algebra::Vector::Subtract(linear_algebra::Vector& i){
    try {
        if(isColumnVector() && !i.isColumnVector()){
            throw LinearAlgebraRunTimeException("Vector::Subtract: The first vector is a column vector and the second vector is a row vector. They need to have the same shape", 3);
        }

        if(isRowVector() && !i.isRowVector()){
            throw LinearAlgebraRunTimeException("Vector::Subtract: The first vector is a row vector and the second vector is a column vector. They need to have the same shape", 3);
        }

        if(getSize() != i.getSize()){
            throw LinearAlgebraRunTimeException ("Vector::Subtract: The number of elements in the vectors dont match each other", 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        e.printMessage();
        std::exit(1);
    }

    linear_algebra::Vector result(getSize());

    for(unsigned int j = 0; j < getSize(); j++){
        result.setVal(j, (getVal(j) - i.getVal(j)));
    }

    return result;
}

linear_algebra::Vector linear_algebra::Vector::Multiply(double val){
    linear_algebra::Vector result(getSize());

    for(unsigned int i = 0; i < getSize(); i++){
        result.setVal(i, (val * getVal(i)));
    }

    return result;
}


double linear_algebra::Vector::dotProduct(linear_algebra::Vector& i){
    try {
        if(getSize() != i.getSize()){
            throw LinearAlgebraRunTimeException("Vector::dotProduct: The number of elements in the first and second vectors dont match", 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        e.printMessage();
        std::exit(1);
    }

    double val = 0;
    for(unsigned int j = 0; j < getSize(); j++){
        val = val + (getVal(j) * i.getVal(j));
    }

    return val;
}

bool linear_algebra::Vector::isColumnVector(){
    return std::get<1>(_dimension) == 1;
}

bool linear_algebra::Vector::isRowVector(){
    return std::get<0>(_dimension) == 1;
}

void linear_algebra::Vector::Transpose(){
    if(isColumnVector()){
        std::get<0>(_dimension) = 1;
        std::get<1>(_dimension) = _vector.size();
    }else{
        std::get<0>(_dimension) = _vector.size();
        std::get<1>(_dimension) = 1;
    }
}

void linear_algebra::Vector::printVector() {
    std::cout << "\nPrinting Vector\n";

    if(isRowVector()){
        for(unsigned int i = 0; i < _vector.size(); i++){
            std::cout << "| " << std::fixed << std::setw(10) << std::setprecision(5) << _vector[i] << " ";

            if(i + 1 == _vector.size()){
                std::cout << "|\n";
            }
        }
    }else{
        for(unsigned int i = 0; i < _vector.size(); i++){
            std::cout << "| " << std::fixed << std::setw(10) << std::setprecision(5) << _vector[i] << " |\n";
        }
    }
}