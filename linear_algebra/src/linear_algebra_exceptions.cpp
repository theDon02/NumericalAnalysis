#include "linear_algebra/linear_algebra_exceptions.h"

LinearAlgebraRunTimeException::LinearAlgebraRunTimeException(const std::string error, const int code){
    //Determine the log level of the operation
    determineLogLevel(code);

    //Create message
    createErrorMessage(error);
}

void LinearAlgebraRunTimeException::determineLogLevel(const int code) {
    switch (code) {
    case 0:
        _level = DEBUG;
        break;
    case 1:
        _level = INFO;
        break;
    case 2:
        _level = WARNING;
    case 3:
        _level = SEVERE;
    default:
        std::cout << "\ndetermineLogLevel: INVALID ERROR CODE\n";
        std::exit(1);
        break;
    }

}

void LinearAlgebraRunTimeException::createErrorMessage(const std::string& message){
    //Create a timestamp of the error message
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::string dateTimeStr(25, '\0');
    std::strftime(&dateTimeStr[0], dateTimeStr.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));

    switch (_level) {
    case DEBUG:
        _myMessage = "\n   DEBUG   " + dateTimeStr + message + "\n";
        break;
    case INFO:
        _myMessage = "\n   INFO   " + dateTimeStr + message + "\n";
        break;
    case WARNING:
        _myMessage = "\n   WARNING   " + dateTimeStr + message + "\n";
        break;
    case SEVERE:
        _myMessage = "\n   SEVERE   " + dateTimeStr + message + "\n";    
    default:
        std::cout << "\ncreateErrorMessage: INVALID ERROR MESSAGE\n";
        std::exit(1);
        break;
    }
}