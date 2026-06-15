class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int,int> m;
        int maj = 0;
        for ( auto n : nums )
        {
            auto v = m.find(n);
            if( v != m.end() )
            {
                m[n] += 1;
            }
            else
            {
                m.insert( std::pair<int, int>(n,1));
            }
            if ( m[n] > nums.size()/2 )
                maj = n;
            
        }
        return maj;
    }
};