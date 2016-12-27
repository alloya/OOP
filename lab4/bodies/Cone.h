#pragma once
#include "Body.h"

class CCone final :
	public CBody
{
public:
	CCone(double density, double radius, double height);
	double GetRadius()const;
	double GetHeight()const;
	double GetVolume()const override;
	~CCone();
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_height;
	double m_radius;
};