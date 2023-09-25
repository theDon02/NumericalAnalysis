# This bash file will be in charge of running the project, it will take the inputs of the user and run the program accordingly
# Therefore, it will be necessary for the user to change the contents of this file to see the program run accordingly

#!/bin/bash

# Calling to run the clean repository 
chmod u+x cleanRepository.sh
./cleanRepository.sh

# Compiling the program and linking all the libraries to create an appropiate executable
if [[ -d ./build ]]; then
    echo "Deleting the build folder!"
    rm -rf ./build
fi

mkdir build
cd ./build
cmake ../
make

# User do not touch anything from above!!!! Just change the contents from below!
# Below is where the user will input their own tests and see the results by the program accordingly.