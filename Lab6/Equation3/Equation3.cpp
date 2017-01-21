// Equation4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "EquationProcessor.h"

using namespace std;

void PrintRoots(const EquationRoot4& roots)
{
	cout << "Equation roots are: ";
	for (size_t i = 0; i < roots.numRoots; ++i)
	{
		cout << roots.roots[i] << "; ";
	}
	cout << endl;
}


int main()
{
	double a, b, c, d, e;
	while ((cin >> a) && (cin >> b) && (cin >> c) && (cin >> d) && (cin >> e))
	{
		try
		{
			PrintRoots(Solve4(a, b, c, d, e));
		}
		catch (const exception & ex)
		{
			cerr << ex.what() << endl;
		}
	}

	return EXIT_SUCCESS;
}
