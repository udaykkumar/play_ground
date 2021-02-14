/*
Hi, here's your problem today. This problem was recently asked by AirBNB:

Given a sorted array, A, with possibly duplicated elements, find the indices of the first and last occurrences of a target element, x. Return -1 if the target is not found.

Example:
Input: A = [1,3,3,5,7,8,9,9,9,15], target = 9
Output: [6,8]

Input: A = [100, 150, 150, 153], target = 150
Output: [1,2]

Input: A = [1,2,3,4,5,6,10], target = 9
Output: [-1, -1]

 */

#include <15_07_2019.hpp>

std::pair<int,int> bounds(std::vector<int> array, int target ) {

    int first{-1}, last{-1};
    for( size_t i = 0; i < array.size(); i ++ ) {
        if( array[i] == target ) {
            if( first == -1 ) {
                first = i;
            }
            last  = i;
        }
    }
    return std::make_pair(first,last);
}

#if 0
int main() {
    std::vector<int> input;
    std::pair<int, int> result;
                int target;
    

    input = {1,3,3,5,7,8,9,9,9,15};
    target = 9;
    result = bounds(input, target);
    std::cout <<  " " << result.first << " " << result.second << std::endl;

    input = {100, 150, 150, 153};
    target = 150;
    result = bounds(input, target);
    std::cout <<  " " << result.first << " " << result.second << std::endl;


    input = {1,2,3,4,5,6,10};
    target = 9;
    result = bounds(input, target);
    std::cout <<  " " << result.first << " " << result.second << std::endl;

    return 0;
}
#endif