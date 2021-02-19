/*
https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k/0

Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.

*/

#include <iostream>
#include <vector>
#include <queue>

std::vector<int> maximum_of_all_subarrays_of_size_k(std::vector< int > &array, int k )
{
	std::vector<int> v;
	for( auto back{ array.begin() } , front{array.begin() + k};  ; ++ front, ++ back )
	{
		v.push_back( std::priority_queue<int>( back, front ).top() );
		if( front == array.end())
			break;
	}

	return v;
}


void exec_test(int index)
{
	int n, k;
		std::cin >> n >> k;

	std::vector<int> v;
	for( int i = 0 ; i < n ; i ++ )
	{
		int x;
			std::cin >> x;
			v.push_back(x);
	}

	std::vector<int> retVector = maximum_of_all_subarrays_of_size_k(v, k);
	for( auto value : retVector ) {
		std::cout << " " << value ;
	}

	std::cout << std::endl;
}

int main( int ac, char **av )
{
	std::cout << "Skipping  " << ac[0] << "\n";
	return 0;
	int t;
		std::cin >> t;

	for( int i = 0 ; i < t; i ++ )
		exec_test(i);

	return 0;
}