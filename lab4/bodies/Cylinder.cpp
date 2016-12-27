#include "stdafx.h"
#include "Cylinder.h"

CCylinder::CCylinder(double density, double radius, double height)
	: CBody("Cylinder", density),
	m_height(height),
	m_radius(radius)
{
	if (radius <= 0 || height <= 0)
	{
		throw std::invalid_argument("Radius and height must have a positive value.\n");
	}
}

double CCylinder::GetRadius() const
{
	return m_radius;
}

double CCylinder::GetHeight() const
{
	return m_height;
}

double CCylinder::GetVolume() const
{
	return M_PI * pow(m_radius, 2) * m_height;
}

CCylinder::~CCylinder()
{
}

void CCylinder::AppendProperties(std::ostream & strm) const
{
	strm << "\tradius = " << GetRadius() << std::endl
	<< "\theight = " << GetHeight() << std::endl;
}