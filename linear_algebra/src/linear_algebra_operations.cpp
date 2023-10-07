#include "linear_algebra/linear_algebra_operations.h"

linear_algebra::Matrix LinearAlgebraOperations::Multiply(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2){
    try {
        //Check the number of columns and rows match
        if(m1.getCols() != m2.getRows()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Multiply: Columns of first Matrix and Rows of Second matrix don't match", 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        std::cerr << e.printMessage();
        std::exit(1);
    }

    //Resulting Matrix, it will contain the correct values
    linear_algebra::Matrix result(m1.getRows(), m2.getCols());

    for(unsigned int i = 0; i < m1.getRows(); i++){
        for(unsigned int j = 0; j < m2.getCols(); j++){
            double val = 0;
            for(unsigned int z = 0; z < m1.getCols(); z++){
                val += (m1.getVal(i, z) * m2.getVal(z, j));
            }
            result.setVal(i, j, val);
        }
    }

    return result;
}

linear_algebra::Matrix LinearAlgebraOperations::Multiply(linear_algebra::Matrix& m1, linear_algebra::Vector& v2){
    try {
        //Check the number of columns and rows match
        if(m1.getCols() != v2.getRows()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Multiply: Columns of first Matrix and Rows of Vector don't match", 3);
        }
    } catch (LinearAlgebraRunTimeException& e) {
        std::cerr << e.printMessage();
        std::exit(1);
    }

    //Resulting Matrix 
    linear_algebra::Matrix result(m1.getRows(), v2.getCols());

    for(unsigned int i = 0; i < m1.getRows(); i++){
        for(unsigned int j = 0; j < v2.getCols(); j++){
            double val = 0;
            for(unsigned int z = 0; z < m1.getCols(); z++){
                val += (m1.getVal(i, z) * v2.getVal(z));
            }
            result.setVal(i, j, val);
        }
    }

    return result;
}

linear_algebra::Matrix LinearAlgebraOperations::Subtract(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2){
    try {
        if(m1.getCols() != m2.getCols()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Subtract: The columns of both Matricies are not the same", 3);
        }

        if(m1.getRows() != m2.getRows()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Subtract: The rows of both Matricies are not the same", 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        std::cerr << e.printMessage();
        std::exit(1);
    }

    //Resulting matrix
    linear_algebra::Matrix result(m1.getRows(), m2.getCols());

    for(unsigned int i = 0; i < m1.getRows(); i++){
        for(unsigned int j = 0; j < m1.getCols(); j++){
            result.setVal(i, j, (m1.getVal(i, j) - m2.getVal(i, j)));
        }
    }

    return result;
}

linear_algebra::Matrix LinearAlgebraOperations::Add(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2){
    try {
        if(m1.getCols() != m2.getCols()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Subtract: The columns of both Matricies are not the same", 3);
        }

        if(m1.getRows() != m2.getRows()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Subtract: The rows of both Matricies are not the same", 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        std::cerr << e.printMessage();
        std::exit(1);
    }

    //Resulting matrix
    linear_algebra::Matrix result(m1.getRows(), m2.getCols());

    for(unsigned int i = 0; i < m1.getRows(); i++){
        for(unsigned int j = 0; j < m1.getCols(); j++){
            result.setVal(i, j, (m1.getVal(i, j) + m2.getVal(i, j)));
        }
    }

    return result;
}

linear_algebra::Matrix LinearAlgebraOperations::Transpose(linear_algebra::Matrix& m){
    linear_algebra::Matrix result(m.getCols(), m.getRows());

    for(unsigned int i = 0; i < m.getRows(); i++){
        for(unsigned int j = 0; j < m.getCols(); j++){
            result.setVal(j, i, m.getVal(i, j));
        }
    }

    return result;
}

linear_algebra::Vector LinearAlgebraOperations::Add(linear_algebra::Vector& v1, linear_algebra::Vector& v2){
    try {
        if(v1.isColumnVector() && !v2.isColumnVector()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Add: The first vector is a column vector and the second vector is a row vector. They need to have the same shape", 3);
        }

        if(v1.isRowVector() && !v2.isRowVector()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Add: The first vector is a row vector and the second vector is a column vector. They need to have the same shape", 3);
        }

        if(v1.getSize() != v2.getSize()){
            throw LinearAlgebraRunTimeException ("LinearAlgebraOperations::Add: The number of elements in the vectors dont match each other", 3);
        }

    } catch(LinearAlgebraRunTimeException& e) {
        std::cerr << e.printMessage();
        std::exit(1);
    }

    linear_algebra::Vector result(v1.getSize());

    for(unsigned int j = 0; j < v1.getSize(); j++){
        result.setVal(j, (v1.getVal(j) + v2.getVal(j)));
    }

    return result;
}

linear_algebra::Vector LinearAlgebraOperations::Subtract(linear_algebra::Vector& v1, linear_algebra::Vector& v2){
    try {
        if(v1.isColumnVector() && !v2.isColumnVector()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Subtract: The first vector is a column vector and the second vector is a row vector. They need to have the same shape", 3);
        }

        if(v1.isRowVector() && !v2.isRowVector()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Subtract: The first vector is a row vector and the second vector is a column vector. They need to have the same shape", 3);
        }

        if(v1.getSize() != v2.getSize()){
            throw LinearAlgebraRunTimeException ("LinearAlgebraOperations::Subtract: The number of elements in the vectors dont match each other", 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        std::cerr << e.printMessage();
        std::exit(1);
    }

    linear_algebra::Vector result(v1.getSize());

    for(unsigned int j = 0; j < v1.getSize(); j++){
        result.setVal(j, (v1.getVal(j) - v2.getVal(j)));
    }

    return result;
}

linear_algebra::Vector LinearAlgebraOperations::Multiply(linear_algebra::Vector& v1, double val){
    linear_algebra::Vector result(v1.getSize());

    for(unsigned int i = 0; i < v1.getSize(); i++){
        result.setVal(i, (val * v1.getVal(i)));
    }

    return result;
}

linear_algebra::Matrix LinearAlgebraOperations::Multiply(linear_algebra::Vector& v1, linear_algebra::Matrix& m2){
    try {
        //Check the number of columns and rows match
        if(v1.getCols() != m2.getRows()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::Multiply: Vector and Matrix multiplication dimensions do not match!", 3);
        }
    } catch (LinearAlgebraRunTimeException& e) {
        std::cerr << e.printMessage();
        std::exit(1);
    }

    //Resulting Matrix 
    linear_algebra::Matrix result(v1.getRows(), m2.getCols());

    for(unsigned int i = 0; i < v1.getRows(); i++){
        for(unsigned int j = 0; j < m2.getCols(); j++){
            double val = 0;
            for(unsigned int z = 0; z < m2.getCols(); z++){
                val += (m2.getVal(i, z) * v1.getVal(z));
            }
            result.setVal(i, j, val);
        }
    }

    return result;
}

double LinearAlgebraOperations::dotProduct(linear_algebra::Vector& v1, linear_algebra::Vector& v2){
    try {
        if(v1.getSize() != v2.getSize()){
            throw LinearAlgebraRunTimeException("LinearAlgebraOperations::dotProduct: The number of elements in the first and second vectors do not match", 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        std::cerr << e.printMessage();
        std::exit(1);
    }

    double val = 0;
    for(unsigned int j = 0; j < v1.getSize(); j++){
        val = val + (v1.getVal(j) * v2.getVal(j));
    }

    return val;
}