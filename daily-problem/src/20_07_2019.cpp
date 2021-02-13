/*

Hi, here's your problem today. This problem was recently asked by Microsoft:

You are given an array of integers in an arbitrary order. Return whether or not it is possible to make the 
array non-decreasing by modifying at most 1 element to any value.

We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).

Example:

[13, 4, 7] should return true, since we can modify 13 to any value 4 or less, to make it non-decreasing.

[13, 4, 1] however, should return false, since there is no way to modify just one element 
to make the array non-decreasing.

Can you find a solution in O(n) time?

*/

#include <20_07_2019.hpp>
#include <iostream>
namespace daily_interview
{
	const std::size_t THRESHOLD = 1;
	bool can_it_be_made_non_decreasing(const std::vector<int> &arr)
	{
		int max = arr[0];
		std::size_t modifications = 0;
		for( std::size_t i = 1; i < arr.size();  ++i ) {
			if( max <= arr[i] ) {
				max = arr[i];
				continue;
			}

			if( modifications < THRESHOLD ){
				modifications ++;
				max = arr[i];
				continue;
			}

			return false;
		}
		return true;
	}
}
