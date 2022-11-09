#pragma once

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>


double RK2(double x0, double y0, int n);
double RK3(double x0, double y0, int n);
double RK4(double x0, double y0, int n);

double epsRK2(double x0, double y0, int n);
double epsRK3(double x0, double y0, int n);
double epsRK4(double x0, double y0, int n);