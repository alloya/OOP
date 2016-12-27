#include "stdafx.h"

#define _USE_MATH_DEFINES
#include "../Cone.h"
#include <math.h>


struct Cone_
{
	const double expectedRadius = 2;
	const double expectedHeight = 10;
	const double expectedDensity = 8.8;
	const double expectedVolume = expectedHeight * expectedRadius * expectedRadius * M_PI / 3;
	const CCone cone;
	Cone_()
		: cone(expectedDensity, expectedRadius, expectedHeight)
	{}
};
	// Сфера
	BOOST_FIXTURE_TEST_SUITE(Cone, Cone_)
	// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&cone));
	}
	// имеет радиус
	BOOST_AUTO_TEST_CASE(has_a_radius)
	{
		BOOST_CHECK_EQUAL(cone.GetRadius(), expectedRadius);
	}
	// имеет радиус
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(cone.GetHeight(), expectedHeight);
	}
	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).GetDensity(), expectedDensity);
	}
	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cone).GetVolume(), expectedVolume, 1e-7);
	}
	// имеет массу
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(cone).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}
	// имеет строковое представление
	BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const auto expectedString = R"(Cone:
	density = 8.8
	volume = 41.88790205
	mass = 368.613538
	radius = 2
	height = 10
)";
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(cone).ToString(), expectedString);
	}

	BOOST_AUTO_TEST_CASE(can_have_only_a_positive_radius)
	{
		BOOST_REQUIRE_THROW(CCone(0, 2, 2), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_have_only_a_positive_density)
	{
		BOOST_REQUIRE_THROW(CCone(2, 0, 2), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_have_only_a_positive_height)
	{
		BOOST_REQUIRE_THROW(CCone(2, 2, 0), std::invalid_argument);
	}

BOOST_AUTO_TEST_SUITE_END()