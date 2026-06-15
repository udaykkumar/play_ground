class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res("");
        if ( strs.size() > 0 ) {
            for ( int col = 0; strs[0][col] ; col ++ ) {
                for ( int row = 0; row < strs.size(); row ++ ) {
                    if ( strs[row][col] != strs[0][col] ) {
                        return res;
                    }
                }
                res += strs[0][col];
            }
        }
        return res;
    }
};