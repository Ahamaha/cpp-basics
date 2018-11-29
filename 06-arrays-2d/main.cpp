#include <cmath>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int aSizeH, aSizeW;

	ifstream fin("input.txt");
	fin >> aSizeH;
	fin >> aSizeW;
	
	double **matrix = new double*[aSizeH];
	for (int count = 0; count < aSizeH; count++)
		matrix[count] = new double[aSizeW];

	int value;
	for (int h = 0; h < aSizeH; h++)
	{
		for (int w = 0; w < aSizeW; w++)
		{
			fin >> value;
			matrix[h][w] = value;
		}
	}									//dynamic array^2
	
	fin.close();

	cout << "\nbefore: \n";
	for (int h = 0; h < aSizeH; h++) 
	{
		for (int w = 0; w < aSizeW; w++)
		{
			cout << setw(4) << matrix[h][w];
		}
		cout << endl;
	} 

	for (int w = 0; w < aSizeW; w++)
	{
		int n = 0;

		for (int h = 0; h < aSizeH; h++)
		{
			if (matrix[h][w] != 0)
				break;
			n++;
		}
		if (n == aSizeH)
		{
			for (int l = w; l < aSizeW - 1; l++)
			{
				for (int h = 0; h < aSizeH; h++)
				{
					swap<double, double>(matrix[h][l], matrix[h][l + 1]);
				}
			}
			aSizeW -= 1;
		}
	}															// for rows

	for (int h = 0; h < aSizeH; h++)
	{
		int n = 0;

		for (int w = 0; w < aSizeW; w++)
		{
			if (matrix[h][w] != 0)
				break;
			n++;
		}
		if (n == aSizeW)
		{
			for (int l = h; l < aSizeH - 1; l++)
			{
				for (int w = 0; w < aSizeW; w++)
				{
					swap<double, double>(matrix[l][w], matrix[l + 1][w]);
				}
			}
			aSizeH--;
		}
	}															// for columns

	cout << "\nafter: \n";
	for (int h = 0; h < aSizeH; h++)
	{
		for (int w = 0; w < aSizeW; w++)
		{
			cout << setw(4) << matrix[h][w];
		}
		cout << endl;
	}														//matrix after

	for (int h = 0; h < aSizeH; h++)
	{
		bool flag = false;
		for (int w = 0; w < aSizeW; w++)
		{
			if (matrix[h][w] > 0)
			{
				cout << "\n\nThe first row with the positive element is:  " << h;
				cout << "(counting from 0.)\n\n";
				flag = true;
				break;
			}
		}
		if (flag == true) break;
	}	
	
	for (int count = 0; count < aSizeH; count++)
		delete[] matrix[count];
	delete[] matrix;

	return 0;
}


