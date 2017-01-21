#include "stdafx.h"
#include "EquationProcessor.h"
using namespace std;

void AddNewPairOfRoots(EquationRoot4 & equation4, EquationRoot2 & equation2)
{
	if (equation2.numRoots > 1)
	{
		equation4.roots[equation4.numRoots++] = equation2.roots[1];
	}
	if (equation2.numRoots > 0)
	{
		equation4.roots[equation4.numRoots++] = equation2.roots[0];
	}
}

EquationRoot4 Solve4(double a, double b, double c, double d, double e)
{
	if (a == 0)
	{
		throw invalid_argument("Argument 'a' must not be equal to 0");
	}
	EquationRoot4 result;
	EquationRoot3 tempResult;

	double inv = a;
	a = b / inv;
	b = c / inv;
	c = d / inv;
	d = e / inv;
	tempResult = Solve3(-b, a * c - 4 * d, 4 * b * d - a * a * d - c * c);
	double y = tempResult.roots[0];
	cout << "temproot = " << y << endl;
	double alpha = sqrt(a * a / 4 - b + y);
	double beta = sqrt(y * y / 4 - d);
	if ((a * y / 2 - c) < 0)
	{
		beta *= -1;
	}
	cout << "solve2 root = " << Solve2(1, a / 2 + alpha, y / 2 + beta).roots[0] << endl;
	AddNewPairOfRoots(result, Solve2(1, a / 2 + alpha, y / 2 + beta));
	AddNewPairOfRoots(result, Solve2(1, a / 2 - alpha, y / 2 - beta));

	if (result.numRoots == 0)
	{
		throw domain_error("Equation does not have real roots");
	}
	sort(begin(result.roots), begin(result.roots) + result.numRoots);
	return result;
}

EquationRoot3 Solve3(double a, double b, double c)
{
	EquationRoot3 equation;
	array<double, 3> roots = {0., 0., 0.};

	double Q = (a * a - 3 * b) / 9.;
	double R = (2 * pow(a, 3) - 9 * a * b + 27 * c) / 54.;
	double S = pow(Q, 3) - pow(R, 2);
	if (S > 0)
	{
		cout << "there are 3 roots" << endl;
		double phi = acos(R / sqrt(pow(Q, 3))) / 3.;
		roots[0] = -2 * sqrt(Q) * cos(phi) - a / 3.;
		roots[1] = -2 * sqrt(Q) * cos(phi + 2 * M_PI / 3.) - a / 3.;
		roots[2] = -2 * sqrt(Q) * cos(phi - 2 * M_PI / 3.) - a / 3.;
		equation.numRoots = 3;
	}
	else 
	{
		/*if (R <= 0.)
		{
			R = -R;
		}*/
		cout << "there is 1 root" << endl;
		double aa = -pow(R + sqrt(pow(R, 2) - pow(Q, 3)), 1. / 3.);
		double bb = (aa != 0) ? (Q / aa) : 0.;
		roots[0] = aa + bb - a / 3;
		equation.numRoots = 1;
		cout << roots[0] << endl;
	}
	if (equation.numRoots != 1)
	{
		sort(roots.begin(), roots.end());
	}
	for(size_t i = 0; i != equation.numRoots; ++i)
	{
		equation.roots[i] = roots[i];
		cout << "root " << i << " = " << roots[i] << endl;
	}

	return equation;
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
