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
/*
	BOOST_AUTO_TEST_CASE(can_have_3_real_roots)
	{
		EquationRoot3 equationRoots;

		equationRoots.numRoots = 3;
		{
			equationRoots.roots[0] = -5.;
			equationRoots.roots[1] = 2.;
			equationRoots.roots[2] = 12.;

			EquationRoot3 resultRoots = Solve3(-9., -46., 120.);

			//CompareRoots(equationRoots, resultRoots);
			for (size_t i = 0; i < equationRoots.numRoots; ++i)
			{
				BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.001);
			}
		}

		{
			equationRoots.roots[0] = -1.94874;
			equationRoots.roots[1] = 1.38681;
			equationRoots.roots[2] = 32.56193;

			EquationRoot3 resultRoots = Solve3(-32., -21., 88.);

			//CompareRoots(equationRoots, resultRoots);
			for (size_t i = 0; i < equationRoots.numRoots; ++i)
			{
				BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.001);
			}
		}
		
	}
*/
	BOOST_AUTO_TEST_CASE(can_have_1_real_root)
	{
			EquationRoot3 equationRoots;
		{	
			equationRoots.roots[0] = 1;
			EquationRoot3 resultRoots = Solve3(-3., 21., -19.);
			//CompareRoots(equationRoots, resultRoots);
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[0], resultRoots.roots[0], 0.001);
			
		}
/*
		{
			equationRoots.roots[0] = 0.0000;
			EquationRoot3 resultRoots = Solve3(-7., 44., 0.);
			//CompareRoots(equationRoots, resultRoots);
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[0], resultRoots.roots[0], 0.001);
		}
		
		{
			equationRoots.roots[0] = -11.41623;
			EquationRoot3 resultRoots = Solve3(9., -19., 98.);
			//CompareRoots(equationRoots, resultRoots);
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[0], resultRoots.roots[0], 0.001);
		}

		{
			equationRoots.roots[0] = -1.38043;
			EquationRoot3 resultRoots = Solve3(0., 22., 33.);
			//CompareRoots(equationRoots, resultRoots);
			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[0], resultRoots.roots[0], 0.001);
		}*/
	}
	
BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(Function_Solve4)

	BOOST_AUTO_TEST_CASE(throws_an_exception_if_hightest_coefficient_is_0)
	{
		BOOST_CHECK_THROW(Solve4(0, 0, 0, 0, 0), invalid_argument);
	}

	/*BOOST_AUTO_TEST_CASE(throws_an_exception_if_there_are_no_real_roots)
	{
		BOOST_CHECK_THROW(Solve4(1, 4, 6, 4, 2), domain_error);
	}*/
	//BOOST_AUTO_TEST_CASE(has_four_equal_real_roots)
	//{
	//	EquationRoot4 equationRoots;

	//	equationRoots.numRoots = 4;
	//	{
	//		equationRoots.roots[0] = -1;
	//		equationRoots.roots[1] = -1;
	//		equationRoots.roots[2] = -1;
	//		equationRoots.roots[3] = -1;

	//		EquationRoot4 resultRoots = Solve4(1, 3, 3, -1, -6);

	//		//CompareRoots(equationRoots, resultRoots);
	//		for (size_t i = 0; i < equationRoots.numRoots; ++i)
	//		{
	//			BOOST_CHECK_CLOSE_FRACTION(equationRoots.roots[i], resultRoots.roots[i], 0.001);
	//		}
	//	}
	//}

BOOST_AUTO_TEST_SUITE_END()