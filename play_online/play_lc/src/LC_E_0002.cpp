#include <LC_E_0002.hpp>

namespace lc
{
int reverse(int x)
{
	size_t base = 1;
	for (int y = x; y != 0; y /= 10)
		base *= 10;

	long rev = 0;
	while (x != 0)
	{
		rev += (x % 10) * base;
		base /= 10;
		x /= 10;
	}

	if ((rev / 10) > 2147483647 || (rev / 10) < -2147483648)
		return 0;

	return rev / 10;
}

int reverse_Method_2(int x)
{

	unsigned int INTMAX = 0;
	INTMAX = ((~INTMAX) & 0xFFFFFFFF) >> 1;

	if (x == 0)
		return 0;

	int mult = (x < 0) ? -1 : 1;
	x *= mult;
	long rev = 0;
	while (x > 0)
	{
		int r = x % 10;
		rev = rev * 10 + r;
		x /= 10;
	}

	if (rev > INTMAX)
		return 0;

	int ret = ((int) rev) * mult;
	return (ret);
}
}

