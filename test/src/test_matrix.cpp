#include "include/test_matrix.h"

linear_algebra::Matrix& test::TestMatrix::MatrixOne(unsigned int r, unsigned int c){
    linear_algebra::Matrix m1(r, c);
    return m1;
}

TEST(creatingMatrixObjects, FirstConstructor){
    test::TestMatrix t1 = test::TestMatrix();

    //Creating a Matrix object using the first constructor of the class
    linear_algebra::Matrix m1 = t1.MatrixOne(2, 2);

    //Obtain the dimensions of the matrix
    auto [row, col] = m1.getDimensions();

    

}

TEST(creatingMatrixObjects, SecondConstructor){
    test::TestMatrix t1 = test::TestMatrix();
}

TEST(creatingMatrixObjects, ThirdConstructor){
    test::TestMatrix t1 = test::TestMatrix();
}


TEST(creatingMatrixObjects, FourthConstructor){
    test::TestMatrix t1 = test::TestMatrix();
}