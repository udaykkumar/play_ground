/*

https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

*/

#include <iostream>
#include <vector>
#include<bits/stdc++.h> 

int  subarray_with_max_sum( std::vector<int>& array )
{
	int max_ending_here = 0;
	int max_so_far		= INT_MIN;

	for( auto a : array  ) {
		max_ending_here = max_ending_here +  a;
		
		if( max_so_far < max_ending_here )
			max_so_far = max_ending_here;

		if( max_ending_here < 0 )
			max_ending_here = 0;
	}

	return max_so_far;
}

void sub_array_with_max_sum_test_1()
{
	std::vector<int> array = {1, 2, 3, -2, 5} ;
	std::cout << subarray_with_max_sum(array) << std::endl;
}

void sub_array_with_max_sum_test_2()
{
	std::vector<int> array = {-1, -2, -3, -4} ;
	std::cout << subarray_with_max_sum(array) << std::endl;
}

int main( int ac, char **av )
{
	sub_array_with_max_sum_test_1();
	sub_array_with_max_sum_test_2();
	return 0;	
}
