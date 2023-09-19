#include "colors.h"

RGB::RGB(int R, int G, int B)
{
    if (R > 255 || R < 0 || G > 255 || G < 0 || B > 255 || B < 0)
    {
        throw "ERROR";
        r = 0;
        g = 0;
        b = 0;
    }
    r = R;
    G = g;
    B = b;
}

double RGB::fXyz(double x)
{
    if (x >= 0.04045)
    {
        return pow((x + 0.055) / 1.055, 2.4);
    }
    else
    {
        return x / 12.92;
    }
}

double RGB::fDop(double x)
{
    if (x >= 0.008856)
    {
        return pow(x, 1 / 3);
    }
    else
    {
        return 7.787 * x + 16 / 116;
    }
}

ColorSystem *RGB::toRGB()
{
    return new RGB(r, g, b);
}

ColorSystem *RGB::toCMYK()
{
    double c, m, y, k;

    if (1 - r / 255 <= 1 - g / 255 && 1 - r / 255 <= 1 - b / 255)
    {
        k = 1 - r / 255;
    }
    else if (1 - g / 255 <= 1 - b / 255)
    {
        k = 1 - g / 255;
    }
    else
    {
        k = 1 - b / 255;
    }

    c = (1 - r / 255 - k) / (1 - k);
    m = (1 - g / 255 - k) / (1 - k);
    y = (1 - b / 255 - k) / (1 - k);

    return new CMYK(c, m, y, k);
}

ColorSystem *RGB::toHSV()
{
    double h, s, v;

    double Cmax = std::max(r / 255.0, g / 255.0);
    Cmax = std::max(Cmax, b / 255.0);

    double Cmin = std::min(r / 255.0, g / 255.0);
    Cmin = std::min(Cmin, b / 255.0);

    double delta = Cmax - Cmin;

    if (delta == 0)
    {
        h = 0;
    }
    else if (Cmax == r / 255.0 && g / 255.0 >= b / 255.0)
    {
        h = 60 * (g / 255.0 - b / 255.0) / delta + 0;
    }
    else if (Cmax == r / 255.0 && g / 255.0 < b / 255.0)
    {
        h = 60 * ((g / 255.0 - b / 255.0) / delta) + 360;
    }
    else if (Cmax == g / 255.0)
    {
        h = 60 * (b / 255.0 - r / 255.0) / delta + 2;
    }
    else if (Cmax == b / 255.0)
    {
        h = 60 * (r / 255.0 - g / 255.0) / delta + 4;
    }

    v = Cmax;

    if (Cmax == 0)
    {
        s = 0;
    }
    else
    {
        s = delta / Cmax;
    }

    return new HSV(h, s, v);
}

ColorSystem *RGB::toHLS()
{
    double h, l, s;

    double Cmax = std::max(r / 255.0, g / 255.0);
    Cmax = std::max(Cmax, b / 255.0);

    double Cmin = std::min(r / 255.0, g / 255.0);
    Cmin = std::min(Cmin, b / 255.0);

    double delta = Cmax - Cmin;

    if (delta == 0)
    {
        h = 0;
    }
    else if (Cmax == r / 255.0 && g / 255.0 >= b / 255.0)
    {
        h = 60 * ((g / 255.0 - b / 255.0) / delta) + 0;
    }
    else if (Cmax == r / 255.0 && g / 255.0 < b / 255.0)
    {
        h = 60 * ((g / 255.0 - b / 255.0) / delta) + 360;
    }
    else if (Cmax == g / 255.0)
    {
        h = 60 * ((b / 255.0 - r / 255.0) / delta) + 2;
    }
    else if (Cmax == b / 255.0)
    {
        h = 60 * (r / 255.0 - g / 255.0) / delta + 4;
    }

    l = (Cmax + Cmin) / 2;

    if (delta == 0)
    {
        s = 0;
    }
    else
    {
        s = delta / (1 - abs(2 * l - 1));
    }

    return new HLS(h, l, s);
}

ColorSystem *RGB::toXYZ()
{
    double x, y, z;

    x = 0.4124453 * fXyz(r / 255.0) * 100 + 0.357580 * fXyz(g / 255.0) * 100 + 0.180423 * fXyz(b / 255.0) * 100;
    y = 0.212671 * fXyz(r / 255.0) * 100 + 0.715160 * fXyz(g / 255.0) * 100 + 0.072169 * fXyz(b / 255.0) * 100;
    z = 0.019334 * fXyz(r / 255.0) * 100 + 0.119193 * fXyz(g / 255.0) * 100 + 0.950227 * fXyz(b / 255.0) * 100;

    return new XYZ(x, y, z);
}

ColorSystem *RGB::toLAB()
{
    double l, a, b;

    l = 116 * fDop((0.212671 * fXyz(r / 255.0) * 100 + 0.715160 * fXyz(g / 255.0) * 100 + 0.072169 * fXyz(b / 255.0) * 100) / 100.0) - 16;
    a = 500 * (fDop((0.4124453 * fXyz(r / 255.0) * 100 + 0.357580 * fXyz(g / 255.0) * 100 + 0.180423 * fXyz(b / 255.0) * 100) / 95.047) - fDop((0.212671 * fXyz(r / 255.0) * 100 + 0.715160 * fXyz(g / 255.0) * 100 + 0.072169 * fXyz(b / 255.0) * 100) / 100.0));
    b = 200 * (fDop((0.212671 * fXyz(r / 255.0) * 100 + 0.715160 * fXyz(g / 255.0) * 100 + 0.072169 * fXyz(b / 255.0) * 100) / 100.0) - fDop((0.019334 * fXyz(r / 255.0) * 100 + 0.119193 * fXyz(g / 255.0) * 100 + 0.950227 * fXyz(b / 255.0) * 100) / 108.883));
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

ColorSystem *XYZ::toRGB()
{
    double Rn = 3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100);
    double Gn = -0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100);
    double Bn = 0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100);

    return new RGB(255 * F(Rn), 255 * F(Gn), 255 * F(Bn));
}

ColorSystem *XYZ::toCMYK()
{
    double K = std::min(1.0 - F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100)), 1.0 - F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100)));
    K = std::min(K, 1.0 - F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100)));

    if (K == 1)
    {
        return new CMYK(0, 0, 0, 1);
    }

    double C = (1 - F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100)) - K) / (1 - K);
    double M = (1 - F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100)) - K) / (1 - K);
    double Y = (1 - F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100)) - K) / (1 - K);

    return new CMYK(C, M, Y, K);
}

ColorSystem *XYZ::toHSV()
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
    return new HSV(temp.hsvHue(), S, V);
}

ColorSystem *XYZ::toHLS()
{
    QColor temp(255 * F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100)), 255 * F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100)), 255 * F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100)));
    return new HLS(temp.hslHue(), temp.lightness(), temp.hslSaturation());
}

ColorSystem *XYZ::toXYZ()
{
    return new XYZ(x, y, z);
}

ColorSystem *XYZ::toLAB()
{
    return new Lab(116 * Flab(y / 100.0) - 16, 500 * (Flab(x / 95.047) - Flab(y / 100.0)), 200 * (Flab(y / 100.0) - Flab(z / 108.883)));
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