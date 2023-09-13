#ifndef COLORS_H
#define COLORS_H

#include <cmath>
#include <algorithm>
#include "QColor"

class XYZ
{
private:
    double x;
    double y;
    double z;

    double F(double x_);
    double Flab(double x_);

public:
    XYZ(double X, double Y, double Z);

    RGB &toRGB();
    CMYK &toCMYK();
    HSV &toHSV();
    HLS &toHLS();
    LAB &toLAB();
};

class Lab
{
private:
    double L;
    double a;
    double b;

    double F(double x_);

public:
    Lab(double L_, double a_, double b_);

    RGB &toRGB();
    CMYK &toCMYK();
    HSV &toHSV();
    HLS &toHLS();
    XYZ &toXYZ();
};

#endif
