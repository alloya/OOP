#include "stdafx.h"
#include "Sphere.h"

CSphere::CSphere(double density, double radius)
	: CBody("Sphere", density)
	, m_radius(radius)
{
	if (radius <= 0)
	{
		throw std::invalid_argument("Radius must have a positive value.\n");
	}
}

double CSphere::GetRadius()const
{
	return m_radius;
}

double CSphere::GetVolume()const
{
	return (pow(m_radius, 3) * M_PI) * 4 / 3;
}

void CSphere::AppendProperties(std::ostream & strm) const
{
	strm << "\tradius = " << GetRadius() << std::endl;
}

CSphere::~CSphere()
{
}