#include <LC_E_0018.hpp>

namespace lc
{
int climbStairs(int n)
{
	if (n == 0 || n == 1)
		return 1;

	return climbStairs(n - 1) + climbStairs(n - 2);
}

int climbStairs_Method_2(int n)
{
	if (n == 0 || n == 1)
		return 1;

	int x1 = 1, x2 = 1;
	int x;

	for (int i = 2; i <= n; i++)
	{
		x = x1 + x2;
		x1 = x2;
		x2 = x;
	}

	return x;
}

}

