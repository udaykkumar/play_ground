#include <LC_E_0017.hpp>

namespace lc
{
int mySqrt(int x)
{
	int l = 0;
	int r = 46340;
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		int res = m * m;

		if (res == x)
			return m;

		if (res < x)
			l = m + 1;
		else if (res > x)
			r = m - 1;
	}
	return r;
}
}

