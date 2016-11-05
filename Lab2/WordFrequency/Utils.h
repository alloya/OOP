#pragma once
#include "stdafx.h"

using namespace std;
typedef map<string, size_t> WordFerequency;

WordFerequency CountWords(istream & input);
void ToLower(string & inputString);
void PrintMap(ostream & output, WordFerequency & map);
