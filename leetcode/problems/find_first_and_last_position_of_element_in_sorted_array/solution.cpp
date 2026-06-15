class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        
        if ( nums.size() == 1) {
            return  (nums[0] == target) ? 
                    std::vector<int>({0,0}) : std::vector<int>({-1,-1});
        }
        /*
            Lets talk a little loud,
            and O(log n) + sorted key words
            always rings a binary search
            
            so some kind of max and min indexes and search
        */
        
        int min = 0, max = nums.size()-1;
        int index = -1;
        while (min < max and min >= 0 and max < nums.size())
        {
            if (nums[min] == target)
            {
                index = min;
                break;
            }
            
            if (nums[max] == target)
            {
                index = max;
                break;
            }

            int mid = (max + min) /2;
            if ( nums[mid] == target)
            {
                index = mid;
                break;
            }
            
            if ( target < nums[mid] )
            {
                max = mid-1;
            }
            else
            {
                min = mid+1;
            }
        }
        
        
        if (index == -1)
            return std::vector<int>({-1,-1});
        
        int lower_index = index;
        for ( ; lower_index >= 0  and nums[lower_index] == target ; lower_index--);
        lower_index += 1;
        
        int upper_index = index;
        for ( ;upper_index < nums.size() and nums[upper_index] == target ; upper_index++);
        upper_index -= 1;
        
        return std::vector<int>({lower_index, upper_index});
    }
};