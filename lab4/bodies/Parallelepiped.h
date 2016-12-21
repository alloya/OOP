#pragma once
#include "Body.h"

class CParallelepiped final :
	public CBody
{
public:
	CParallelepiped(double density, double width, double height, double depth);
	double GetDepth()const;
	double GetWidth()const;
	double GetHeight()const;
	double GetVolume()const override;
	~CParallelepiped();
protected:
	void AppendProperties(std::ostream & strm) const override;
private:
	double m_width;
	double m_height;
	double m_depth;
};