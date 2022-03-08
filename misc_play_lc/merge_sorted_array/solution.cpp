class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::vector<int> nums;
            auto i = 0;
            auto j = 0;

            for( ; ; )
            {
                if( i == m && j == n )
                    break;

                if( i < m && j < n )
                {
                    if( nums1.at(i) < nums2.at(j) )
                        nums.push_back( nums1.at(i++) );
                    else
                        nums.push_back( nums2.at(j++) );
                }
                else if ( i < m )
                {
                    nums.push_back( nums1.at(i++) );
                }
                else
                {
                    nums.push_back( nums2.at(j++) );   
                }
            }

            i = 0;
            for( auto x : nums )
            {
                nums1[ i ++ ] = x;
            }
    }
};