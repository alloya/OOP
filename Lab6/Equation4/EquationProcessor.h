#pragma once
struct EquationRoot4
{
	double numRoots;
	double roots[4];
};

EquationRoot4 SolveEquation(double a, double b, double c, double d, double e);
