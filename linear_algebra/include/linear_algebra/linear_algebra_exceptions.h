#ifndef LINEAR_ALGEBRA_EXCEPTION_H
#define LINEAR_ALGEBRA_EXCPETION_H

#include <iostream>
#include <string>
#include <chrono>
#include <stdexcept>

enum LogLevel {
    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    SEVERE = 3
};

class LinearAlgebraRunTimeException : public std::exception {
    private:
        std::string _myMessage;
        LogLevel _level;
    public:
        /*
        This constructor will take an inputted string to define the error inplace
        @param const std::string error: This is the error message of the exception
        @param const inst code: This the code level that will be inputted. 

        NOTE: The code level will be determined by the developer.
        */
        LinearAlgebraRunTimeException(const std::string error, const int code);

        /*
        This function will return the Logging Error of the exception
        */
        int returnLogLevel(){return _level;};

        /*
        This function will determine the Logging Level depending on the code
        @param const int code: This is the code level that will determine the LogLevel
        */
        void determineLogLevel(const int code);

        /*
        This function will create resulting error message that will be printed out to the user
        @param const std::string& message: Thsi is the message that will be printed to the user

        NOTE: The message that will be created will have the LOGGING level and message
        */
        void createErrorMessage(const std::string& message);

        /*
        This function will print out the message to the user
        */
        std::string& printMessage(){return _myMessage;};
};

#endif
