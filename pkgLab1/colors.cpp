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
    g = G;
    b = B;
}

double RGB::getParam1()
{
    return r;
}

double RGB::getParam2()
{
    return g;
}

double RGB::getParam3()
{
    return b;
}

double RGB::getParam4()
{
    return 0.0;
}

void RGB::setParam1(double val)
{
    r = val;
}

void RGB::setParam2(double val)
{
    g = val;
}

void RGB::setParam3(double val)
{
    b = val;
}

void RGB::setParam4(double val)
{
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

    if (1 - r / 255.0 <= 1 - g / 255.0 && 1 - r / 255.0 <= 1 - b / 255.0)
    {
        k = 1.0 - r / 255.0;
    }
    else if (1 - g / 255.0 <= 1 - b / 255.0)
    {
        k = 1.0 - g / 255.0;
    }
    else
    {
        k = 1.0 - b / 255.0;
    }

    c = (1.0 - r / 255.0 - k) / (1.0 - k);
    m = (1.0 - g / 255.0 - k) / (1.0 - k);
    y = (1.0 - b / 255.0 - k) / (1.0 - k);

    return new CMYK(c * 100.0, m * 100.0, y * 100.0, k * 100.0);
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

    return new Lab(l, a, b);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CMYK::CMYK(double C, double M, double Y, double K)
{
    if (C > 100 || C < 0 || M > 100 || M < 0 || Y > 100 || Y < 0 || K > 100 || K < 0)
    {
        throw "ERROR";
        c = 0;
        m = 0;
        y = 0;
        k = 0;
        return;
    }

    c = C;
    m = M;
    y = Y;
    k = K;
}

double CMYK::getParam1()
{
    return c;
}

double CMYK::getParam2()
{
    return m;
}

double CMYK::getParam3()
{
    return y;
}

double CMYK::getParam4()
{
    return k;
}

void CMYK::setParam1(double val)
{
    c = val;
}

void CMYK::setParam2(double val)
{
    m = val;
}

void CMYK::setParam3(double val)
{
    y = val;
}

void CMYK::setParam4(double val)
{
    k = val;
}

ColorSystem *CMYK::toRGB()
{
    return new RGB(255 * (1.0 - c / 100.0) * (1.0 - k / 100.0), 255 * (1.0 - m / 100.0) * (1.0 - k / 100.0), 255 * (1.0 - y / 100.0) * (1.0 - k / 100.0));
}

ColorSystem *CMYK::toCMYK()
{
    return new CMYK(c, m, y, k);
}

ColorSystem *CMYK::toHSV()
{
    return toRGB()->toHSV();
}

ColorSystem *CMYK::toHLS()
{
    return toRGB()->toHLS();
}

ColorSystem *CMYK::toXYZ()
{
    return toRGB()->toXYZ();
}

ColorSystem *CMYK::toLAB()
{
    return toRGB()->toLAB();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HSV::HSV(double H, double S, double V)
{
    if (H > 360 || H < 0 || S > 100 || S < 0 || V > 100 || V < 0)
    {
        throw "ERROR";
        h = 0;
        s = 0;
        v = 0;
        return;
    }

    h = H;
    s = S;
    v = V;
}

double HSV::getParam1()
{
    return h;
}

double HSV::getParam2()
{
    return s;
}

double HSV::getParam3()
{
    return v;
}

double HSV::getParam4()
{
    return 0.0;
}

void HSV::setParam1(double val)
{
    h = val;
}

void HSV::setParam2(double val)
{
    s = val;
}

void HSV::setParam3(double val)
{
    v = val;
}

void HSV::setParam4(double val)
{
}

ColorSystem *HSV::toRGB()
{
    double r, g, b;

    double c = v * s;
    double x = c * (1 - abs(static_cast<int>(h / 60) % 2 - 1));
    double m = v - c;

    if (h >= 0 && h < 60)
    {
        r = (c + m) * 255;
        g = (x + m) * 255;
        b = m * 255;
    }
    else if (h >= 60 && h < 120)
    {
        r = (x + m) * 255;
        g = (c + m) * 255;
        b = m * 255;
    }
    else if (h >= 120 && h < 180)
    {
        r = (0 + m) * 255;
        g = (c + m) * 255;
        b = (x + m) * 255;
    }
    else if (h >= 180 && h < 240)
    {
        r = (0 + m) * 255;
        g = (x + m) * 255;
        b = (c + m) * 255;
    }
    else if (h >= 240 && h < 300)
    {
        r = (x + m) * 255;
        g = (0 + m) * 255;
        b = (c + m) * 255;
    }
    else if (h >= 300 && h < 360)
    {
        r = (c + m) * 255;
        g = (0 + m) * 255;
        b = (x + m) * 255;
    }

    return new RGB(r, g, b);
}

ColorSystem *HSV::toCMYK()
{
    return toRGB()->toCMYK();
}

ColorSystem *HSV::toHSV()
{
    return new HSV(h, s, v);
}

ColorSystem *HSV::toHLS()
{
    return toRGB()->toHLS();
}

ColorSystem *HSV::toXYZ()
{
    return toRGB()->toXYZ();
}

ColorSystem *HSV::toLAB()
{
    return toRGB()->toLAB();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

HLS::HLS(double H, double L, double S)
{
    if (H > 360 || H < 0 || S > 100 || S < 0 || L > 100 || L < 0)
    {
        throw "ERROR";
        h = 0;
        s = 0;
        l = 0;
        return;
    }

    h = H;
    s = S;
    l = L;
}

double HLS::getParam1()
{
    return h;
}

double HLS::getParam2()
{
    return l;
}

double HLS::getParam3()
{
    return s;
}

double HLS::getParam4()
{
    return 0.0;
}

void HLS::setParam1(double val)
{
    h = val;
}

void HLS::setParam2(double val)
{
    l = val;
}

void HLS::setParam3(double val)
{
    s = val;
}

void HLS::setParam4(double val)
{
}

ColorSystem *HLS::toRGB()
{
    double r, g, b;
    double c = (1 - abs(2 * l - 1)) * s;
    double x = c * (1 - abs(static_cast<int>(h / 60) % 2 - 1));
    double m = l - c / 2;

    if (h >= 0 && h < 60)
    {
        r = (c + m) * 255;
        g = (x + m) * 255;
        b = m * 255;
    }
    else if (h >= 60 && h < 120)
    {
        r = (x + m) * 255;
        g = (c + m) * 255;
        b = m * 255;
    }
    else if (h >= 120 && h < 180)
    {
        r = (0 + m) * 255;
        g = (c + m) * 255;
        b = (x + m) * 255;
    }
    else if (h >= 180 && h < 240)
    {
        r = (0 + m) * 255;
        g = (x + m) * 255;
        b = (c + m) * 255;
    }
    else if (h >= 240 && h < 300)
    {
        r = (x + m) * 255;
        g = (0 + m) * 255;
        b = (c + m) * 255;
    }
    else if (h >= 300 && h < 360)
    {
        r = (c + m) * 255;
        g = (0 + m) * 255;
        b = (x + m) * 255;
    }

    return new RGB(r, g, b);
}

ColorSystem *HLS::toCMYK()
{
    return toRGB()->toCMYK();
}

ColorSystem *HLS::toHSV()
{
    return toRGB()->toHSV();
}

ColorSystem *HLS::toHLS()
{
    return new HLS(h, l, s);
}

ColorSystem *HLS::toXYZ()
{
    return toRGB()->toXYZ();
}

ColorSystem *HLS::toLAB()
{
    return toRGB()->toLAB();
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

double XYZ::getParam1()
{
    return x;
}

double XYZ::getParam2()
{
    return y;
}

double XYZ::getParam3()
{
    return z;
}

double XYZ::getParam4()
{
    return 0.0;
}

void XYZ::setParam1(double val)
{
    x = val;
}

void XYZ::setParam2(double val)
{
    y = val;
}

void XYZ::setParam3(double val)
{
    z = val;
}

void XYZ::setParam4(double val)
{
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

    Rn = std::max(0.0, std::min(1.0, F(Rn))) * 255.0;
    Gn = std::max(0.0, std::min(1.0, F(Gn))) * 255.0;
    Bn = std::max(0.0, std::min(1.0, F(Bn))) * 255.0;

    return new RGB(Rn, Gn, Bn);
}

ColorSystem *XYZ::toCMYK()
{
    double K = std::min(1.0 - F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100)), 1.0 - F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100)));
    K = std::min(K, 1.0 - F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100)));

    if (K == 1)
    {
        return new CMYK(0, 0, 0, 100);
    }

    double C = (1.0 - F(3.2406 * (x / 100) - 1.5372 * (y / 100) - 0.4986 * (z / 100)) - K) / (1.0 - K);
    double M = (1.0 - F(-0.9689 * (x / 100) + 1.8758 * (y / 100) + 0.0415 * (z / 100)) - K) / (1.0 - K);
    double Y = (1.0 - F(0.0557 * (x / 100) - 0.2040 * (y / 100) + 1.0570 * (z / 100)) - K) / (.01 - K);

    return new CMYK(C * 100, M * 100, Y * 100, K * 100);
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

