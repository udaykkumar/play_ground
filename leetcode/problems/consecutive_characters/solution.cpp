class Solution {
public:
    int maxPower(string s) {
        int maxPower = 1;
        int power    = 1;
        for( int i = 0 ; i < s.size()-1 ; i ++ ) {
            power =  ( s[i] != s[i+1] ) ? 1 : (++power);
            if ( maxPower < power )
                maxPower = power;
        }
        
        return maxPower;
    }
};