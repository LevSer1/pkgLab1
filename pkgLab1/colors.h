#ifndef COLORS_H
#define COLORS_H

class XYZ
{
private:
    double x;
    double y;
    double z;

public:
    XYZ(double X, double Y, double Z);

    RGB &toRGB() const;
    LAB &toLAB() const;
};

#endif
