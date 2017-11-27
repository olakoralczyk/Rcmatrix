cmake_minimum_required(VERSION 3.8)
project(Rcmatrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Dimension.cpp Dimension.h IncorrectIndices.cpp IncorrectIndices.h Nullptr.cpp Nullptr.h Rcmatrix.cpp Rcmatrix.h)
add_executable(Rcmatrix ${SOURCE_FILES})