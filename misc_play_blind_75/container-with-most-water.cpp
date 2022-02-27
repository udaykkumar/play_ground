/**
 * 

 You are given an integer array height of length n. 
 There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1

**/

#include <iostream>
#include <vector>


class Solution {

	int area( int left, int right, int width) {
		//std::cout << " left " << left << " right " << right  << " width " << width << "\n";
		return std::min(left, right) * width;
	}

public:
    int maxArea(std::vector<int>& height) {
        /// the key to answering this question is reading carefully
        ///
        /// Find two lines that together with the x-axis form a container, -- this line is the key
        ///
        /// essentially we have to find two lines and distance between that form maximum area
        /// nothing facny .. water , container is a distraction .. 
        ///

        int max_area    = 0;
        int left_index  = 0;
        int right_index = height.size()-1;

        /// we start from left and right .. 
        /// calculate the area and converge slowly based on the hight 
        /// keeping track of max in every iteration ..
        /// at the end we are left with max 
        while( left_index <= right_index ) {

        	int left_line  = height[left_index];
        	int right_line = height[right_index];

        	max_area = std::max( area(left_line, right_line, right_index - left_index ), max_area);
        	if ( left_line < right_line ) {
        		left_index ++;
        	} else {
        		right_index --;
        	}

        }
        return max_area;
    }
};

int main(int argc, char const *argv[])
{
	{
		Solution s;
		std::vector<int> height = {1,8,6,2,5,4,8,3,7};
		std::cout << "area " << s.maxArea(height) << "\n";
	}

	{
		Solution s;
		std::vector<int> height = {1,1};
		std::cout << "area " << s.maxArea(height) << "\n";
	}

	{
		Solution s;
		std::vector<int> height = {1,8,100,2,100,4,8,3,7};
		std::cout << "area " << s.maxArea(height) << "\n";
	}
	return 0;
}