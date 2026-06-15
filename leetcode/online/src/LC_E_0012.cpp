#include <LC_E_0012.hpp>

namespace lc
{
std::string countAndSay(int n)
{
	std::string result = "1";
	for (size_t x = 2; x <= (size_t) n; x++)
	{
		std::string r = "";
		int count = 1;

		for (size_t i = 0; i < result.length(); ++i)
		{
			if (i == (result.length() - 1))
			{
				r += std::to_string(count) + result[i];
				continue;
			}

			if (result[i] == result[i + 1])
			{
				count++;
			}
			else
			{
				r += std::to_string(count) + result[i];
				count = 1;
			}
		}
		result = r;
		;
	}

	return result;
}
}

