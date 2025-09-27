#ifndef HW1_EXCEPTION_H_
#define HW1_EXCEPTION_H_

#include <stdexcept>

class exit_exception : public std::exception {
    const char* what() const noexcept {
        return "Exiting the application.";
    } 
};

#endif