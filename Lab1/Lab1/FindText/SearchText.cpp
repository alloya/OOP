#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: findtext.exe <input file> <output file>\n";
		return 1;
	}

	// �������� ���������� ���� ifstream 
	// (input file stream, ����� ��� ������ �� �����), ������������������ ���
	// ������ �������� �����
	ifstream input(argv[1]);

	// �������� ����� is_open() � ������� input,
	// ������� ������ true, ���� ���� ��� ������
	if (!input.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	// ������� ����� ��� ������ � �������� ����
	ofstream output(argv[2]);
	if (!output.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	char ch;
	// ��������� � ���������� ch ������ �� �������� ������
	// ���������� ��������, ���������� � bool, ������� ������������� �� ������
	while (input.get(ch))
	{
		if (!output.put(ch))
		{
			cout << "Failed to save data on disk\n";
			return 1;
		}
	}

	if (!output.flush()) // ���� �� ������� �������� ������ �� ����
	{
		cout << "Failed to save data on disk\n";
		return 1;
	}

	return 0;
}