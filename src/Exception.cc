#include "Exception.h"

Exception::Exception(const char* msg){
    reason = msg;
}

const char* Exception::what() const throw(){
    return reason;
}



