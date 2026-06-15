#include <LC_E_0016.hpp>
#include <algorithm>
namespace lc
{

// "1111"
// "1111"

std::string addBinary(std::string a, std::string b)
{
	std::string res = "";
	auto ai = a.rbegin();
	auto bi = b.rbegin();
	int c = 0;

	for (; ai != a.rend() && bi != b.rend(); ai++, bi++)
	{
		int r = ((*ai - '0') + (*bi - '0') + c) & 0x01;
		c = (((*ai - '0') + (*bi - '0') + c) >> 1) & 0x01;

		res += (r + '0');
	}

	for (; ai != a.rend(); ai++)
	{
		int r = ((*ai - '0') + c) & 0x01;
		c = (((*ai - '0') + c) >> 1) & 0x01;
		res += (r + '0');
	}

	for (; bi != b.rend(); bi++)
	{
		int r = ((*bi - '0') + c) & 0x01;
		c = (((*bi - '0') + c) >> 1) & 0x01;
		res += (r + '0');
	}

	if (c > 0)
		res += (c + '0');

	std::reverse(res.begin(), res.end());
	return res;
}

std::string addBinary_Method_2(std::string a, std::string b)
{
	std::string res("");
	int c = 0;
	for (int i(a.size() - 1), j(b.size() - 1); not (i < 0 && j < 0); i--, j--)
	{
		int x = (i < 0) ? 0 : a[i] - '0';
		int y = (j < 0) ? 0 : b[j] - '0';

		int r = (x + y + c) & 0x01;
		c = ((x + y + c) >> 1) & 0x01;

		res += (r + '0');

	}

	if (c > 0)
		res += (c + '0');

	std::reverse(res.begin(), res.end());

	return res;
}
}

