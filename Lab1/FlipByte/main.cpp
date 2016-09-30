#include <iostream>
#include <cmath>
using namespace std;

void dectobin(int);

int check;

int out[8];

int main()
{
	int q;
	cin >> q;
	dectobin(q);
	system("pause");
	return 0;
}

void dectobin(int dc)
{
	for (int i = 7; i >= 0; i--)
	{
		int c = pow(2.0, i);
		check = c & dc;
		if (check)
		{
			out[i] = 1;
		}
		else out[i] = 0;
	}
	for (int i = 0; i<8; i++)
	{
		cout << out[i];
	}
	cout << endl;
}