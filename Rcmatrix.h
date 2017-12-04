//
// Created by ola on 27.11.17.
//

#ifndef RCMATRIX_RCMATRIX_H
#define RCMATRIX_RCMATRIX_H

#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

class Rcmatrix{
    struct Rcarray;
    Rcarray* data;
public:
    class Cref;
    Rcmatrix(unsigned int i, unsigned int j, double **p);
    Rcmatrix(unsigned int i, unsigned int j);
    Rcmatrix(const Rcmatrix& source);
    ~Rcmatrix();
    Rcmatrix& operator=(const Rcmatrix&);
    Rcmatrix operator-() const;
    Rcmatrix& operator+=(const Rcmatrix &);
    Rcmatrix operator+(const Rcmatrix &) const;
    Rcmatrix& operator-=(const Rcmatrix &);
    Rcmatrix operator-(const Rcmatrix &) const;
    Rcmatrix& operator*=(const Rcmatrix &);
    Rcmatrix operator*(const Rcmatrix&) const;
    bool operator==(const Rcmatrix& s);
    friend ostream& operator<<(ostream&, const Rcmatrix&);
    friend istream& operator>>(istream&, const Rcmatrix&);
    double operator()(unsigned int i, unsigned int j) const;
    Cref operator()(unsigned int i, unsigned int j);
private:
    void check (unsigned int i, unsigned int j) const;
    double read(unsigned int i, unsigned int j) const;
    void write(unsigned int i, unsigned int j, double c);
	void checkDimension(const Rcmatrix&);
};


#endif //RCMATRIX_RCMATRIX_H