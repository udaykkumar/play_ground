#include <LC_E_0003.hpp>
#include <sstream>
#include <algorithm>

namespace lc
{
bool isPalindrome(int x)
{
	auto s1 = std::to_string(x);
	auto s2 = s1;

	std::reverse(s1.begin(), s1.end());

	return s1 == s2;
}

bool isPalindrome_Method_2(int x)
{
	int nums[32] =
	{ 0 };
	int len = 0;
	if (x < 0)
	{
		return false;
	}

	for (; x != 0; x /= 10)
	{
		nums[len++] = x % 10;
	}

	len -= 1;

	for (int i = 0; i <= len; i++, len--)
	{
		if (nums[i] != nums[len])
			return false;
	}

	return true;
}

bool isPalindrome_Method_3_2_Years_Ago(int x)
{
	if (x < 0)
		return false;

	if (x > 0 && x < 10)
		return true;

	int l = 0;
	int n = x;
	for (; x; x /= 10)
		l++;

	int mid = 0;
	if (l % 2 == 0)
		mid = l / 2;
	else
		mid = (l / 2) + 1;

	x = n;

	int rev = 0;
	for (int i = l; i > mid; i--, x /= 10)
		rev = rev * 10 + x % 10;

	if (l % 2 == 0)
		return rev == x;
	else
		return rev == x / 10;

}
}

