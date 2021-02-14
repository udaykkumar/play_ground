/*

https://practice.geeksforgeeks.org/problems/subarray-with-given-sum/0

Given an unsorted array A of size N of non-negative integers, find a continuous sub-array which adds to a given number S.

*/

#include <iostream>
#include <vector>
#include <tuple>

std::tuple<size_t,size_t>  subarray_with_given_sum( std::vector<size_t> array, size_t sum )
{
	size_t idx = 0, jdx = 0;
	
	for( ; idx < array.size() ; idx ++ )
	{
		size_t sub_array_sum = 0;
		for( jdx = idx ; jdx < array.size() ; jdx ++ )
		{
			sub_array_sum += array.at(jdx);
			if( sub_array_sum >= sum )
					break;
		}
		
		if( sub_array_sum == sum )
			return std::make_pair(idx+1, jdx+1);
	}
	
	return std::make_pair( 0, 0);
}


void sub_array_sum_test_1()
{
	std::vector<size_t> array = {1,2,3,7,5};
			    size_t    sum = 12;

    std::tuple< size_t, size_t > res = subarray_with_given_sum(array, sum);
    std::cout << " " << std::get<0>(res) <<  "  " <<  std::get<1>(res) << "\n";
}

void sub_array_sum_test_2()
{
	std::vector<size_t> array = {1,2,3,4,5,6,7,8,9,10};
			    size_t    sum = 15;

    std::tuple< size_t, size_t > res = subarray_with_given_sum(array, sum);
    std::cout << " " << std::get<0>(res) <<  "  " <<  std::get<1>(res) << "\n";
}


void sub_array_sum_test_3()
{
	std::vector<size_t> array = {1,1,1,1,1,1,1,1,1,1};
			    size_t    sum = array.size();

    std::tuple< size_t, size_t > res = subarray_with_given_sum(array, sum);
    std::cout << " " << std::get<0>(res) <<  "  " <<  std::get<1>(res) << "\n";
}

int main( int ac, char **av )
{
	sub_array_sum_test_1();
	sub_array_sum_test_2();
    sub_array_sum_test_3();
	return 0;	
}
