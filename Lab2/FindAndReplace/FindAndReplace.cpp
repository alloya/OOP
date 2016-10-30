// FindAndReplace.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Utils.h"


int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Rus");
	if (!CheckArgumentCount(argc) || !CheckReplacingString(argv[1]))
	{
		return 1;
	}
	cout << FindAndReplace(argv[1], argv[2], argv[3]) << endl;

	return 0;
}

