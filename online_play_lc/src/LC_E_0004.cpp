#include <LC_E_0004.hpp>
#include <unordered_map>
namespace lc
{

int romanToInt(std::string s)
{
	std::unordered_map<char, int> SVMap =
	{
	{ 'I', 1 },
	{ 'V', 5 },
	{ 'X', 10 },
	{ 'L', 50 },
	{ 'C', 100 },
	{ 'D', 500 },
	{ 'M', 1000 } };

	int res = SVMap.at((size_t) s.at(0));

	int pre_value = res;
	for (size_t i = 1; i < s.length(); ++i)
	{
		int cur_value = SVMap.at((size_t) s.at(i));

		res += cur_value;

		if (cur_value > pre_value)
			res -= (pre_value + pre_value);

		pre_value = cur_value;
	}

	return res;
}

int romanToInt_Method_2(std::string s)
{
	int SVMap[255];
	SVMap[(size_t)'I'] = 1;
	SVMap[(size_t)'V'] = 5;
	SVMap[(size_t)'X'] = 10;
	SVMap[(size_t)'L'] = 50;
	SVMap[(size_t)'C'] = 100;
	SVMap[(size_t)'D'] = 500;
	SVMap[(size_t)'M'] = 1000;

	int res = SVMap[(size_t) s.at(0)];

	int pre_value = res;
	for (size_t i = 1; i < s.length(); ++i)
	{
		int cur_value = SVMap[(size_t) s.at(i)];

		res += cur_value;

		if (cur_value > pre_value)
			res -= (pre_value + pre_value);

		pre_value = cur_value;
	}

	return res;
}
}

