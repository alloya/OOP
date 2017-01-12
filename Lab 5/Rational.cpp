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

unsigned MCD(unsigned a, unsigned b)
{
	return a / GCD(a, b) * b;
}


//////////////////////////////////////////////////////////////////////////
// TODO: 1. Реализовать метод ToDouble() согласно заданию
//////////////////////////////////////////////////////////////////////////
double CRational::ToDouble()const
{
	return static_cast<double>(m_numerator) / m_denominator;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 2. Реализовать унарный + и унарный -
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
// TODO: 3. Реализовать бинарный +
//////////////////////////////////////////////////////////////////////////
CRational const operator+(const CRational & leftFraction, const CRational & rightFraction)
{
	int newDenominator = MCD(leftFraction.GetDenominator(), rightFraction.GetDenominator());
	int newNumerator = (leftFraction.GetNumerator()*newDenominator/leftFraction.GetDenominator() 
		+ rightFraction.GetNumerator()*newDenominator/rightFraction.GetDenominator());
	return CRational(newNumerator, newDenominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 4. Реализовать бинарный -
//////////////////////////////////////////////////////////////////////////
CRational const operator-(const CRational & leftFraction, const CRational & rightFraction)
{
	return leftFraction + (-rightFraction);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 5. Реализовать оператор +=
//////////////////////////////////////////////////////////////////////////
CRational & CRational::operator+=(const CRational & rightFraction)
{
	*this = *this + rightFraction;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 6. Реализовать оператор -=
//////////////////////////////////////////////////////////////////////////
CRational & CRational::operator-=(const CRational & rightFraction)
{
	*this = *this - rightFraction;
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 7. Реализовать оператор *
//////////////////////////////////////////////////////////////////////////
CRational const operator*(const CRational & leftFraction, const CRational & rightFraction)
{
	int newNumerator = leftFraction.GetNumerator()*rightFraction.GetNumerator();
	int newDenominator = leftFraction.GetDenominator()*rightFraction.GetDenominator();
	return CRational(newNumerator, newDenominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 8. Реализовать оператор /
//////////////////////////////////////////////////////////////////////////
CRational const operator/(const CRational & leftFraction, const CRational & rightFraction)
{
	int newNumerator = leftFraction.GetNumerator()*rightFraction.GetDenominator();
	int newDenominator = leftFraction.GetDenominator()*rightFraction.GetNumerator();
	return CRational(newNumerator, newDenominator);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 9. Реализовать оператор *=
//////////////////////////////////////////////////////////////////////////
CRational & CRational::operator *=(const CRational & rightFraction)
{
	m_numerator *= rightFraction.GetNumerator();
	m_denominator *= rightFraction.GetDenominator();
	Normalize();
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 10. Реализовать оператор /=
//////////////////////////////////////////////////////////////////////////
CRational & CRational::operator/=(const CRational & rhs)
{
	if (rhs.GetNumerator() == 0)
	{
		throw std::invalid_argument("Denominator must not be equal to zero");
	}
	m_numerator *= rhs.GetDenominator();
	m_denominator *= rhs.GetNumerator();
	Normalize();
	return *this;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 11. Реализовать операторы == и !=
//////////////////////////////////////////////////////////////////////////

bool const operator==(const CRational & leftFraction, const CRational & rightFraction)
{
	return (leftFraction.GetNumerator() == rightFraction.GetNumerator()
		&& leftFraction.GetDenominator() == rightFraction.GetDenominator());
}

bool const operator!=(const CRational & leftFraction, const CRational & rightFraction)
{
	return !(leftFraction == rightFraction);
}


//////////////////////////////////////////////////////////////////////////
// TODO: 12. Реализовать операторы <, >, <=, >=
//////////////////////////////////////////////////////////////////////////
bool const operator<(const CRational & leftFraction, const CRational & rightFraction)
{
	return leftFraction.ToDouble() < rightFraction.ToDouble();
}

bool const operator>(const CRational & leftFraction, const CRational & rightFraction)
{
	return leftFraction.ToDouble() > rightFraction.ToDouble();
}

bool const operator<=(const CRational & leftFraction, const CRational & rightFraction)
{
	return !(leftFraction > rightFraction);
}

bool const operator>=(const CRational & leftFraction, const CRational & rightFraction)
{
	return !(leftFraction < rightFraction);
}

//////////////////////////////////////////////////////////////////////////
// TODO: 13. Реализовать оператор вывода рационального числа в выходной поток 
//////////////////////////////////////////////////////////////////////////
std::ostream & operator<<(std::ostream & strm, const CRational & fraction)
{
	strm << fraction.GetNumerator() << '/' << fraction.GetDenominator();
	return strm;
}

//////////////////////////////////////////////////////////////////////////
// TODO: 14. Реализовать оператор ввода рационального числа из входного потока 
//////////////////////////////////////////////////////////////////////////
std::istream & operator >> (std::istream & stream, CRational & fraction)
{
	int numerator;
	int denominator;
	if ((stream >> numerator) && (stream.get() == '/') && (stream >> denominator))
	{
		fraction = CRational(numerator, denominator);
	}
	else
	{
		stream.setstate(std::ios_base::failbit);
	}
	return stream;
}

