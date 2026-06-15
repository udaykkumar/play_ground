class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::vector<int> v( heights.begin(), heights.end() );
        std::sort( heights.begin(), heights.end() );
        
        int res = 0;
        for ( int i = 0 ; i < v.size() ; i ++ )
        {
            if ( heights[i] != v[i] )
                res ++;
        }
        return res;
    }
};