#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<double> GetVector(ifstream &input)
{
	/*double temp;
	while (!file.eof())
	{
		file >> temp;
		destVector.push_back(temp);
	}
	return destVector;*/
	return {istream_iterator<double>(input), istream_iterator<double>() };
}

void PrintSortedVector(vector<double> &inputVector)
{
	sort(inputVector.begin(), inputVector.end());
	cout << fixed << setprecision(3);
	for (vector<double>::const_iterator i = inputVector.begin(); i != inputVector.end(); ++i)
	{
		cout << setprecision(3) << *i << ' ';
	}
	cout << endl;
}

void Modify(vector<double> &inputVector)
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

int main(int argc, char * argv[])
{
	ifstream input(argv[1]);
	vector<double> vector = GetVector(input);
	Modify(vector);
	PrintSortedVector(vector);
	return 0;
}