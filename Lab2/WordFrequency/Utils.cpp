#include "stdafx.h"
#include "Utils.h"

void ToLower(string & word)
{
	transform(word.begin(), word.end(), word.begin(), ::tolower);
}

void PrintMap(ostream & output, WordFerequency & map)
{
	for (auto word : map)
	{
		output << word.first << " -> " << word.second << endl;
	}
}

WordFerequency CountWords(istream & input)
{
	setlocale(LC_ALL, "Rus");
	WordFerequency wordMap;
	string word;
	while (input >> word)
	{
		ToLower(word);
		++wordMap[word];
	}
	return wordMap;
}
