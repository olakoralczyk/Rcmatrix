//
// Created by ola on 27.11.17.
//

#include "Rcmatrix.h"
#include "IncorrectIndices.h"
#include "Nullptr.h"
#include "Dimension.h"

struct Rcmatrix::Rcarray {
    double** s;
    unsigned int sizex, sizey;
    int reference;

    Rcarray(unsigned int nsize, unsigned int msize) {
        reference=1;
        sizex = nsize;
        sizey = msize;
        s = new double*[sizex];
        unsigned int i;
        try {
            for (i=0; i < sizex; ++i) {
                s[i] = new double[sizey];
                for (unsigned int j = 0; j < i; ++j) {
                    s[i][j] = 0;
                }
            }
        }
        catch(...) {
            for (unsigned int j = 0; j <i; ++j) {
                delete [] s[j];
            }
            delete [] s;
            throw;
        }
    }

    Rcarray(unsigned int nsize, unsigned int msize, double** p) {
        reference=1;
        sizex = nsize;
        sizey = msize;
        p = new double*[sizex];
        unsigned int i;
        try {
            for (i=0; i < sizex; ++i) {
                s[i] = new double[sizey];
                for (unsigned int j = 0; j < i; ++j) {
                    s[i][j] = p[i][j];
                }
            }
        }
        catch(...) {
            for (unsigned int j = 0; j <i; ++j) {
                delete [] s[j];
            }
            delete [] s;
            throw;
        }
    }

    ~Rcarray() {
        for (unsigned int i = 0; i < sizex; ++i) {
            delete [] s[i];
        }
        delete [] s;
    }

    Rcarray* detach() {
        if(reference == 1)
            return this;
        auto*t = new Rcarray(*this);
        reference--;
        return t;
    }

    void assign(unsigned int nsize, unsigned int msize, double **p) {
        if(nsize != sizex || msize != sizey) {
            nsize = sizex;
            msize = sizey;
            auto** ns = new double*[nsize];
            unsigned int i;
            try {
                for (i = 0; i < sizex; ++i) {
                    s[i] = new double[msize];
                    for (unsigned int j = 0; j < sizey; ++j) {
                        s[i][j] = p[i][j];
                    }
                }
            }
            catch (...) {
                for (unsigned int j = 0; j < i; ++j) {
                    delete [] s[j];
                }
                delete [] s;
                throw;
            }
            delete [] s;
            s = ns;
        }
        else {
            for (unsigned int i = 0; i < sizex; ++i) {
                for (unsigned int j = 0; j < sizey; ++j) {
                    s[i][j] = p[i][j];
                }
            }
        }
    }

    Rcarray(const Rcarray& source) : Rcarray(source.sizex, source.sizey) {
        unsigned i;
        for (i=0; i < sizex; ++i) {
            for (unsigned int j = 0; j < sizey; ++j){
                s[i][j] = source.s[i][j];
            }
        }
    }
    Rcarray& operator=(const Rcarray&) = delete;

};

class Rcmatrix::Cref {
    friend class Rcmatrix;
    Rcmatrix& s;
    unsigned int i, j;
    Cref (Rcmatrix& ss, unsigned int ii, unsigned int jj): s(ss), i(ii), j(jj) {};
public:
    explicit operator double() const {
        return s.read(i, j);
    }
    Rcmatrix::Cref& operator = (double c) {
        s.write(i, j, c);
        return *this;
    }
};

Rcmatrix::Rcmatrix(unsigned int i, unsigned int j) {
    data = new Rcarray(i, j);
}

Rcmatrix::Rcmatrix(unsigned int i, unsigned int j, double** s) {
    if (s == nullptr)
        throw Nullptr();
    data = new Rcarray(i, j, s);
}

Rcmatrix::Rcmatrix(const Rcmatrix& x) {
    x.data->reference++;
    data = x.data;
}

Rcmatrix::~Rcmatrix() {
    if(--data->reference == 0)
        delete data;
}

Rcmatrix& Rcmatrix::operator=(const Rcmatrix & x)
{
    x.data->reference++;
    if(--data->reference == 0)
        delete data;
    else if (data->reference==1)
        data->assign(data->sizex, data->sizey, data->s);
    data = x.data;
    return *this;
}

