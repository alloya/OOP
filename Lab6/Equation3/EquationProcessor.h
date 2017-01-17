#pragma once
struct EquationRoot3
{
	size_t numRoots;
	double roots[3];
};

struct EquationRoot2
{
	size_t numRoots;
	double roots[2];
};

EquationRoot3 Solve3(double a, double b, double c, double d);
EquationRoot2 Solve2(double a, double b, double c);