double Lab::getParam1()
{
    return L;
}

double Lab::getParam2()
{
    return a;
}

double Lab::getParam3()
{
    return b;
}

double Lab::getParam4()
{
    return 0.0;
}

void Lab::setParam1(double val)
{
    L = val;
}

void Lab::setParam2(double val)
{
    a = val;
}

void Lab::setParam3(double val)
{
    b = val;
}

void Lab::setParam4(double val)
{
}

double Lab::F(double x_)
{
    return 0.0;
}

ColorSystem *Lab::toRGB()
{
    int R, G, B;

    const double Yn = 100.0;
    const double Xn = 95.047;
    const double Zn = 108.883;

    double fy = (L + 16.0) / 116.0;
    double fx = a / 500.0 + fy;
    double fz = fy - b / 200.0;

    double X = (std::pow(fx, 3.0) > 0.008856) ? std::pow(fx, 3.0) : (fx - 16.0 / 116.0) / 7.787;
    double Y = (std::pow(fy, 3.0) > 0.008856) ? std::pow(fy, 3.0) : (fy - 16.0 / 116.0) / 7.787;
    double Z = (std::pow(fz, 3.0) > 0.008856) ? std::pow(fz, 3.0) : (fz - 16.0 / 116.0) / 7.787;

    X *= Xn;
    Y *= Yn;
    Z *= Zn;

    double Xr = X / 100.0;
    double Yr = Y / 100.0;
    double Zr = Z / 100.0;

    R = Xr * 3.2406 + Yr * -1.5372 + Zr * -0.4986;
    G = Xr * -0.9689 + Yr * 1.8758 + Zr * 0.0415;
    B = Xr * 0.0557 + Yr * -0.2040 + Zr * 1.0570;

    R = (R > 0.0031308) ? (1.055 * std::pow(R, 1 / 2.4) - 0.055) : 12.92 * R;
    G = (G > 0.0031308) ? (1.055 * std::pow(G, 1 / 2.4) - 0.055) : 12.92 * G;
    B = (B > 0.0031308) ? (1.055 * std::pow(B, 1 / 2.4) - 0.055) : 12.92 * B;

    R = (R < 0.0) ? 0.0 : R;
    G = (G < 0.0) ? 0.0 : G;
    B = (B < 0.0) ? 0.0 : B;

    R = (R > 1.0) ? 1.0 : R;
    G = (G > 1.0) ? 1.0 : G;
    B = (B > 1.0) ? 1.0 : B;

    R *= 255.0;
    G *= 255.0;
    B *= 255.0;

    return new RGB(R, G, B);
}

ColorSystem *Lab::toCMYK()
{
    return toRGB()->toCMYK();
}

ColorSystem *Lab::toHSV()
{
    return toRGB()->toHSV();
}

ColorSystem *Lab::toHLS()
{
    return toRGB()->toHLS();
}

ColorSystem *Lab::toXYZ()
{
    return toRGB()->toXYZ();
}

ColorSystem *Lab::toLAB()
{
    return new Lab(L, a, b);
}
