class Solution {
public:
    
    
    
    int romanToInt(string s) {
        int R2I[255] = {0,};
    
        R2I['I'] = 1;
        R2I['V'] = 5;
        R2I['X'] = 10;
        R2I['L'] = 50;
        R2I['C'] = 100;
        R2I['D'] = 500;
        R2I['M'] = 1000;
        
        int res = R2I[ s[0] ];
        for ( auto i = 1; i < s.length() ; ++i ) {
            if ( R2I[ s[i-1] ] < R2I[ s[i] ] ) {
                res += R2I[ s[i] ] - 2*R2I[ s[i-1] ] ;
            } else {
                res += R2I[ s[i] ];
            }
        }
        return res;
    }
};