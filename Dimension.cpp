//
// Created by ola on 27.11.17.
//

#include "Dimension.h"

Dimension::Dimension(unsigned int ai, unsigned int aj, unsigned int bi, unsigned int bj) {
    a.append("Improper dimensions for operation, LHS ");
    a.append(std::to_string(ai));
    a.append(" x ");
    a.append(std::to_string(aj));
    a.append(" RHS ");
    a.append(std::to_string(bi));
    a.append(" x ");
    a.append(std::to_string(bj));
}

const char* Dimension::what() const noexcept {
    return a.c_str();
}