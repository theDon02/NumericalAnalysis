#include "linear_algebra/linear_algebra_exceptions.h"
#include "linear_algebra/matrix.h"

linear_algebra::Matrix::Matrix(const unsigned int rows, const unsigned int columns) {
    _dimension = std::make_tuple(rows, columns);
    _matrix.resize(rows, std::vector<double>(columns, 0.));
}

linear_algebra::Matrix::Matrix(const unsigned int rows, const unsigned int columns, std::string fileName) {
    _dimension = std::make_tuple(rows, columns);
    linear_algebra::Matrix::filloutMatrix(fileName, true); 
}

linear_algebra::Matrix::Matrix(const std::string inputFile){
    linear_algebra::Matrix::filloutMatrix(inputFile, false);
}

linear_algebra::Matrix::Matrix(const std::vector<std::vector<double>>& input) {
    _matrix = input;
    _dimension = std::make_tuple((unsigned int)(input.size()), (unsigned int)(input)[0].size());
}

void linear_algebra::Matrix::filloutMatrix(const std::string inputFile, bool hasDim){
    //Create an inputfile variable
    std::ifstream fileObject(inputFile);

    //string that will be used to get the values
    std::string fileString;

    //Get a line counter
    int lineCounter = 0;

    //Number of rows and columns
    unsigned int rows = 0, cols = 0;

    //Current  matrix counter
    unsigned int curr_rows = 0, curr_cols = 0;

    //Get 
    while(getline(fileObject, fileString)){
        //To obtain the rows and columns only
        if(lineCounter < 2){
            if(lineCounter == 0){
                rows = (unsigned int)std::stoi(fileString);
            }else{
                cols = (unsigned int)std::stoi(fileString);
            }

            if(lineCounter == 1){
                if(hasDim){
                    try{
                        if(rows != std::get<0>(_dimension)) {
                            throw LinearAlgebraRunTimeException("Matrix::fillOutMatrix: The rows value in file and inputted row are not the same", 3);
                        }else if(cols != std::get<1>(_dimension)){
                            throw LinearAlgebraRunTimeException("Matrix::fillOutMatrix: The columns value in file and inputted columns are not the same", 3);
                        }
                    } catch(LinearAlgebraRunTimeException& e) {
                        e.printMessage();
                        std::exit(1);
                    }
                }else {
                    //Creating a blank matrix if the user did not input size of the matrix
                    _dimension = std::make_tuple(rows, cols);
                    _matrix.resize(rows, std::vector<double>(cols, 0));
                }
                
            }

        }else{
            //temporary string
            std::string temp;

            //Loop through the fileString
            for(unsigned int i = 0; i < fileString.size(); i++){
                if(fileString[i] != ' ' || i + 1 == fileString.size()){
                    //Adding the current index to temp variable
                    temp.push_back(fileString[i]);
                }

                //End of the string
                if(fileString[i] == ' ' || i + 1 == fileString.size()){
                    setVal(curr_rows, curr_cols, std::stod(temp));

                    if(fileString[i] == ' '){
                        curr_cols++;
                    }

                    if(i + 1 == fileString.size()){
                        curr_cols = 0;
                        curr_rows++;
                    }

                    //Clearing the temporary string
                    temp.clear();
                }
            }
        }

        //Increase the counter
        lineCounter++;
    }

    //Close the file
    fileObject.close(); 
}

void linear_algebra::Matrix::setVal(unsigned int r, unsigned int c, double val){
    try {
        if(r < 0 || r > std::get<0>(_dimension)){
            std::string errorM = "Matrix::setValueInMatrix: Invalid row input at position: (" + std::to_string(r) + ", " +  std::to_string(c) + ") with val: " + std::to_string(val);
            throw LinearAlgebraRunTimeException(errorM, 3);
        }

        if(c < 0 || c > std::get<1>(_dimension)){
            std::string errorM = "Matrix::setValueInMatrix: Invalid column input  at position: (" + std::to_string(r) + ", " + std::to_string(c) + ") with val: " + std::to_string(val);
            throw LinearAlgebraRunTimeException(errorM, 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        e.printMessage();
        std::exit(1);
    }

    //Setting value
    _matrix[r][c] = val;
}

double linear_algebra::Matrix::getVal(unsigned int r, unsigned int c){
    try {
        if(r < 0 || r > std::get<0>(_dimension)){
            std::string errorM = "Matrix::getValueInMatrix: Invalid row input at position: (" + std::to_string(r) + ", " +  std::to_string(c) + ")";
            throw LinearAlgebraRunTimeException(errorM, 3);
        }

        if(c < 0 || c > std::get<1>(_dimension)){
            std::string errorM = "Matrix::getValueInMatrix: Invalid column input at position: (" + std::to_string(r) + ", " + std::to_string(c) + ")";
            throw LinearAlgebraRunTimeException(errorM, 3);
        }
    } catch(LinearAlgebraRunTimeException& e) {
        e.printMessage();
        std::exit(1);
    }
    
    return _matrix[r][c];
}

void linear_algebra::Matrix::printMatrix() {
    std::cout << "\nPrinting Matrix:\n";
    for(unsigned int i = 0; i < std::get<0>(_dimension); i++) {
        std::cout << "| ";
        for(unsigned int j = 0; j < std::get<1>(_dimension); j++) {
            std::cout << std::fixed << std::setw(10) << std::setprecision(5) << _matrix[i][j] << " ";
        }
        std::cout << "|\n";
    }
}