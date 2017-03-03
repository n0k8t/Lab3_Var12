#ifndef LAB3_VAR12_TVECTOR_H
#define LAB3_VAR12_TVECTOR_H

#pragma once
#include <iostream>

class TVector
{
private:
    double * Data;
    size_t Len;
public:

    ~TVector();

    TVector();

    TVector(const TVector & rhs);

    TVector(const double * const data, const size_t len);

    TVector & operator=(const TVector & rhs);

    TVector & operator+=(const double * const data);

    size_t getLen()const;

    double operator[](size_t index) const;
    double& operator[](size_t index);
};

double *  operator+(const TVector & a ,const double * const b);


#endif //LAB3_VAR12_TVECTOR_H
