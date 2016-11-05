// WordFrequency.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utils.h"

int main()
{
	setlocale(LC_ALL, "Rus");
	//std::locale::global(std::locale(".KOI8-R"));
	PrintMap(cout, CountWords(cin));
	return 0;
}

