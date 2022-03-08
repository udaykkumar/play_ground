class Solution {
public:
    void reverseString(vector<char>& s) {
         int i = 0;
         int j = s.size()-1;
        for (; i < j ; i ++ , j -- )
        {
            std::swap( s[i], s[j] );
        }
    }
};