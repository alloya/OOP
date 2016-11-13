#include "stdafx.h"
#include "TVSet.h"
#include "RemoteControl.h"

using namespace std;

void main()
{
	CTvSet tv;
	CRemoteControl remoteControl(tv, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
}