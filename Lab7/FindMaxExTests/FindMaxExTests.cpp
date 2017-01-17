#include "stdafx.h"
#include <vector>
#include <functional>
#include "../Lab7/FindMaxEx.h"

using namespace std;


struct Athlete
{
	std::string name;
	int growth;
	int weight;
};

bool IsWeightLess(const Athlete &l, const Athlete &r)
{
	return l.weight < r.weight;
}

bool IsGrowthtLess(const Athlete &l, const Athlete &r)
{
	return l.growth < r.growth;
}


bool AreEqual(const Athlete &l, const Athlete &r)
{
	return (l.name == r.name) && (l.growth == r.growth) && (l.weight == r.weight);
}

BOOST_AUTO_TEST_SUITE(FindMaxEx_function)

BOOST_AUTO_TEST_CASE(when_vector_has_a_size_equal_1)
{
	{
		int maxValue = 0;
		std::vector<int> arr = { 1 };
		BOOST_CHECK(FindMaxEx(arr, maxValue));
		BOOST_CHECK(maxValue == 1);
	}


	{
		float maxValue = 0.0f;
		std::vector<float> arr = { 1.54f };
		BOOST_CHECK(FindMaxEx(arr, maxValue));
		BOOST_CHECK(maxValue == 1.54f);
	}

	{
		std::string maxValue = "";
		std::vector<std::string> arr = { "new year" };
		BOOST_CHECK(FindMaxEx(arr, maxValue));
		BOOST_CHECK(maxValue == "new year");
	}


	{
		Athlete athlete = { "Anton Shipulin", 185, 81 };
		std::vector<Athlete> arr = { athlete };
		BOOST_CHECK(FindMaxEx(arr, athlete, IsGrowthtLess));
		BOOST_CHECK(AreEqual(athlete, { "Anton Shipulin", 185, 81 }));

		BOOST_CHECK(FindMaxEx(arr, athlete, IsWeightLess));
		BOOST_CHECK(AreEqual(athlete, { "Anton Shipulin", 185, 81 }));
	}
}


BOOST_AUTO_TEST_CASE(when_vector_is_empty)
{
	{
		int maxValue = 0;
		std::vector<int> arr;
		BOOST_CHECK(!FindMaxEx(arr, maxValue));
		BOOST_CHECK(maxValue == 0);
	}

	{
		float maxValue = 0.0f;
		std::vector<float> arr;
		BOOST_CHECK(!FindMaxEx(arr, maxValue));
		BOOST_CHECK(maxValue == 0.0f);
	}

	{
		std::string maxValue = "";
		std::vector<std::string> arr;
		BOOST_CHECK(!FindMaxEx(arr, maxValue));
		BOOST_CHECK(maxValue == "");
	}


	{
		Athlete athlete = { "Anton Shipulin", 185, 81 };
		std::vector<Athlete> arr;
		BOOST_CHECK(!FindMaxEx(arr, athlete, IsGrowthtLess));
		BOOST_CHECK(AreEqual(athlete, { "Anton Shipulin", 185, 81 }));

		BOOST_CHECK(!FindMaxEx(arr, athlete, IsWeightLess));
		BOOST_CHECK(AreEqual(athlete, { "Anton Shipulin", 185, 81 }));
	}
}


BOOST_AUTO_TEST_CASE(when_vector_has_a_size_more_1)
{
	{
		int maxValue = 0;
		std::vector<int> arr = { 0 , 7, 4, 42, -41 };
		BOOST_CHECK(FindMaxEx(arr, maxValue));
		BOOST_CHECK(maxValue == 42);
	}

	{
		float maxValue = 0.0f;
		std::vector<float> arr = { 9.54f, -2.32f, 1.21f, -1.43f };
		BOOST_CHECK(FindMaxEx(arr, maxValue));
		BOOST_CHECK(maxValue == 9.54f);
	}

	{
		std::string maxValue = "";
		std::vector<std::string> arr = { "new", "87", "fir-tree", "squadron" };
		BOOST_CHECK(FindMaxEx(arr, maxValue));
		BOOST_CHECK(maxValue == "squadron");
	}



	{
		Athlete Shipulin = { "Anton Shipulin", 185, 81 };
		Athlete Garanichev = { "Eugene Garanichev", 169, 69 };
		Athlete Be = { "Johannes Be", 187, 80 };

		Athlete athlete = Shipulin;
		std::vector<Athlete> arr = { Shipulin, Garanichev, Be };


		BOOST_CHECK(FindMaxEx(arr, athlete, IsGrowthtLess));
		BOOST_CHECK(AreEqual(athlete, Be));

		BOOST_CHECK(FindMaxEx(arr, athlete, IsWeightLess));
		BOOST_CHECK(AreEqual(athlete, Shipulin));
	}

}
BOOST_AUTO_TEST_SUITE_END()