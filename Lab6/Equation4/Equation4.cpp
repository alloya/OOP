// Equation4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EquationProcessor.h"

using namespace std;

void ReadCoefficients(vector <double> &coefficients)
{
	/*size_t i = 0;
	double value;
	while (std::cin >> value)
	{
		if (i < 5)
		{
			coefficients[i] = value;
			++i;
		}
	}*/
	for (size_t i = 0; i < 5; ++i)
	{
		cin >> coefficients[i];
	}
}


int main()
{
	vector <double> coefficients = { 0, 0, 0, 0, 0 };
	ReadCoefficients(coefficients);
	for (size_t i = 0; i < 5; ++i)
	{
		cout << coefficients[i] << " ";
	}
	try
	{
		SolveEquation(coefficients[0], coefficients[1], coefficients[2], coefficients[3], coefficients[4]);
	}
	catch (const exception & ex)
	{
		cerr << ex.what() << endl;
	}


	return EXIT_SUCCESS;
}
