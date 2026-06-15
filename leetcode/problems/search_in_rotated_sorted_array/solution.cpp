class Solution {

	
public:
    int search(std::vector<int>& nums, int target) {
    	int lo = 0;
    	int hi = nums.size()-1;

    	while ( lo <= hi ) {
    		/// This is the correct way to calculate mid
    		/// start + ( end - start ) /2  
    		int mid = lo + ((hi - lo) >> 1);

    		/// Got what we need
    		if ( nums[mid] == target )  return mid;
    		
    		if ( nums[mid] >= nums[lo] ) { 
    			/// sorted from lo to mid 

				if ( target >= nums[lo] and target < nums[mid] )
					/// Its within this list bring down hi to within this list
					hi = mid-1;
				else
					/// its in other list
					lo = mid+1;
			
			} else {
				 /// unsorted part

				if ( target <= nums[hi] and target > nums[mid] )
					/// Its within this list .. bring up the lo 
					lo = mid + 1;
				else
					/// its in other part .. move hi down
					hi = mid -1;
			}	
    	}
       
       return -1;
    }
};