#include <LC_E_0005.hpp>

namespace lc
{
std::string longestCommonPrefix(std::vector<std::string> &strs)
{
	std::string prefix("");
	if (strs.size() > 0)
	{
		for (int col = 0; strs[0][col]; ++col)
		{
			for (size_t i = 0; i < strs.size(); i++)
				if (strs[i][col] != strs[0][col])
					return prefix;
			prefix += strs[0][col];
		}

	}
	return prefix;
}
}

