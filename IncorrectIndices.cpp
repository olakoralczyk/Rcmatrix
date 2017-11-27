//
// Created by ola on 27.11.17.
//

#include "IncorrectIndices.h"

IncorrectIndices::IncorrectIndices(unsigned int i) : i(i) {
    a.append("index i: ");
    a.append(std::to_string(i));
    a.append(" is not in range");
}

const char *IncorrectIndices::what() const noexcept {
    return a.c_str();
}