#include "stdafx.h"
#include "Cone.h"

CCone::CCone(double density, double radius, double height)
	: CBody("Cone", density),
	m_height(height),
	m_radius(radius)
{
	if (radius <= 0 || height <= 0)
	{
		throw std::invalid_argument("Radius and height must have a positive value.\n");
	}
}

double CCone::GetRadius() const
{
	return m_radius;
}

double CCone::GetHeight() const
{
	return m_height;
}

double CCone::GetVolume() const
{
	return M_PI * pow(m_radius, 2) * m_height/3;
}

CCone::~CCone()
{
}

void CCone::AppendProperties(std::ostream & strm) const
{
	strm << "\tradius = " << GetRadius() << std::endl
		<< "\theight = " << GetHeight() << std::endl;
}