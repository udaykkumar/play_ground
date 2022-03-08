class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = -1;
        for ( auto a : accounts )
        {
            int sum = 0;
            for ( auto s : a )
                sum += s;
            max = std::max ( max , sum );

        }
        
        return max;
    }
};