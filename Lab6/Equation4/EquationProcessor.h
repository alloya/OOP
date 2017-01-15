#pragma once
struct EquationRoot4
{
	size_t numRoots;
	double roots[4];
};

struct EquationRoot2
{
	size_t numRoots;
	double roots[2];
};

EquationRoot4 Solve4(double a, double b, double c, double d, double e);
EquationRoot2 Solve2(double a, double b, double c);
double Solve3(double a, double b, double c);