#include "TVector.h"

TVector::~TVector()//+
{
    delete[] Data;
}

TVector::TVector()//+
{
    Data = nullptr;
    Len = 0;
}

TVector::TVector(const TVector & rhs)//+
{
    Len = rhs.Len;
    Data = new double[Len];
    memcpy(Data, rhs.Data, Len * sizeof(double));
}

TVector::TVector(const double * const data, const size_t len)//+
{
    Len = len;
    Data = new double[Len];
    memcpy(Data, data, Len * sizeof(double));
}

TVector & TVector::operator=(const TVector & rhs)//+
{
    if (&rhs == this) return *this;

    Len = rhs.Len;
    delete[] Data;
    Data = new double[Len];
    memcpy(Data, rhs.Data, Len * sizeof(double));
    return *this;
}

TVector & TVector::operator+=(const double * const data)//+
{
    double * newData = new double[Len * 2];
    memcpy(newData, data, Len * sizeof(double));
    memcpy(newData + Len, Data, Len * sizeof(double));


    Len *= 2;
    delete[] Data;
    Data = newData;
    return *this;
}

double TVector::operator[](size_t index) const//+
{
    return Data[index];
}

double& TVector::operator[](size_t index)//+
{
    return Data[index];
}

double * operator+(const TVector & a ,const double * const b)//+
{
    size_t n = a.getLen();
    size_t ln = 2 * n;
    double * res = new double[ln];
    size_t x = 0;
    for (x = 0; x < n; x++)
        res[x] = a[x];
    for (x = n; x < 2 * n; x++)
        res[x] = b[x-n];

    return res;
}

size_t TVector::getLen()const
{
    return Len;
}