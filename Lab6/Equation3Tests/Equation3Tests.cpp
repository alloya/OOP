#include "stdafx.h"
#include "..\Equation3\EquationProcessor.h"

using namespace std;

//template <typename T>
//void CompareRoots(const T &expectedRoots, const T &actualRoots)
//{
//	for (size_t i = 0; i < expectedRoots.numRoots; ++i)
//	{
//		BOOST_CHECK_CLOSE(expectedRoots.roots[i], actualRoots.roots[i], 0.001));
//	}
//}

BOOST_AUTO_TEST_SUITE(Function_Solve2)

	BOOST_AUTO_TEST_CASE(can_compute_correct_roots_for_positive_discriminant)
	{
		EquationRoot2 equationRoots;

		equationRoots.numRoots = 2;
		equationRoots.roots[0] = 0.5 ;
		equationRoots.roots[1] = -3.;

		EquationRoot2 resultRoots = Solve2(2., 5., -3.);

		//CompareRoots(equationRoots, resultRoots);
		for (size_t i = 0; i < equationRoots.numRoots; ++i)
		{
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.0001);
		}
	}

	BOOST_AUTO_TEST_CASE(can_compute_correct_roots_for_zero_discriminant)
	{
		EquationRoot2 equationRoots;

		equationRoots.numRoots = 2;
		equationRoots.roots[0] = 1.66667;
		equationRoots.roots[1] = 1.66667;

		EquationRoot2 resultRoots = Solve2(9, -30., 25.);

		for (size_t i = 0; i < equationRoots.numRoots; ++i)
		{
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.0001);
		}
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Function_Solve3)

	//BOOST_AUTO_TEST_CASE(can_have_3_real_roots)
	//{
	//	EquationRoot3 equationRoots;

	//	equationRoots.numRoots = 3;
	//	equationRoots.roots[0] = -5.;
	//	equationRoots.roots[1] = 2.;
	//	equationRoots.roots[1] = 12.;

	//	EquationRoot3 resultRoots = Solve3(1., -9., -46., 120.);

	//	//CompareRoots(equationRoots, resultRoots);
	//	for (size_t i = 0; i < equationRoots.numRoots; ++i)
	//	{
	//		BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.0001);
	//	}
	//}

	/*BOOST_AUTO_TEST_CASE(can_compute_correct_roots_for_zero_discriminant)
	{
		EquationRoot2 equationRoots;

		equationRoots.numRoots = 2;
		equationRoots.roots[0] = 1.66667;
		equationRoots.roots[1] = 1.66667;

		EquationRoot2 resultRoots = Solve2(9, -30., 25.);

		for (size_t i = 0; i < equationRoots.numRoots; ++i)
		{
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.0001);
		}
	}*/

BOOST_AUTO_TEST_SUITE_END()
