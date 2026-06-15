/*
 Hi, here's your problem today. This problem was recently asked by Uber:

 Given a list of numbers, find if there exists a pythagorean triplet in that
 list. A pythagorean triplet is 3 variables a, b, c where a^2 + b^2 = c^2

 Example:

 Input: [3, 5, 12, 5, 13]
 Output: True

 Here, 5^2 + 12^2 = 13^2.


 def findPythagoreanTriplets(nums):
 # Fill this in.

 print findPythagoreanTriplets([3, 12, 5, 13])
 # True

 */

#include <25_07_2019.hpp>
#include <algorithm>
namespace daily_interview
{
bool is_there_a_pythagorean_triplet(std::vector<size_t> &v)
{
	std::sort(v.begin(), v.end());
	for (size_t i = 0; i < v.size() - 2; i++)
	{
		size_t a = v[i];
		size_t a_sq = a * a;

		for (size_t j = i + 1; j < v.size() - 1; j++)
		{
			size_t b = v[j];
			size_t b_sq = b * b;

			for (size_t k = j + 1; k < v.size(); k++)
			{
				size_t c = v[k];
				size_t c_sq = c * c;

				if (a_sq + b_sq == c_sq)
					return true;

				if (a_sq + b_sq > c_sq)
					break;
			}

		}
	}
	return false;
}
}

