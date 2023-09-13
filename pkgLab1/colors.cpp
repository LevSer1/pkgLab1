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

double XYZ::F(double val)
{
    if (val >= 0.0031308)
    {
        return 1.055 * pow(val, 1 / 2.4) - 0.055;
    }
    else
    {
        return 12.92 * val;
    }
}

double XYZ::Flab(double val)
{
    if (val >= 0.008856)
    {
        return pow(val, 1 / 3);
    }
    else
    {
        return 7.787 * val + 16 / 116;
    }
}

RGB &XYZ::toRGB()
{
    double Rn = 3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100);
    double Gn = -0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100);
    double Bn = 0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100);

    return RGB(255 * F(Rn), 255 * F(Gn), 255 * F(Bn));
}

CMYK &XYZ::toCMYK()
{
    double K = std::min(1.0 - F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100)), 1.0 - F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100)));
    K = std::min(K, 1.0 - F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100)));

    if (K == 1)
    {
        return CMYK(0, 0, 0, 1);
    }

    double C = (1 - F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100)) - K) / (1 - K);
    double M = (1 - F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100)) - K) / (1 - K);
    double Y = (1 - F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100)) - K) / (1 - K);

    return CMYK(C, M, Y, K);
}

HSV &XYZ::toHSV()
{
    double Xf = F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100));
    double Yf = F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100));
    double Zf = F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100));

    double CMax = std::max(Xf, Yf);
    CMax = std::max(CMax, Zf);
    double CMin = std::min(Xf, Yf);
    CMin = std::min(CMax, Zf);

    double delta = CMax - CMin;

    double S, V;

    if (CMax == 0)
    {
        S = 0;
    }
    else
    {
        S = delta / CMax;
    }
    V = CMax;

    QColor temp(255 * F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100)), 255 * F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100)), 255 * F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100)));
    return HSV(temp.hsvHue(), S, V);
}

HLS &XYZ::toHLS()
{
    QColor temp(255 * F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100)), 255 * F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100)), 255 * F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100)));
    return HLS(temp.hslHue(), temp.lightness(), temp.hslSaturation());
}

LAB &XYZ::toLAB()
{
    return LAB(116 * Flab(y / 100.0) - 16, 500 * (Flab(x / 95.047) - Flab(y / 100.0)), 200 * (Flab(y / 100.0) - Flab(z / 108.883)));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Lab::Lab(double L_, double a_, double b_)
{
    if (L_ > 100 || (a_ > 128 || a_ < -128) || (b_ > 128 || b_ < -128))
    {
        L = 0;
        a = 0;
        b = 0;
        throw "error";
    }

    L = L_;
    a = a_;
    b = b_;
}

XYZ &Lab::toXYZ()
{
    // TODO: вставьте здесь оператор return
}
