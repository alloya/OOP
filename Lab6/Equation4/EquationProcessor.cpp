#include "stdafx.h"
#include "EquationProcessor.h"
using namespace std;

EquationRoot4 Solve4(double a, double b, double c, double d, double e)
{
	return EquationRoot4();
}

EquationRoot2 Solve2(double a, double b, double c)
{
	EquationRoot2 equation;
	double D = b * b - 4. * a * c;
	if (D == 0)
	{
		equation.roots[0] = equation.roots[1] = -b / (2 * a);
	}
	else if (D > 0)
	{
		equation.roots[0] = (-b + sqrt(D)) / (2 * a);
		equation.roots[1] = (-b - sqrt(D)) / (2 * a);
	}
	return equation;
}

double Solve3(double a, double b, double c)
{
	array<double, 3> roots;
	double q = (pow(a, 2) - 3.0 * b) / 9.0;
	double r = (2.0 * pow(a, 3) - 9.0 * a * b + 27.0 * c) / 54.0;
	double s = pow(q, 3) - pow(r, 2);
	if (s > 0)
	{
		double t = acos(r / sqrt(pow(q, 3))) / 3.0;
		roots[0] = -2 * sqrt(q) * cos(t) - a / 3.0;
		roots[1] = -2 * sqrt(q) * cos(t + 2 * M_PI / 3.0) - a / 3.0;
		roots[2] = -2 * sqrt(q) * cos(t - 2 * M_PI / 3.0) - a / 3.0;
	}
	else if (s < 0)
	{
		if (q > 0)
		{
			double t = acosh(abs(r) / sqrt(pow(q, 3))) / 3.0;
			roots[0] = -2 * ((r > 0) ? 1 : ((r < 0) ? -1 : 0)) * sqrt(q) * cosh(t) - a / 3.0;
		}
		if (q < 0)
		{
			double t = asinh(abs(r) / sqrt(pow(abs(q), 3))) / 3.0;
			roots[0] = -2 * ((r > 0) ? 1 : ((r < 0) ? -1 : 0)) * sqrt(abs(q)) * sinh(t) - a / 3.0;
		}
		if (q == 0)
		{
			roots[0] = -pow((c - pow(a, 3) / 27), 1 / 3.0) - a / 3.0;
		}
	}
	else
	{
		roots[0] = -2 * ((r > 0) ? 1 : ((r < 0) ? -1 : 0)) * sqrt(q) - a / 3.0;
		roots[1] = ((r > 0) ? 1 : ((r < 0) ? -1 : 0)) * sqrt(q) - a / 3.0;
	}
	return *max_element(roots.begin(), roots.end());
}

