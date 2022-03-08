class Solution {

	int int_min() {
		unsigned int max = 0;
 
	    // Computing NOT of 0
	    max = ~max;
	     
	    // 1 time arithmetic right shift
	    max = max >> 1;
	     
	    // Computing INT_MIN
	    int min = max;
	     
	    // INT_MIN = ~INT_MAX
	    min = ~min;

	    return min;
	}

public:
	/// its  Kadane's algo ..
    int maxSubArray(std::vector<int>& nums) {
    	int max_sum  = int_min();
    	int sum = 0;
        
        /// for every n in nums
        for ( auto n : nums ) {

        	/// Keep calculating the sum
            sum += n;
            max_sum = std::max( max_sum,  sum );

            /// if sum falls below zero 
            /// reset to zero and do it again
            sum =  ( sum < 0 ) ? 0 : sum;
        }
        
        return max_sum;
    }
};
