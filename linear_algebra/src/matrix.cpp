#include "linear_algebra/matrix.h"

linear_algebra::Matrix::Matrix(unsigned int rows, unsigned int columns) {
    _rows = rows;
    _columns = columns;
    _matrix.resize(_rows, std::vector<double>(_columns, 0.));
}

linear_algebra::Matrix::Matrix(unsigned int rows, unsigned int columns, std::string fileName) {
    //Filling out the private variables
    _rows = rows; _columns = columns;

    //Fill out the matrix based on the input file
    linear_algebra::Matrix::filloutMatrix(fileName, true); 
}

linear_algebra::Matrix::Matrix(std::string inputFile){
    
    //Filling out the matrix
    linear_algebra::Matrix::filloutMatrix(inputFile, false);
}

linear_algebra::Matrix::Matrix(std::vector<std::vector<double>>& input) {
    _matrix = input;
    _rows = (unsigned int)(input.size());
    _columns = (unsigned int)(input)[0].size();
}

void linear_algebra::Matrix::filloutMatrix(std::string inputFile, bool hasDim){
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
                    if(rows != _rows) {
                        std::cout << "\nfillOutMatrix: The rows value in file and inputted row are not the same\n";
                        std::exit(1);
                    }else if(cols != _columns){
                        std::cout << "\nfillOutMatrix: The columns value in file and inputted columns are not the same\n";
                        std::exit(1);
                    }
                }

                //Creating a blank matrix if the user did not input size of the matrix
                _rows = rows;
                _columns = cols;
                _matrix.resize(rows, std::vector<double>(cols, 0));
                
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
                    setValueInMatrix(curr_rows, curr_cols, std::stod(temp));

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

void linear_algebra::Matrix::setValueInMatrix(unsigned int r, unsigned int c, double val){
    if(r < 0 || r > _rows){
        std::cout << "\nsetValueInMatrix: Invalid row input at position: (" << r << ", " <<  c << ") with val: " << val << "\n";
        std::exit(1);
    }

    if(c < 0 || c > _columns){
        std::cout << "\nsetValueInMatrix: Invalid col input  at position: (" << r << ", " <<  c << ") with val: " << val << "\n";
        std::exit(1);
    }

    //Setting value
    _matrix[r][c] = val;
}

double linear_algebra::Matrix::getValueInMatrix(unsigned int r, unsigned int c){
    if(r < 0 || r > _rows){
        std::cout << "\ngetValueInMatrix: Invalid row input at position: (" << r << ", " <<  c << ") \n";
        std::exit(1);
    }

    if(c < 0 || c > _columns){
        std::cout << "\ngetValueInMatrix: Invalid col input at position: (" << r << ", " <<  c << ") \n";
        std::exit(1);
    }
    
    return _matrix[r][c];
}

void linear_algebra::Matrix::printMatrix() {
    std::cout << "\nPrinting Matrix:\n";
    for(unsigned int i = 0; i < _rows; i++) {
        std::cout << "| ";
        for(unsigned int j = 0; j < _columns; j++) {
            std::cout << std::fixed << std::setw(10) << std::setprecision(5) << _matrix[i][j] << " ";
        }
        std::cout << "|\n";
    }
}

linear_algebra::Matrix linear_algebra::Matrix::multiply(linear_algebra::Matrix& input){
    //Check the number of columns and rows match
    if(_columns != input.getRows()){
        std::cout << "\nrows: " << _rows << " cols: " << _columns << "\n";
        std::cout << "\nrows: " << input.getRows() << " cols: " << input.getCols() << "\n";
        std::cout << "multiply: columns and rows don't match\n";
        std::exit(1);
    }

    //Resulting Matrix
    linear_algebra::Matrix result(_rows, input.getCols());

    for(unsigned int i = 0; i < _rows; i++){
        for(unsigned int j = 0; j < input.getCols(); j++){
            double val = 0;
            for(unsigned int z = 0; z < _columns; z++){
                val = val + (getValueInMatrix(i, z) * input.getValueInMatrix(z, j)); 
            }
            result.setValueInMatrix(i, j, val);
        }
    }

    return result;
}

linear_algebra::Matrix linear_algebra::Matrix::getTranspose(){
    Matrix newMatrix(_columns, _rows);

    for(int i = 0; i < _rows; i++){
        for(int j = 0; j < _columns; j++){
            newMatrix.setValueInMatrix(j, i, getValueInMatrix(i, j));
        }
    }

    return newMatrix;
}