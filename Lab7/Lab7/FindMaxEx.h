#pragma once

template<typename T, typename Less = std::less<T>>
bool FindMaxEx(std::vector<T>const & arr, T & maxValue, Less const & less = Less())
{
	if (arr.empty())
	{
		return false;
	}

	auto result = arr.begin();
	for (auto it = result + 1; it < arr.end(); ++it)
	{
		if (less(*result, *it))
		{
			result = it;
		}
	}
	maxValue = *result;

	return true;
}