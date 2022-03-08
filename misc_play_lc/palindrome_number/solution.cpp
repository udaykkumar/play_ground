class Solution {
public:
    bool isPalindrome(int x) {
        
        // These are my obvious cases only case I'm little doubt ful of is 
        // x < 10 single digits but lets see
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        if (x%10 == 0)
            return false;
        
        std::vector<int> r;
        for( ;x; x /= 10)
            r.push_back(x%10);
        
        for( int i = 0, j = r.size()-1;
            i < j; i ++, j -- ) {
            if( r[i] != r[j] )
                return false;
        }
        
        return true;
    }
};