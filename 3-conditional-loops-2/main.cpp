#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const int kMaxIters = 1000000;

	double xn, xk, dx, eps;
	cout << "-inf < x < -1\n";
	cout << "Enter xn: ";
	cin >> xn;
	cout << "Enter xk >= xn: ";
	cin >> xk;
	cout << "Enter dx > 0: ";
	cin >> dx;
	cout << "Enter eps > 0: ";
	cin >> eps;

	if (dx <= 0)
	{
		cout << "\nError 1: dx can't be less than or equal to zero.";
	}
	else if (xk >= -1)
	{
		cout << "\nError 2: xk has to be less than -1.";
	}
	else if (xk < xn)
	{
		cout << "\nError 3: xk can't be less than xn.\n";
	}
	else if (eps <= 0)
	{
		cout << "\nError 4: eps can't be less than or equal to zero.";
	}
	else
	{
		cout << string(67, '=') << endl;
		cout << "|       x       ";
		cout << "| arctg(x) (mine) ";
		cout << "| arctg(x) (cmath) ";
		cout << "| iterations |\n";
		cout << string(67, '=') << endl;

		cout << fixed;
		cout.precision(6);

		for (double x = xn; x <= xk; x += dx)
		{
			int n;
			double arctg = -M_PI_2, nth_term;
			for (n = 0; n <= kMaxIters; n++)
			{
				nth_term = pow(-1, n + 1) / ((2 * n + 1) * (pow(x, 2 * n + 1)));
				arctg += nth_term;
				if (abs(nth_term) < eps) break;
			}

			cout << "|" << setw(12) << x << setw(4) << "|";
			if (n <= kMaxIters)
				cout << setw(13) << arctg << setw(5);
			else
				cout << " limit exceeded! ";
			cout << "|" << setw(13) << atan(x) << setw(6);
			cout << "|" << setw(7) << n << setw(7) << "|\n";
		}
		cout << string(67, '=');
	}

	return 0;
}