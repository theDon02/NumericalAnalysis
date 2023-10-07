#include <gtest/gtest.h>
#include <string>
#include "linear_algebra/matrix.h"
#include "linear_algebra/linear_algebra_exceptions.h"

class testMatrix {
    public:
        testMatrix(){};
        ~testMatrix(){};
        bool matchingMatricies(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2);
        bool matchingMatricies(linear_algebra::Matrix& m1, std::vector<std::vector<double>>& _m);
        bool matchingDimensions(linear_algebra::Matrix& m1, linear_algebra::Matrix& m2);
        bool matchingDimensions(linear_algebra::Matrix& m1, std::vector<std::vector<double>>& _m);
        bool correctDimensions(linear_algebra::Matrix& m1, unsigned int& r, unsigned int& c);
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

bool testMatrix::correctDimensions(linear_algebra::Matrix& m1, unsigned int& r, unsigned int& c){
    if(m1.getRows() != r){
        return false;
    }

    if(m1.getCols() != c){
        return false;
    }

    return true;
}

/*
This test will test the first constructor of the Matrix class.

This constructor will create Matrix instance filled with 0's with a dimension of c x r
@param unsigned int r: The row size of the matrix
@param unsigned int c: The column size of the matrix  
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

    //Create a square matrix
    linear_algebra::Matrix m1d(3, 3);

    //Creating my own square matrix
    std::vector<std::vector<double>> vectd = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}  
    };

    ASSERT_FALSE(tm1.matchingMatricies(m1d, vectd));
    ASSERT_FALSE(tm1.matchingMatricies(m1d, vectd));
}

/*
This test will test fourth constructor of the Matrix class

This constructor will create Matrix instance with a dimension of c x r
@param std::vector<std::vector<double>>& m: It is the 2D vector that we want to use for this Matrix instance.            
*/
TEST(Creating_Matrix, fourth_constructor){
    //Creating a testMatrix object
    testMatrix tm4;

    //Creating my own square matrix
    std::vector<std::vector<double>> vecta = {
        {0, 0},
        {0, 0}  
    };

    //Create a Matrix
    linear_algebra::Matrix m4a(vecta);

    ASSERT_TRUE(tm4.matchingMatricies(m4a, vecta));
    ASSERT_TRUE(tm4.matchingDimensions(m4a, vecta));

    std::vector<std::vector<double>> vectb = {
        {0, 0},
        {0, 0},
        {0, 0},
    };

    linear_algebra::Matrix m4b(vectb);

    ASSERT_TRUE(tm4.matchingMatricies(m4b, vectb));
    ASSERT_TRUE(tm4.matchingDimensions(m4b, vectb));
}

/*
This test will test the getMatrix() function in the Matrix class
*/
TEST(Test_Method, getMatrix){
    //Testing matrix 
    testMatrix tm5;

    linear_algebra::Matrix m1(3, 2);
    std::vector<std::vector<double>> vect1 = m1.getMatrix();
    ASSERT_TRUE(tm5.matchingMatricies(m1, vect1));   

    linear_algebra::Matrix m2(10, 10);
    std::vector<std::vector<double>> vect2 = m2.getMatrix(); 
    ASSERT_TRUE(tm5.matchingMatricies(m2, vect2));     

    linear_algebra::Matrix m3(3, 5);
    std::vector<std::vector<double>> vect3 = m3.getMatrix();  
    ASSERT_TRUE(tm5.matchingMatricies(m3, vect3));    

    linear_algebra::Matrix m4(15, 4);
    std::vector<std::vector<double>> vect4 = m4.getMatrix(); 
    ASSERT_TRUE(tm5.matchingMatricies(m4, vect4));     

    linear_algebra::Matrix m5(10, 2);
    std::vector<std::vector<double>> vect5 = m5.getMatrix();   
    ASSERT_TRUE(tm5.matchingMatricies(m5, vect5));   
}

/*
This test will test the getRows() function in the Matrix class
*/
TEST(Test_Method, getRows){
    linear_algebra::Matrix m1(4, 5);
    ASSERT_EQ(4, m1.getRows());

    linear_algebra::Matrix m2(11, 10);
    ASSERT_EQ(11, m2.getRows());

    linear_algebra::Matrix m3(14, 16);
    ASSERT_EQ(14, m3.getRows());
    ASSERT_NE(23, m3.getCols());

    linear_algebra::Matrix m4(4, 24);
    ASSERT_EQ(4, m4.getRows());
    ASSERT_NE(4, m4.getCols());
}

/*
This test will test the getCols() function in the Matrix class
*/
TEST(Test_Method, getCols){
    linear_algebra::Matrix m1(5, 10);
    ASSERT_EQ(10, m1.getCols());
    ASSERT_NE(12, m1.getCols());

    linear_algebra::Matrix m2(10, 11);
    ASSERT_EQ(11, m2.getCols());
    ASSERT_NE(19, m2.getCols());

    linear_algebra::Matrix m3(13, 14);
    ASSERT_EQ(14, m3.getCols());
    ASSERT_NE(15, m3.getCols());
}

/*
This test will test the getDimensions function in the Matrix class
*/
TEST(Test_Method, getDimensions){
    testMatrix tm6;

    linear_algebra::Matrix m1(3, 2);
    std::tuple<unsigned int, unsigned int> m1d = m1.getDimensions();
    ASSERT_TRUE(tm6.correctDimensions(m1, std::get<0>(m1d), std::get<1>(m1d)));

    linear_algebra::Matrix m2(13, 2);
    std::tuple<unsigned int, unsigned int> m2d = m2.getDimensions();
    ASSERT_TRUE(tm6.correctDimensions(m2, std::get<0>(m2d), std::get<1>(m2d)));

    linear_algebra::Matrix m3(3, 22);
    std::tuple<unsigned int, unsigned int> m3d = m3.getDimensions();
    ASSERT_TRUE(tm6.correctDimensions(m3, std::get<0>(m3d), std::get<1>(m3d)));

    linear_algebra::Matrix m4(13, 42);
    std::tuple<unsigned int, unsigned int> m4d = m4.getDimensions();
    ASSERT_TRUE(tm6.correctDimensions(m4, std::get<0>(m4d), std::get<1>(m4d)));
}

/*
This test will test the setRows function in the Matrix class
*/
TEST(Test_Method, setRows){
    linear_algebra::Matrix m1(3, 4);
    m1.setRows(5);
    ASSERT_EQ(m1.getRows(), 5);

    linear_algebra::Matrix m2(3, 4);
    m1.setRows(10);
    ASSERT_EQ(m1.getRows(), 10);
    
    linear_algebra::Matrix m3(3, 4);
    m1.setRows(7);
    ASSERT_EQ(m1.getRows(), 7);
}

/*
This test will test the setColumns function in the Matrix class
*/
TEST(Test_Method, setCols){
    linear_algebra::Matrix m1(3, 4);
    m1.setColumns(5);
    ASSERT_EQ(m1.getCols(), 5);

    linear_algebra::Matrix m2(3, 4);
    m1.setColumns(10);
    ASSERT_EQ(m1.getCols(), 10);
    
    linear_algebra::Matrix m3(3, 4);
    m1.setColumns(7);
    ASSERT_EQ(m1.getCols(), 7);
}

/*
This test will test the setMatrix function in the Matrix class
*/
TEST(Test_Method, setMatrix){
    testMatrix tm7;

    linear_algebra::Matrix m1;
    std::vector<std::vector<double>> vecta = {
        {3, 4, 25, 6},
        {4, 5, 6, 7},
        {5, 6, 7, 8}
    };
    m1.setMatrix(vecta);
    ASSERT_TRUE(tm7.matchingMatricies(m1, vecta));
    ASSERT_TRUE(tm7.matchingMatricies(m1, vecta));

    linear_algebra::Matrix m2;
    std::vector<std::vector<double>> vectb = {
        {3, 234, 25, 8},
        {4, 45, 6, 5},
        {5, 6, 4, 8}
    };
    m2.setMatrix(vecta);
    ASSERT_TRUE(tm7.matchingDimensions(m2, vectb));
    ASSERT_TRUE(tm7.matchingDimensions(m2, vectb));


}

/*
This test will test the getVal function in the Matrix class
*/
TEST(Test_Method, getVal){
    linear_algebra::Matrix m1;
    std::vector<std::vector<double>> vecta = {
        {3, 4, 5},
        {5, 6, 7},
        {8, 9, 10} 
    };
    m1.setMatrix(vecta);
    

    ASSERT_EQ(3, m1.getVal(0, 0));
    ASSERT_EQ(10, m1.getVal(2, 2));
    ASSERT_THROW(m1.getVal(3, 3), LinearAlgebraRunTimeException);
}

/*
This test will test the isSquare function in the Matrix class
*/
TEST(Test_Method, isSquare){
    linear_algebra::Matrix m1(3, 4);
    ASSERT_FALSE(m1.isSquare());

    linear_algebra::Matrix m2(4, 4);
    ASSERT_TRUE(m2.isSquare());

    linear_algebra::Matrix m3(5, 6);
    ASSERT_FALSE(m3.isSquare());
}
