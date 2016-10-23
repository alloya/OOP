// Vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "utils.h"

int main()
{
	vector<double> vector = GetNumbers(std::cin);
	ModifyVector(vector);
	SortVector(vector);
	PrintVector(vector);
	return 0;
}

