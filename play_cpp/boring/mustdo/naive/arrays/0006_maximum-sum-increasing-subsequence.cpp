/*

https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence/0

Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

*/

#include <iostream>
#include <vector>


int  max_sum_increasing_subsequence( std::vector<int>& array )
{
	int max_ending_here = array[0];
	int max_so_far		= array[0];

	for( size_t i = 1; i < array.size();  i ++  ) 
    {
		max_ending_here = std::max( max_ending_here, max_ending_here +  array.at(i));
        if( array[i] <= array[i-1] )
        {
            for( size_t n = i;  array[n] < array[n-1]; n -- )
                max_ending_here -= array[n-1];
        }
		max_so_far      = std::max( max_ending_here, max_so_far);
	}

	return max_so_far;
}

void sub_array_with_max_sum_test_1()
{
	std::vector<int> array = {1, 101, 2, 3, 100, 4, 5} ;
	std::cout << max_sum_increasing_subsequence(array) << std::endl;
}

void sub_array_with_max_sum_test_2()
{
	std::vector<int> array = {10, 5, 4, 3} ;
	std::cout << max_sum_increasing_subsequence(array) << std::endl;
}

int main( int ac, char **av )
{
	sub_array_with_max_sum_test_1();
	sub_array_with_max_sum_test_2();
	return 0;	
}
