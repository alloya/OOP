// bodies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Controller.h"
using namespace std;

int main()
{
	vector<shared_ptr<CBody>> bodies;
	CBodyController controller(bodies, cin, cout);
	controller.Info();
	while (cin)
	{
		cout << "> ";
		if (!controller.HandleCommand() && !cin.eof())
		{
			cout << "Error in command!" << endl;
		}
	}
	controller.PrintBodies(bodies, cout);
	controller.GetHaviestBody(bodies, cout);
	controller.GetLightestBody(bodies, cout);
	return EXIT_SUCCESS;
}

