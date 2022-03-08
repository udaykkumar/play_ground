class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        for ( auto r : grid )
            for ( auto c : r )
                if ( c < 0 )
                    res ++;
        return res;
    }
};