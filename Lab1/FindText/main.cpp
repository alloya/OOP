#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool CheckInput(int argc)
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl <<
			"Usage: findtext.exe <input file> <text to search>" << endl;
		return false;
	}

	return true;
}

bool CheckArguments(ifstream & input, const string & textToFind)
{
	if (!input.is_open())
	{
		cout << "Failed to open file" << endl;
		return false;
	}

	if (textToFind.empty())
	{
		cout << "Searching text should not be empty." << endl;
		return false;
	}

	return true;
}

void SearchText(ifstream & haystack, const string & needle)
{
	int lineNumber = 1;
	bool isTextFound = false;
	string curLine;
	while (getline(haystack, curLine))
	{
		size_t position = curLine.find(needle);
		if (position != string::npos)
		{
			cout << lineNumber << endl;
			isTextFound = true;
		}
		lineNumber++;
	}

	if (!isTextFound)
	{
		cout << "Text not found" << endl;
	}
}

int main(int argc, char * argv[])
{

	if (!CheckInput(argc))
	{
		return 1;
	}

	ifstream input(argv[1]);
	string textToFind = argv[2];

	if (CheckArguments(input, textToFind))
	{
		SearchText(input, textToFind);
	}

	return 0;
}