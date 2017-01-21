#include "stdafx.h"
#include "..\Equation3\EquationProcessor.h"

using namespace std;

//template <typename T>
//void CompareRoots(const T &expectedRoots, const T &actualRoots)
//{
//	for (size_t i = 0; i != expectedRoots.numRoots; ++i)
//	{
//		BOOST_CHECK_CLOSE(expectedRoots.roots[i], actualRoots.roots[i], 0.0001));
//	}
//}

BOOST_AUTO_TEST_SUITE(Function_Solve2)

	BOOST_AUTO_TEST_CASE(can_compute_2_different_correct_roots_for_positive_discriminant)
	{
		EquationRoot2 equationRoots;
		equationRoots.numRoots = 2;
		equationRoots.roots[0] = -3.;
		equationRoots.roots[1] = 0.5 ;

		EquationRoot2 resultRoots = Solve2(2., 5., -3.);
		for (size_t i = 0; i < equationRoots.numRoots; ++i)
		{
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.0001);
		}
	}

	BOOST_AUTO_TEST_CASE(can_compute_2_equal_correct_roots_for_zero_discriminant)
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

	BOOST_AUTO_TEST_CASE(can_compute_3_real_roots)
	{
		EquationRoot3 equationRoots;

		equationRoots.numRoots = 3;
		{
			equationRoots.roots[2] = -5.;
			equationRoots.roots[1] = 2.;
			equationRoots.roots[0] = 12.;

			EquationRoot3 resultRoots = Solve3(-9., -46., 120.);
			for (size_t i = 0; i < equationRoots.numRoots; ++i)
			{
				BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.001);
			}
		}

		{
			equationRoots.roots[2] = -1.94874;
			equationRoots.roots[1] = 1.38681;
			equationRoots.roots[0] = 32.56193;

			EquationRoot3 resultRoots = Solve3(-32., -21., 88.);
			for (size_t i = 0; i < equationRoots.numRoots; ++i)
			{
				BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.001);
			}
		}
		
	}

	BOOST_AUTO_TEST_CASE(can_compute_1_real_root)
	{
			EquationRoot3 equationRoots;
		{	
			equationRoots.roots[0] = 1;
			EquationRoot3 resultRoots = Solve3(-3., 21., -19.);
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[0], resultRoots.roots[0], 0.001);
			
		}
		
		{
			equationRoots.roots[0] = -11.41623;
			EquationRoot3 resultRoots = Solve3(9., -19., 98.);
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[0], resultRoots.roots[0], 0.001);
		}
	}
	
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Function_Solve4)

	BOOST_AUTO_TEST_CASE(throws_an_exception_if__coefficient_at_supreme_degree_is_0)
	{
		BOOST_CHECK_THROW(Solve4(0, 0, 0, 0, 0), invalid_argument);
	}

	BOOST_AUTO_TEST_CASE(throws_an_exception_if_there_are_no_real_roots)
	{
		BOOST_CHECK_THROW(Solve4(1, 4, 6, 4, 2), domain_error);
	}

	BOOST_AUTO_TEST_CASE(has_2_real_roots)
	{
		EquationRoot4 equationRoots;
		equationRoots.numRoots = 2;
		equationRoots.roots[0] = -2;
		equationRoots.roots[1] = 1;

		EquationRoot4 resultRoots = Solve4(1, 3, 3, -1, -6);
		for (size_t i = 0; i < equationRoots.numRoots; ++i)
		{
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.001);
		}
	}

	BOOST_AUTO_TEST_CASE(has_4_different_real_roots)
	{
		EquationRoot4 equationRoots;
		equationRoots.numRoots = 4;
		equationRoots.roots[0] = -3;
		equationRoots.roots[1] = -2;
		equationRoots.roots[2] = 0.5;
		equationRoots.roots[3] = 2;

		EquationRoot4 resultRoots = Solve4(2, 5, -11, -20, 12);
		for (size_t i = 0; i < equationRoots.numRoots; ++i)
		{
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.001);
		}
	}

	BOOST_AUTO_TEST_CASE(has_4_equal_real_roots)
	{
		EquationRoot4 equationRoots;
		equationRoots.numRoots = 4;
		equationRoots.roots[0] = 0;
		equationRoots.roots[1] = 0;
		equationRoots.roots[2] = 0;
		equationRoots.roots[3] = 0;

		EquationRoot4 resultRoots = Solve4(1, 0, 0, 0, 0);
		for (size_t i = 0; i < equationRoots.numRoots; ++i)
		{
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.001);
		}
	}

BOOST_AUTO_TEST_SUITE_END()