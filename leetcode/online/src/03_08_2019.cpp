/*
 Hi, here's your problem today. This problem was recently asked by Twitter:

 Given a string with the initial condition of dominoes, where:

 . represents that the domino is standing still
 L represents that the domino is falling to the left side
 R represents that the domino is falling to the right side

 Figure out the final position of the dominoes. If there are dominoes that get pushed on both ends, the force cancels out and that domino remains upright.

 Example:
 Input:  ..R...L..R.
 Output: ..RR.LL..RR
 Here is your starting point:

 class Solution(object):
 def pushDominoes(self, dominoes):
 # Fill this in.

 print Solution().pushDominoes('..R...L..R.')
 # ..RR.LL..RR

 */
#include <03_08_2019.hpp>

namespace daily_interview
{
std::string falling_dominoes(std::string &dominoes)
{
	size_t mark = 0;
	for (size_t i = 0; i < dominoes.size(); ++i)
	{
		if (dominoes[i] == 'R')
		{
			mark = i;
		}
		else if (dominoes[i] == '.')
		{
			if (mark != 0)
			{
				dominoes[i] = 'R';
			}
		}
		else if (dominoes[i] == 'L')
		{
			size_t m = mark, n = i;
			while (m < n)
			{
				dominoes[++m] = 'R';
				dominoes[--n] = 'L';
			}
			if (m == n)
			{
				dominoes[m] = '.';
			}
			mark = 0;
		}
	}
	return dominoes;
}
}

