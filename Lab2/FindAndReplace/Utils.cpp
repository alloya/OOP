#include "stdafx.h"
#include "Utils.h"

bool CheckArgumentCount(const int argumentCount)
{

	if (argumentCount != 4)
	{
		cout << "Invalid arguments count" << endl
			<< "Usage: replace <subject-string> <search-string> <replace-string>" << endl;
		return false;
	}
	return true;
}

bool CheckReplacingString(const string & str)
{
	if (str == "")
	{
		return false;
	}
	return true;
}

string FindAndReplace(string const & subject, string const & search, string  const & replace)
{
	string newString = "";

	size_t leftPosition = 0;
	size_t rightPosition = 0;

	if (!search.empty())
	{
		while (rightPosition != string::npos)
		{
			rightPosition = subject.find(search, leftPosition);
			if (rightPosition != string::npos)
			{
				newString.append(subject, leftPosition, rightPosition - leftPosition);
				newString += replace;
				leftPosition = rightPosition + search.length();
			}
		}

		newString.append(subject, leftPosition, subject.length());

		return newString;
	}
	else
	{
		return subject;
	}
	
}