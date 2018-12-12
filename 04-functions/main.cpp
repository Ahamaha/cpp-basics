#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void PrintTableHead() {
    cout << string(62, '-') << endl;
    cout << "|" << setw(8) << "X" << setw(7);
    cout << "|" << setw(13) << "arctg(x)" << setw(4);
    cout << "|" << setw(12) << "atan(x)" << setw(3);
    cout << "|" << setw(12) << "iterations" << setw(3) << "|\n";
    cout << string(62, '-') << endl;
}

double arctg(double x, double eps, int &n, const int kMaxIters) {
    double arc1, arc2 = -M_PI_2;
    for (n = 0; n <= kMaxIters; n++) {
        arc1 = pow(-1, n + 1) / ((2 * n + 1) * pow(x, 2 * n + 1));
        arc2 += arc1;
        if (abs(arc1) < eps) break;
    }
    return arc2;
}

void CreateRow(double x, double eps, const int kMaxIters) {
    int n = 0;
    double y = arctg(x, eps, n, kMaxIters);

    cout << "|" << setw(14) << x << "|" << setw(16);
    if (n > kMaxIters)
        cout << "limit exceeded ";
    else
        cout << y;
    cout << "|" << setw(14) << atan(x)
        << "|" << setw(13) << n << "|\n";
}

int main() {
    const int kMaxIters = 1000000;

    double xn, xk, dx, eps;
    cout << "X must be less than -1\n";
    cout << "Please, enter X (start): ";
    cin >> xn;
    cout << "Please, enter X (end): ";
    cin >> xk;
    cout << "Please, enter dX > 0: ";
    cin >> dx;
    cout << "Please, enter eps > 0: ";
    cin >> eps;

    if (dx > 0 && xk < -1 && xn < xk && eps > 0) {
        PrintTableHead();

        cout << fixed;
        cout.precision(6);

        for (double x = xn; x <= xk; x += dx)
            CreateRow(x, eps, kMaxIters);
        cout << string(62, '-');
    }
    else {
        cout << "\nInvalid values";
    }

    return 0;
}