class Solution {
public:
    string convert(string s, int numRows) {
     if( numRows == 1 )
         return s;
        
     vector<string> strs(min(numRows, int(s.length())));
     int cr = 0;
     bool down = false;
     for( auto c: s )
     {
         strs[cr] += c;
         down = ( cr == 0 || cr == numRows - 1) ? !down : down;
         cr += down ? 1 : -1;
     }
                          
     string r;
        for( auto st : strs)
            r += st;
     
      return r;
    }
};