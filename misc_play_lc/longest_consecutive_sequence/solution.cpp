class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set< int > journal( nums.begin(), nums.end());
        
        int longest = 0;
        for ( auto n : nums ) {
            if( journal.count(n) > 0 ) {
                journal.erase(n);
                int s = n-1;
                for ( ; journal.count(s) > 0 ; -- s) {
                    journal.erase(s);
                }
                int e = n+1;
                for ( ; journal.count(e) > 0 ; ++ e) {
                    journal.erase(e);
                }
                
                longest = std::max ( e - s -1, longest );
            }
        }
        
        return longest;
        
    }
};