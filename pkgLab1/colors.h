#ifndef COLORS_H
#define COLORS_H

#include <cmath>
#include "QColor"

class ColorSystem
{
public:
    virtual ColorSystem *toRGB() = 0;
    virtual ColorSystem *toCMYK() = 0;
    virtual ColorSystem *toHSV() = 0;
    virtual ColorSystem *toHLS() = 0;
    virtual ColorSystem *toXYZ() = 0;
    virtual ColorSystem *toLAB() = 0;
};

///////////////////////////////////////////////////////////////////////////////////

class RGB : public ColorSystem
{
private:
    int r;
    int g;
    int b;

    double fXyz(double x);
    double fDop(double x);

public:
    RGB(int R, int G, int B);

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class CMYK : public ColorSystem
{
private:
    double c;
    double m;
    double y;
    double k;

public:
    CMYK(double C, double M, double Y, double K);

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class HSV : public ColorSystem
{
private:
    double h;
    double s;
    double v;

public:
    HSV(double H, double S, double V);

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class HLS : public ColorSystem
{
private:
    double h;
    double l;
    double s;

public:
    HLS(double H, double L, double S);

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class XYZ : public ColorSystem
{
private:
    double x;
    double y;
    double z;

    double F(double x_);
    double Flab(double x_);

public:
    XYZ(double X, double Y, double Z);

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

///////////////////////////////////////////////////////////////////////////////////

class Lab : public ColorSystem
{
private:
    double L;
    double a;
    double b;

    double F(double x_);

public:
    Lab(double L_, double a_, double b_);

    ColorSystem *toRGB() override;
    ColorSystem *toCMYK() override;
    ColorSystem *toHSV() override;
    ColorSystem *toHLS() override;
    ColorSystem *toXYZ() override;
    ColorSystem *toLAB() override;
};

#endif
