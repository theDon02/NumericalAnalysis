#ifndef USER_INPUT_H
#define USER_INPUT_H
#include <iostream>
#include <map>
#include <vector>
#include <string>

namespace projectDriver{

    enum class projectActions {
        LinerEquations
    };

    class project {
        public:
            //Constructor of this class
            project(){};
            
            //Destructor of this class
            ~project(){};

            //This function will print to the user the possibilites of this program
            void aboutProgram();

            //This function will run the program after obtaining all the information from the user
            void runProgram(int argc, char** argv);
    };

    class projectInput {
        private:
            std::vector<std::string> _userInputs;
            projectActions result;
        public:
            //It will be used to analyze the inputs from the user
            projectInput(int, char* argv[]);

            //Destructor of this class
            ~projectInput(){};


    };
}

#endif