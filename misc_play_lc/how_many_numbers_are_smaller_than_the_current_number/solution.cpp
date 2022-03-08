class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
       for ( int i = 0; i < nums.size() ; ++i )
       {
           int less = 0;
           for ( int j = 0 ; j < nums.size() ; ++j )
           {
               if ( i == j )
                   continue;
                if( nums[i] > nums[j] )
                    less++;
           }
            res.push_back(less);
       }
        return res;
    }
};