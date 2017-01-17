#include "stdafx.h"
#include "EquationProcessor.h"
using namespace std;


EquationRoot3 Solve3(double a, double b, double c, double d)
{
	return EquationRoot3();
}

EquationRoot2 Solve2(double a, double b, double c)
{
	EquationRoot2 equation;
	double D = b * b - 4. * a * c;
	if (D == 0)
	{
		equation.numRoots = 1;
		equation.roots[0] = equation.roots[1] = -b / (2 * a);
	}
	else if (D > 0)
	{
		equation.numRoots = 2;
		equation.roots[0] = (-b + sqrt(D)) / (2 * a);
		equation.roots[1] = (-b - sqrt(D)) / (2 * a);
	}
	else if (D < 0)
	{
		equation.numRoots = 0;
	}
	return equation;
}
//http://www.resolventa.ru/spr/algebra/ferrary.htm
