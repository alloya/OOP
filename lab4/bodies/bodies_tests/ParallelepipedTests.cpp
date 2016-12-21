// test.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../Parallelepiped.h"



struct Parallelepiped_
{
	const double expectedDepth = 1;
	const double expectedDensity = 2;
	const double expectedWidth = 1;
	const double expectedHeight = 2;
	const double expectedVolume = expectedHeight * expectedWidth * expectedDepth;
	const CParallelepiped parallelepiped;
	Parallelepiped_()
		: parallelepiped(expectedDensity, expectedWidth, expectedHeight, expectedDepth)
	{}
};
// Параллелепипед
BOOST_FIXTURE_TEST_SUITE(Parallelepiped, Parallelepiped_)
// является объемным телом
	BOOST_AUTO_TEST_CASE(is_a_body)
	{
		BOOST_CHECK(static_cast<const CBody*>(&parallelepiped));
	}

	// имеет плотность
	BOOST_AUTO_TEST_CASE(has_a_density)
	{
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).GetDensity(), expectedDensity);
	}

	// имеет объем
	BOOST_AUTO_TEST_CASE(has_a_volume)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(parallelepiped).GetVolume(), expectedVolume, 1e-7);
	}

	// имеет массу
	BOOST_AUTO_TEST_CASE(has_a_mass)
	{
		BOOST_CHECK_CLOSE_FRACTION(static_cast<const CBody &>(parallelepiped).GetMass(), expectedVolume * expectedDensity, 1e-7);
	}

	// имеет глубину
	BOOST_AUTO_TEST_CASE(has_a_depth)
	{
		BOOST_CHECK_EQUAL(parallelepiped.GetDepth(), expectedDepth);
	}

	// имеет ширину
	BOOST_AUTO_TEST_CASE(has_a_width)
	{
		BOOST_CHECK_EQUAL(parallelepiped.GetWidth(), expectedWidth);
	}

	// имеет высоту
	BOOST_AUTO_TEST_CASE(has_a_height)
	{
		BOOST_CHECK_EQUAL(parallelepiped.GetHeight(), expectedHeight);
	}

	// имеет строковое представление
	/*BOOST_AUTO_TEST_CASE(can_be_converted_to_string)
	{
		const std::string expectedString = R"(parallelepiped:
		density = 2
		volume = 2
		mass = 4
		depth = 1
		height = 2
		width = 1
	)";
		BOOST_CHECK_EQUAL(static_cast<const CBody &>(parallelepiped).ToString(), expectedString);
	}
	*/
	BOOST_AUTO_TEST_CASE(can_not_have_a_negative_width)
	{
		BOOST_REQUIRE_THROW(CParallelepiped(1, 0, 4, 1), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_not_have_a_negative_density)
	{
		BOOST_REQUIRE_THROW(CParallelepiped(0, 3, 6, 7), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_not_have_a_negative_height)
	{
		BOOST_REQUIRE_THROW(CParallelepiped(41, 2, 0, 33), std::invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(can_not_have_a_negative_depth)
	{
		BOOST_REQUIRE_THROW(CParallelepiped(7, 4, 2, 0), std::invalid_argument);
	}

BOOST_AUTO_TEST_SUITE_END()

