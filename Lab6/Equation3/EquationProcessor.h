#pragma once

struct EquationRoot4
{
	size_t numRoots = 0;
	double roots[4];
};

struct EquationRoot3
{
	size_t numRoots = 1;
	double roots[3];
};

struct EquationRoot2
{
	size_t numRoots = 0;
	double roots[2];
};

EquationRoot4 Solve4(double a, double b, double c, double d, double e);
EquationRoot3 Solve3(double a, double b, double c);
EquationRoot2 Solve2(double a, double b, double c);
