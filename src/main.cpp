#include "project_management/projectDriver.h"

int main(int argc, char* argv[]) {
    //Project variable
    projectDriver::project project = projectDriver::project();

    //Print what this program is about
    project.aboutProgram();

    //Run the program
    project.runProgram(argc, argv);
    
        
    return 0;
}