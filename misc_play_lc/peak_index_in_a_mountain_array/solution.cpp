class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int max_at_index = 0;
        for ( int i = 1 ; i < arr.size() ; ++ i )
        {
            if ( arr[i] > arr[max_at_index] )
                max_at_index = i;
        }
        
        return max_at_index;
    }
};