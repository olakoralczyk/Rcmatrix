//
// Created by ola on 27.11.17.
//

#ifndef RCMATRIX_NULLPTR_H
#define RCMATRIX_NULLPTR_H

#include <exception>

class Nullptr: public std::exception {
    const char* what() const noexcept override;
};


#endif //RCMATRIX_NULLPTR_H