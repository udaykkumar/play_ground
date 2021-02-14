/*

https://practice.geeksforgeeks.org/problems/missing-number-in-array/0

Given an array C of size N-1 and given that there are numbers from 
1 to N with one element missing, the missing number is to be found.

 */

#include <iostream>
#include <algorithm>
#include <vector>

int missing_number_in_array( std::vector<int> array , int n)
{
	int sum = n * ( n + 1) / 2;
	for( auto v : array ) {
		 sum -= v;
	}

	return sum;
}

void missing_number_in_array_test_1()
{
	std::vector<int> array = {1,2,3,5};
	std::cout << missing_number_in_array(array, 5) << std::endl;
}

void missing_number_in_array_test_2()
{
	std::vector<int> array = {1,2,3,4,5,6,8};
	std::cout << missing_number_in_array(array, 8) << std::endl;
}

void missing_number_in_array_test_3()
{
	std::vector<int> array = {1,2,3,4,5,6,7,8,10};
	std::cout << missing_number_in_array(array, 10) << std::endl;
}

int main(int ac, char **av)
{
	missing_number_in_array_test_1();
	missing_number_in_array_test_2();
	missing_number_in_array_test_3();
	return 0;
}

