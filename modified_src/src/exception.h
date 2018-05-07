#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>

class Exception : public std::exception {
    private:
        const char* reason;
        
    public:
        Exception(const char* msg);
        const char* what() const throw();
};

#endif /* EXCEPTION_H */

