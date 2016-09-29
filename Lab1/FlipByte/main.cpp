#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main()
{
	unsigned int  dec;
	cin >> dec;
	for (int i = 0; i<32; i++, dec <<= 1) putchar(48 + (dec >> 31));
}