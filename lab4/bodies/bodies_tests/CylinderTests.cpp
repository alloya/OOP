#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../Cylinder.h"
#include <math.h>


struct Cylinder_
{
	const double expectedRadius = 2;
	const double expectedHeight = 10;
	const double expectedDensity = 8.8;
	const double expectedVolume = expectedHeight * expectedRadius * expectedRadius * M_PI;
	const CCylinder cylinder;
	Cylinder_()
		: cylinder(expectedDensity, expectedRadius, expectedHeight)
	{}
};
// Сфера
BOOST_FIXTURE_TEST_SUITE(Cylinder, Cylinder_)
// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&cylinder));
	}
	// имеет радиус
	BOOST_AUTO_TEST_CASE(has_a_radius)
	{
		BOOST_CHECK_EQUAL(cylinder.GetRadius(), expectedRadius);
	}
	// имеет радиус
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(cylinder.GetHeight(), expectedHeight);
	}
	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).GetDensity(), expectedDensity);
	}
	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetVolume(), expectedVolume, 1e-7);
	}
	// имеет массу
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cylinder).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	// имеет строковое представление
	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Cylinder:
	density = 8.8
	volume = 125.6637061
	mass = 1105.840614
	radius = 2
	height = 10
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(cylinder).ToString(), expectedString);
	}

	BOOST_AUTO_TEST_CASE(can_have_only_a_positive_radius)
	{
		BOOST_REQUIRE_THROW(CCylinder(0, 2, 2), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_have_only_a_positive_density)
	{
		BOOST_REQUIRE_THROW(CCylinder(2, 0, 2), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_have_only_a_positive_height)
	{
		BOOST_REQUIRE_THROW(CCylinder(2, 2, 0), std::invalid_argument);
	}

BOOST_AUTO_TEST_SUITE_END()