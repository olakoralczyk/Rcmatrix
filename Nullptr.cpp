//
// Created by ola on 27.11.17.
//

#include "Nullptr.h"

const char *Nullptr::what() const noexcept {
    return "A non-null pointer is needed";
}