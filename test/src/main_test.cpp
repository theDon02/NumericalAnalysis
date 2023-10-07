#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char* argv[]){
    std::cout << "\nStarting the testing program!!!\n\n";

    testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}