#include "colors.h"

XYZ::XYZ(double X = 0, double Y = 0, double Z = 0)
{
    if (X > 95.048 || Y > 100.0 || Z > 108.884)
    {
        x = 0;
        y = 0;
        z = 0;
        throw "error";
    }

    x = X;
    y = Y;
    z = Z;
}

RGB &XYZ::toRGB() const
{

}

LAB &XYZ::toLAB() const
{

}
