#include "linear_algebra/specialMatricies.h"

linear_algebra::SquareMatrix::SquareMatrix(unsigned int r, unsigned int c){
    if(!isSquare(r, c)){
        std::cout << "\nSquareMatrix constructor: The inputted rows and columns of matrix needs to be equal\n";
        std::exit(1);
    }

    //Setting the row and column, and creating the matrix
    Matrix::setRows(r);
    Matrix::setColumns(c);
    std::vector<std::vector<double>> vec(r, std::vector<double>(c, 0));
    Matrix::setMatrix(vec);
}

linear_algebra::SquareMatrix::SquareMatrix(unsigned int r, unsigned int c, std::string fileName){
    if(!isSquare(r, c)){
        std::cout << "\nSquareMatrix constructor: The inputted rows and columns of matrix needs to be equal\n";
        std::exit(1);
    }

    //Setting the row and column, and creating the matrix
    Matrix::setRows(r);
    Matrix::setColumns(c);
    Matrix::filloutMatrix(fileName, true);
}

linear_algebra::SquareMatrix::SquareMatrix(std::vector<std::vector<double>>& i){
    if(i.size() != i[0].size()){
        std::cout << "\nSquareMatrix constructor: The inputted 2D vector dont not have equal rows or columns\n";
        std::exit(1);
    }

    Matrix::setRows(i.size());
    Matrix::setColumns(i[0].size());
    Matrix::setMatrix(i);
}

linear_algebra::IdentityMatrix::IdentityMatrix(unsigned int c, unsigned int r) : SquareMatrix(r, c){
    if(!isSquare(r, c)){
        std::cout << "\nIdentityMatrix constructor: The inputted rows and columns of matrix needs to be equal\n";
        std::exit(1);
    }    

    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            if(i == j){
                Matrix::setValueInMatrix(i, j, 1.);
            }
        }
    }
}

linear_algebra::IdentityMatrix::IdentityMatrix(std::vector<std::vector<double>>& i){
    if(i.size() != i[0].size()){
        std::cout << "\nIdentityMatrix constructor: The inputted rows and columns of matrix needs to be equal\n";
        std::exit(1);
    }

    SquareMatrix::setRows(i.size());
    SquareMatrix::setColumns(i[0].size());
    SquareMatrix::setMatrix(i);
}