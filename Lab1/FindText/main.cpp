#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkInput(int argc)
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl <<
			"Usage: findtext.exe <input file> <text to search>" << endl;
		return false;
	}

	return true;
}

bool checkArguments(ifstream & input, const string & textToFind)
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

void searchText(ifstream & haystack, const string & needle)
{
	int lineNumber = 1;
	bool isTextFound = false;
	string curLine;
	while (getline(haystack, curLine))
	{
		size_t position = curLine.find(needle);
		if (position != -1)
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

	setlocale(LC_ALL, "Rus");
	if (!checkInput(argc))
	{
		return 1;
	}

	ifstream input(argv[1]);
	string textToFind = argv[2];

	if (checkArguments(input, textToFind))
	{
		searchText(input, textToFind);
	}

	return 0;
}