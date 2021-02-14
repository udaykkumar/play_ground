/*

https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

Given an array arr of N integers. Find the contiguous sub-array with maximum sum.

*/

#include <iostream>
#include <vector>
#include <climits>


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


static void exec_tests()
{
	int t;
		std::cin >> t;

	while( t --> 0 ) 
	{
		int n;
			std::cin >> n ;

		std::vector<int> v;
		for(int i = 0 ; i < n; i ++ ) {
			int x;
				std::cin >> x ;
			v.push_back(x);
		}

	    std::cout << subarray_with_max_sum(v) << std::endl;
	}
}

int main( int ac, char **av )
{
	exec_tests();
	return 0;	
}
