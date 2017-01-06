#include "stdafx.h"
#include "Rational.h"
#include <utility>
#include <stdexcept>


CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	if (denominator < 0)
	{
		m_numerator = -m_numerator;
		m_denominator = -m_denominator;
	}
	Normalize();
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

void CRational::Normalize()
{
	const int gcd = GCD(abs(m_numerator), m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

unsigned GCD(unsigned a, unsigned b)
{
	while (b != 0)
	{
		std::swap(a, b);
		b = b % a;
	}
	return (a != 0) ? a : 1;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 1. ����������� ����� ToDouble() �������� �������
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble()const
{
	return static_cast<double>(m_numerator) / m_denominator;
}



//////////////////////////////////////////////////////////////////////////
// TODO: 2. ����������� ������� + � ������� -
//////////////////////////////////////////////////////////////////////////
CRational const CRational::operator-()const
{
	return CRational(-m_numerator, m_denominator);
}

CRational const CRational::operator+()const
{
	return *this;
}




//////////////////////////////////////////////////////////////////////////
// TODO: 3. ����������� �������� +
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 4. ����������� �������� -
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 5. ����������� �������� +=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 6. ����������� �������� -=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 7. ����������� �������� *
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 8. ����������� �������� /
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 9. ����������� �������� *=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 10. ����������� �������� /=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 11. ����������� ��������� == � !=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 12. ����������� ��������� <, >, <=, >=
//////////////////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////////////
// TODO: 13. ����������� �������� ������ ������������� ����� � �������� ����� 
//////////////////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////////////////
// TODO: 14. ����������� �������� ����� ������������� ����� �� �������� ������ 
//////////////////////////////////////////////////////////////////////////

