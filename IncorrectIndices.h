//
// Created by ola on 27.11.17.
//

#ifndef RCMATRIX_INCORRECTINDICES_H
#define RCMATRIX_INCORRECTINDICES_H

#include <ostream>

class IncorrectIndices: public std::exception {
    std::string a;
public:
    explicit IncorrectIndices(unsigned int i);
    const char* what() const noexcept override;
};



#endif //RCMATRIX_INCORRECTINDICES_H