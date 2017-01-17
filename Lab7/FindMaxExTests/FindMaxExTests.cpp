#include "stdafx.h"
#include <vector>
#include <functional>
#include "../Lab7/FindMaxEx.h"

using namespace std;


struct Athlete
{
	std::string name;
	int height;
	int weight;
};

bool IsWeightLess(const Athlete &first, const Athlete &second)
{
	return first.weight < second.weight;
}

bool IsHeightLess(const Athlete &first, const Athlete &second)
{
	return first.height < second.height;
}


bool AreEqual(const Athlete &first, const Athlete &second)
{
	return (first.name == second.name) && (first.height == second.height) && (first.weight == second.weight);
}

BOOST_AUTO_TEST_SUITE(FindMaxEx_function_works_correct_when)

	BOOST_AUTO_TEST_CASE(vector_is_empty)
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
			Athlete athlete = { "Vladimir Putin", 177, 75 };
			std::vector<Athlete> arr;
			BOOST_CHECK(!FindMaxEx(arr, athlete, IsHeightLess));
			BOOST_CHECK(AreEqual(athlete, { "Vladimir Putin", 177, 75 }));

			BOOST_CHECK(!FindMaxEx(arr, athlete, IsWeightLess));
			BOOST_CHECK(AreEqual(athlete, { "Vladimir Putin", 177, 75 }));
		}
	}

	BOOST_AUTO_TEST_CASE(vector_has_only_one_element)
	{
		{
			int maxValue = 0;
			std::vector<int> arr = { 1 };
			BOOST_CHECK(FindMaxEx(arr, maxValue));
			BOOST_CHECK(maxValue == 1);
		}

		{
			float maxValue = 0.0f;
			std::vector<float> arr = { 3.33f };
			BOOST_CHECK(FindMaxEx(arr, maxValue));
			BOOST_CHECK(maxValue == 3.33f);
		}

		{
			std::string maxValue = "";
			std::vector<std::string> arr = { "hello world" };
			BOOST_CHECK(FindMaxEx(arr, maxValue));
			BOOST_CHECK(maxValue == "hello world");
		}

		{
			Athlete athlete = { "Vladimir Putin", 177, 75 };
			std::vector<Athlete> arr = { athlete };
			BOOST_CHECK(FindMaxEx(arr, athlete, IsHeightLess));
			BOOST_CHECK(AreEqual(athlete, { "Vladimir Putin", 177, 75 }));

			BOOST_CHECK(FindMaxEx(arr, athlete, IsWeightLess));
			BOOST_CHECK(AreEqual(athlete, { "Vladimir Putin", 177, 75 }));
		}
	}

	BOOST_AUTO_TEST_CASE(vector_has_multiple_elements)
	{
		{
			int maxValue = 0;
			std::vector<int> arr = { 0 , 8, 6, 4, 2 };
			BOOST_CHECK(FindMaxEx(arr, maxValue));
			BOOST_CHECK(maxValue == 8);
		}

		{
			float maxValue = 0.0f;
			std::vector<float> arr = { 3.33f, 7.41f, -6.77f, -3.43f };
			BOOST_CHECK(FindMaxEx(arr, maxValue));
			BOOST_CHECK(maxValue == 7.41f);
		}

		{
			std::string maxValue = "";
			std::vector<std::string> arr = { "one", "two", "three", "four" };
			BOOST_CHECK(FindMaxEx(arr, maxValue));
			BOOST_CHECK(maxValue == "two");
		}

		{
			Athlete Putin = { "Vladimir Putin", 177, 75 };
			Athlete Medvedev = { "Mikhail Medvedev", 172, 70 };
			Athlete Obama = { "Barak Obama", 189, 83 };

			Athlete athlete = Putin;
			std::vector<Athlete> arr = { Putin, Medvedev, Obama };


			BOOST_CHECK(FindMaxEx(arr, athlete, IsHeightLess));
			BOOST_CHECK(AreEqual(athlete, Obama));

			BOOST_CHECK(FindMaxEx(arr, athlete, IsWeightLess));
			BOOST_CHECK(AreEqual(athlete, Obama));
		}
	}
BOOST_AUTO_TEST_SUITE_END()