//
// Created by ola on 27.11.17.
//

#ifndef RCMATRIX_DIMENSION_H
#define RCMATRIX_DIMENSION_H

#include <iostream>

class Dimension: public std::exception {
    unsigned int ai, aj, bi, bj;
    std::string a;
public:
    Dimension(unsigned int ai, unsigned int aj, unsigned int bi, unsigned int bj);
    const char* what() const noexcept override;
};


#endif //RCMATRIX_DIMENSION_H
