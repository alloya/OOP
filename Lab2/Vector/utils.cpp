#include "stdafx.h"
#include "utils.h"

vector<double> GetNumbers(istream & inputVector)
{
	return{ istream_iterator<double>(inputVector), istream_iterator<double>() };
}

void PrintVector(const vector<double> & inputVector)
{
	ostream_iterator<double> output(cout, " ");
	cout << fixed << setprecision(3);
	copy(inputVector.begin(), inputVector.end(), output);
	cout << endl;
}

void SortVector(vector<double>& inputVector)
{
	sort(inputVector.begin(), inputVector.end(), [](double a, double b) {
		return a < b;
	});
}

void ModifyVector(vector<double> & inputVector)
{
	if (inputVector.empty())
	{
		return;
	}
	double min = *min_element(inputVector.begin(), inputVector.end());
	transform(inputVector.begin(), inputVector.end(), inputVector.begin(), [=](double element) {
		return element * min;
	});
}