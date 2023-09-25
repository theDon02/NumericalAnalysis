#include "project_management/projectDriver.h"
#include "linear_algebra/linear_algebra.h"

void projectDriver::project::aboutProgram() {
    std::cout << "\nWelcome to Numerical Analysis project!\n"
              << "This project will be dealing with numerical analyses.\n"
              << "As of right now you this program can only deal with solving system of linear equations\n";   

    std::cout << "As this program gets developed, it will ask you for what you want to do\n"
              << "Here are the options possible for this program\n"
              << "1. Solving a system of linear equations\n";   

    std::cout << "If you want to run the linear euquations calculator use the following command input\n"
              << "./numerical_solver <int> <string> <int>\n\n";    
}

void projectDriver::project::runProgram(int argc, char* argv[]){
    // std::cout << argv[0] << "\n";
    // std::cout << argv[1] << "\n";
    // std::cout << argv[2] << "\n";
    //It will run the project
    linear_algebra::Matrix m(argv[1]);

    linear_algebra::Matrix m2(argv[2]);

    linear_algebra::Matrix m3 = m2.multiply(&m);

    m3.printMatrix();
}

