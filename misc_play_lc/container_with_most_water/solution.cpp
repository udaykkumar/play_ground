class Solution {

	int area( int left, int right, int width) {
		//std::cout << " left " << left << " right " << right  << " width " << width << "\n";
		return std::min(left, right) * width;
	}

public:
    int maxArea(std::vector<int>& height) {
        
        int max_area    = 0;
        int left_index  = 0;
        int right_index = height.size()-1;

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