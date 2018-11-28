#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, g;
	double ar[1000];
	double a, b, max_el_num = 0.0, sum = 0.0;

	cout << "Enter the amount of numbers in the array: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the element number " << i << ": ";
		cin >> ar[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (abs(ar[i]) > max_el_num)
		{
			max_el_num = abs(ar[i]);
			g = i;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (ar[i] > 0)
		{
			for (int m = i + 1; m < n; m++)
			{
				sum += ar[m];
			}
			break;
		}
	}

	cout << "Element with the maximal absolute value:  " << g;
	cout << "\nThe sum of the elements after the first positive number: " << sum;

	cout << "\n\nEnter a: ";
	cin >> a;
	cout << "Enter b: ";
	cin >> b;

	cout << "\nbefore: ";
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << ", ";
	}

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (ar[j] < a && ar[j + 1] >= a)
				swap(ar[j], ar[j + 1]); // Stolen from Anush. Thanks.

	cout << "\nafter: ";
	for (int i = 0; i < n; i++)
	{
		cout << ar[i] << ", ";
	}

	return 0;
}