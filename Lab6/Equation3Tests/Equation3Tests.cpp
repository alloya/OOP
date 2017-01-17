#include "stdafx.h"
#include "..\Equation3\EquationProcessor.h"

using namespace std;

template <typename T>
bool RootsAreEqual(const T &expectedRoots, const T &actualRoots)
{
	for (size_t i = 0; i < expectedRoots.numRoots; ++i)
	{
		if (expectedRoots.roots[i] != actualRoots.roots[i])
		{
			return false;
		}
	}
	return true;
}

BOOST_AUTO_TEST_SUITE(Function_Solve2)

	BOOST_AUTO_TEST_CASE(can_compute_correct_roots_for_positive_discriminant)
	{
		EquationRoot2 equationRoots;

		equationRoots.numRoots = 2;
		equationRoots.roots[0] = 0.5 ;
		equationRoots.roots[1] = -3.;

		EquationRoot2 resultRoots = Solve2(2., 5., -3.);

		BOOST_CHECK(RootsAreEqual(equationRoots, resultRoots));
	}

	/*BOOST_AUTO_TEST_CASE(can_compute_correct_roots_for_zero_discriminant)
	{
		EquationRoot2 equationRoots;

		equationRoots.numRoots = 2;
		equationRoots.roots[0] = 1.66667;
		equationRoots.roots[1] = 1.66667;

		EquationRoot2 resultRoots = Solve2(9, -30., 25.);

		BOOST_CHECK(RootsAreEqual(equationRoots, resultRoots));
	}*/

BOOST_AUTO_TEST_SUITE_END()
