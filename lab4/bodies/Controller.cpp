#include "stdafx.h"
#include "Controller.h"
#include "Body.h"
#include "Sphere.h"
#include "Parallelepiped.h"

using namespace std;
using namespace std::placeholders;

bool CBodyController::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	return false;
}

void CBodyController::Info()
{
	m_output << "Use commands to create figures:\n"
		<< "Sphere <density> <radius>\n"
		<< "Parallelepiped <density> <width> <height> <depth>\n";
}

void CBodyController::PrintBodies(vector<shared_ptr<CBody>> const &bodies, ostream &output)
{
	if (bodies.empty())
	{
		output << "Not found of bodies\n";
	}
	else
	{
		for (auto &body : bodies)
		{
			output << body->ToString();
		}
	}
}

void CBodyController::GetHaviestBody(std::vector<std::shared_ptr<CBody>> const & bodies, std::ostream & output)
{
	if (!bodies.empty())
	{
		auto maxWeight = [](shared_ptr<CBody> const &x, shared_ptr<CBody> const &y)
		{
			return x->GetMass() < y->GetMass();
		};
		output << "Body with max mass is " << (*max_element(bodies.begin(), bodies.end(), maxWeight))->ToString();
	}
}

void CBodyController::GetLightestBody(std::vector<std::shared_ptr<CBody>> const & bodies, std::ostream & output)
{
	static const double WATER_DENSITY = 1000.0;
	static const double G = 9.8;
	if (!bodies.empty())
	{
		auto minWeight = [](shared_ptr<CBody> const &x, shared_ptr<CBody> const &y)
		{
			return ((x->GetDensity() - WATER_DENSITY) * G * x->GetVolume()) < ((y->GetDensity() - WATER_DENSITY)* G * y->GetVolume());
		};
		output << "Body with min weight in water is " << (*min_element(bodies.begin(), bodies.end(), minWeight))->ToString();
	}
}

bool CBodyController::CreateSphere(std::istream & args)
{
	double radius;
	double density;
	if (!(args >> radius) || !(args >> density))
	{
		m_output << "Invalid count of arguments\n"
			<< "Usage: Sphere <radius> <density>\n";
		return false;
	}

	try
	{
		shared_ptr<CBody> sphere = make_shared<CSphere>(radius, density);
		m_bodies.push_back(sphere);
	}
	catch (invalid_argument const &e)
	{
		m_output << e.what();
		return false;
	}
	return true;
}

bool CBodyController::CreateParallelepiped(std::istream & args)
{
	double width;
	double density;
	double height;
	double depth;
	if (!(args >> density) || !(args >> width) || !(args >> height) || !(args >> depth))
	{
		m_output << "Invalid number of arguments\n"
			<< "Usage: Parallelepiped <density> <width> <height> <depth>\n";
		return false;
	}
	try
	{
		shared_ptr<CBody> parallelepiped = make_shared<CParallelepiped>(density, width, height, depth);
		m_bodies.push_back(parallelepiped);
	}
	catch (invalid_argument const &e)
	{
		m_output << e.what();
		return false;
	}
	return true;
}

CBodyController::CBodyController(vector<shared_ptr<CBody>> & bodies, istream & input, ostream & output)
	: m_bodies(bodies)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "Sphere", bind(&CBodyController::CreateSphere, this, _1) },
	{ "Parallelepiped", bind(&CBodyController::CreateParallelepiped, this, _1) }
})
{
}


