#include "source.h"

                
                                                        // Решение ДУ dy/dx = y - x

double RK2(double x0, double y0, int n) {
    double tmpX = x0, tmpY = y0, tmpF;
    double h = double(1.0/ n);

    for (int i = 0; i < n; i++) {
        tmpF = tmpY - tmpX;
        tmpY = tmpY + h * 0.5 *(tmpF + tmpY + h * tmpF - tmpX - h);
        tmpX += h;
    }

    return tmpY;
}

double epsRK2(double x0, double y0, int n) {
    return abs(RK2(x0, y0, n) - RK2(x0, y0, 2 * n));
}


double RK3(double x0, double y0, int n) {
    double tmpX = x0, tmpY = y0, tmpF;
    double h = double(1.0 / n);
    double k1, k2, k3;

    for (int i = 0; i < n; i++) {
        k1 = h * (tmpY - tmpX);
        k2 = h * (tmpY + k1 / 2.0 - tmpX - h / 2.0);
        k3 = h * (tmpY - k1 + 2.0 * k2 - tmpX - h);

        tmpY = tmpY + (k1 + 4.0 * k2 + k3) / 6.0;
        tmpX += h;
    }

    return tmpY;
}

double epsRK3(double x0, double y0, int n) {
    return abs(RK3(x0, y0, n) - RK3(x0, y0, 2 * n));
}

double RK4(double x0, double y0, int n) {
    double tmpX = x0, tmpY = y0, tmpF;
    double h = double(1.0 / n), h1;
    double k1, k2, k3, k4, k11, k21, k31, k41;
    double e;

    for (int i = 0; i < n; i++) {
        k1 = tmpY - tmpX;
        k2 = tmpY + h * k1 / 2.0 - tmpX - h / 2.0;
        k3 = tmpY + h * k2 / 2.0 - tmpX - h / 2.0;
        k4 = tmpY + h * k3 - tmpX - h;

        tmpY = tmpY + h * (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
        tmpX += h;
    }

    return tmpY;
}

double epsRK4(double x0, double y0, int n) {
    return abs(RK4(x0, y0, n) - RK4(x0, y0, 2 * n));
}