Rcmatrix& Rcmatrix::operator+=(const Rcmatrix& RHS) {
	checkDimension(RHS);
    data = data->detach();
    for (unsigned int i = 0; i < data->sizex; ++i) {
        for (unsigned int j = 0; j < data->sizey; ++j) {
            data->s[i][j] += RHS.data->s[i][j];
        }
    }
    return *this;
}

Rcmatrix Rcmatrix::operator+(const Rcmatrix& s) const {
    return Rcmatrix(*this) += s;
}

Rcmatrix Rcmatrix::operator-() const {
    Rcmatrix negation(*this);
    for (unsigned int i = 0; i < data->sizex; ++i) {
        for (unsigned int j = 0; j < data->sizey; ++j) {
            negation.data->s[i][j] *= -1;
        }
    }
    return negation;
}

Rcmatrix& Rcmatrix::operator-=(const Rcmatrix& RHS) {
	checkDimension(RHS);
    data = data->detach();
    for (unsigned int i = 0; i < data->sizex; ++i) {
        for (unsigned int j = 0; j < data->sizey; ++j) {
            data->s[i][j] -= RHS.data->s[i][j];
        }
    }
    return *this;
}

Rcmatrix Rcmatrix::operator-(const Rcmatrix& RHS) const {
    return *this + (-RHS);
}

Rcmatrix &Rcmatrix::operator*=(const Rcmatrix& s) {
    *this = *this * s;
    return *this;
}

Rcmatrix Rcmatrix::operator*(const Rcmatrix& RHS) const {
    if (data->sizey != RHS.data->sizex)
        throw Dimension(data->sizex, data->sizey, RHS.data->sizex, RHS.data->sizey);
    Rcmatrix product(data->sizex, RHS.data->sizey);
    for (unsigned int i = 0; i < data->sizex; ++i) {
        for (unsigned int j = 0; j < RHS.data->sizey; ++j) {
            double cellSum = 0;
            for (unsigned int k = 0; k < data->sizey; ++k)
                cellSum += data->s[i][k] * RHS.data->s[k][j];
            product.data->s[i][j] = cellSum;
        }
    }
    return product;
}

bool Rcmatrix::operator==(const Rcmatrix &RHS) {
    if (this->data->sizey == RHS.data->sizey && this->data->sizex == RHS.data->sizey) {
        for (unsigned int i = 0; i < this->data->sizex; ++i) {
            for (unsigned int j = 0; i < this->data->sizey; ++j) {
                if (this->data->s[i][j] != RHS.data->s[i][j]) {
                    return false;
                }
            }
        } return true;
    } return false;
}

ostream& operator<<(ostream& o, const Rcmatrix& s) {
    for (unsigned int i = 0; i < s.data->sizex; ++i) {
        for (unsigned int j = 0; j < s.data->sizey; ++j) {
            o.precision(2);
            o << s.data->s[i][j] << "\t";
        }
        o << '\n';
    }
    return o;
}

istream& operator>>(istream &input, const Rcmatrix &M) {
    for (unsigned int i = 0; i < M.data->sizex; ++i) {
        for (unsigned int j = 0; j < M.data->sizey; ++j) {
            input >> M.data->s[i][j];
        }
    }
    return input;
}

double Rcmatrix::operator()(unsigned int i, unsigned int j) const {
    check(i, j);
    return data->s[i][j];
}

Rcmatrix::Cref Rcmatrix::operator()(unsigned int i, unsigned int j) {
    check(i, j);
    return {*this, i, j};
}

void Rcmatrix::check (unsigned int i, unsigned int j) const {
    if(data->sizex <= i) {
        throw IncorrectIndices(data->sizex);
    }
    if (data->sizey <= j) {
        throw IncorrectIndices(data->sizey);
    }
}
double Rcmatrix::read(unsigned int i, unsigned int j) const {
    return data->s[i][j];
}
void Rcmatrix::write(unsigned int i, unsigned int j, double c) {
    data = data->detach();
    data->s[i][j] = c;
}

void Rcmatrix::checkDimension(const Rcmatrix& RHS) {
	if (data->sizex != RHS.data->sizex || data->sizey != RHS.data->sizey) {
        throw Dimension(data->sizex, data->sizey, RHS.data->sizex, RHS.data->sizey);
    }
}