class Solution {
public:
    bool checkOnesSegment(string s) {
        bool is_prev_zero = false;
        for ( auto c : s) {
            if ( c == '0' ) {
                is_prev_zero = true;
                continue;
            }
                
            if ( c == '1' and is_prev_zero )
                return false;
            
       }
    
        return true;
    }
    
 
};