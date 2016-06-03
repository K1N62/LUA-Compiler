#pragma once

#include <exception>
#include <string>

//! Class for handling simple errors
/**
* @author Jim Ahlstrand
*/
class Error : public std::exception {
public:
    // Constructors
    // ---------------------------------------
    //! Constructor with msg
    Error(std::string msg) : msg(msg) {}

    // Methods
    // ---------------------------------------
    //! Overloads the what function
    /**
    * @return pointer to error message
    */
    const char* what() { return this->msg.c_str(); }
private:
    std::string msg;
};
