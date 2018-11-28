#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const double kEps = 1e-15;

	double xn, xk, dx, a, b, c;
	cout << "Enter xn: ";
	cin >> xn;
	cout << "Enter xk >= xn: ";
	cin >> xk;
	cout << "Enter dx > 0: ";
	cin >> dx;
	cout << "Enter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;
	cout << "Enter c: ";
	cin >> c;

	if (dx <= 0)
	{
		cout << "\nError 1: dx can't be less than or equal to zero.\n";
	}
	else if (xk < xn)
	{
		cout << "\nError 2: xk can't be less than xn.\n";
	}
	else
	{
		cout << string(33, '=') << endl;
		cout << "|       x       |       F       |\n";
		cout << string(33, '=') << endl;

		cout << fixed;
		cout.precision(3);

		double x = xn;
		while (x <= xk)
		{
			cout << "|" << setw(10) << x << setw(6) << "|";

			double f;
			if ((x < 0.6) && (abs(b + c) >= kEps))
			{
				f = a * x * x * x + b * b + c;
			}
			else if ((x > 0.6) && (abs(b + c) < kEps))
			{
				if (abs(x - c) >= kEps)
				{
					f = (x - a) / (x - c);
				}
				else
				{
					cout << " division by 0 |\n";
					x += dx;
					continue;
				}
			}
			else
			{
				if ((abs(a) >= kEps) && (abs(c) >= kEps))
				{
					f = x / c + x / a;
				}
				else
				{
					cout << " division by 0 |\n";
					x += dx;
					continue;
				}
			}

			int ac = static_cast<int>(a);
			int bc = static_cast<int>(b);
			int cc = static_cast<int>(c);
			if ((ac | bc) & cc)
				cout << setw(10) << f << setw(7);
			else
				cout << setw(8) << static_cast<int>(f) << setw(9);
			cout << "|\n";

			x += dx;
		}
		cout << string(33, '=');
	}
	return 0;
}