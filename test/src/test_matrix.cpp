#include <gtest/gtest.h>
#include "linear_algebra/matrix.h"

class testMatrix {
    public:
        testMatrix(){};
        ~testMatrix(){};
        bool matchingMatricies(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2);
        bool matchingMatricies(linear_algebra::Matrix& m1, std::vector<std::vector<double>>& _m);
        bool matchingDimensions(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2);
        bool matchingDimensions(linear_algebra::Matrix& m1, std::vector<std::vector<double>>& _m);
};

bool testMatrix::matchingMatricies(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2){
    if(m1.getCols() != m2.getCols()){
        return false;
    }

    if(m1.getRows() != m2.getRows()){
        return false;
    }

    for(unsigned int i = 0; i < m1.getRows(); i++){
        for(unsigned int j = 0; j < m1.getCols(); j++){
            if(m1.getVal(i, j) != m2.getVal(i,j)){
                return false;
            }
        }
    }

    return true;
} 

bool testMatrix::matchingMatricies(linear_algebra::Matrix& m1, std::vector<std::vector<double>>& _m){
    if(m1.getRows() != _m.size()){
        return false;
    }

    if(m1.getCols() != _m[0].size()){
        return false;
    }

    for(unsigned int i = 0; i < m1.getRows(); i++){
        for(unsigned int j = 0; j < m1.getCols(); j++){
            if(m1.getVal(i, j) != _m[i][j]){
                return false;
            }
        }
    }


    return true;
}

bool testMatrix::matchingDimensions(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2){
    if(m1.getCols() != m2.getCols()){
        return false;
    }

    if(m1.getRows() != m2.getRows()){
        return false;
    }

    return true;
}

bool testMatrix::matchingDimensions(linear_algebra::Matrix& m1, std::vector<std::vector<double>>& _m){
    if(m1.getRows() != _m.size()){
        return false;
    }

    if(m1.getCols() != _m[0].size()){
        return false;
    }

    return true;
}

/*
This test will test the first constructor of the Matrix class
*/
TEST(Creating_Matrix, first_constructor){
    //Create a testMatrix object
    testMatrix tm1;

    //Create a square Matrix
    linear_algebra::Matrix m1a(2, 2);

    //Creating my own square matrix
    std::vector<std::vector<double>> vecta = {
        {0, 0},
        {0, 0}  
    };

    ASSERT_TRUE(tm1.matchingMatricies(m1a, vecta));
    ASSERT_TRUE(tm1.matchingDimensions(m1a, vecta));

    //Create a square Matrix
    linear_algebra::Matrix m1b(3, 2);

    //Creating my own square matrix
    std::vector<std::vector<double>> vectb = {
        {0, 0},
        {0, 0},
        {0, 0}  
    };

    ASSERT_TRUE(tm1.matchingMatricies(m1b, vectb));
    ASSERT_TRUE(tm1.matchingDimensions(m1b, vectb));

    //Create a square Matrix
    linear_algebra::Matrix m1c(2, 5);

    //Creating my own square matrix
    std::vector<std::vector<double>> vectc = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}  
    };

    ASSERT_TRUE(tm1.matchingMatricies(m1c, vectc));
    ASSERT_TRUE(tm1.matchingDimensions(m1c, vectc));

}

// /*
// This test will test the second constructor of the Matrix class
// */
// TEST(Creating_Matrix, second_constructor){

// }

// /*
// This test will test the thrid constructor of the Matrix class
// */
// TEST(Creating_Matrix, third_constructor){

// }

// /*
// This test will test fourth constructor of the Matrix class
// */
// TEST(Creating_Matrix, fourth_constructor){

// }