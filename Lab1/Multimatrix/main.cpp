#include <iostream>
#include <fstream>
#include <array>
#include <math.h>
#include <iomanip>

using namespace std;

static const int MATRIX_DIM = 3;
typedef array <double, MATRIX_DIM> MatrixRow;
typedef array <MatrixRow, MATRIX_DIM> Matrix;

bool CheckInput(int argc)
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl <<
			"Usage: multimatrix.exe <first file> <second file>" << endl;
		return false;
	}
	return true;
}

bool CheckArguments(ifstream & firstFile, ifstream & secondFile)
{
	if (!firstFile.is_open() || !secondFile.is_open())
	{
		cout << "Failed to open one of the files" << endl;
		return false;
	}
	return true;
}

bool GetMatrix(ifstream & file, Matrix & matrix)
{
	for (size_t row, col = 0; col < MATRIX_DIM; col++)
	{
		for (row = 0; row < MATRIX_DIM; row++)
		{
			if (!(file >> matrix[col][row]))
			{
				return false;
			}
		}
	}
	return true;
}


Matrix MultiplyMatrix(Matrix firstMatrix, Matrix secondMatrix)
{
	Matrix newMatrix;
	for (size_t i = 0; i < MATRIX_DIM; ++i)
	{
		for (size_t j = 0; j < MATRIX_DIM; ++j)
		{
			newMatrix[i][j] = 0;
			for (size_t k = 0; k < MATRIX_DIM; ++k)
			{
				newMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
			
		}
	}
	return newMatrix;
}

void PrintMatrix(ostream & output, Matrix & matrix)
{
	output << fixed;
	for (size_t col = 0; col < MATRIX_DIM; col++)
	{
		for (size_t row = 0; row < MATRIX_DIM; row++)
		{
			output << setprecision(3) << matrix[col][row] << '\t';
		}
		output << endl;
	}
}

int main(int argc, char * argv[])
{
	if (!CheckInput(argc))
	{
		return 1;
	}

	ifstream firstFile(argv[1]), secondFile(argv[2]);;

	if (!CheckArguments(firstFile, secondFile))
	{
		return 1;
	}

	Matrix firstMatrix, secondMatrix, multipliedMatrix;
	
	GetMatrix(firstFile, firstMatrix);
	GetMatrix(secondFile, secondMatrix);

	multipliedMatrix = MultiplyMatrix(firstMatrix, secondMatrix);
	PrintMatrix(cout, multipliedMatrix);
	return 0;
}