class Solution {
public:
    string addBinary(string a, string b) {
        std::string res("");
        int           c = 0;
        for( int i(a.size() -1),  j(b.size() -1) ; not ( i < 0 && j < 0 ) ;  i --, j -- )
        {
            int x  = ( i < 0 ) ? 0 : a[i] - '0';
            int y  = ( j < 0 ) ? 0 : b[j] - '0';

            int r = (x + y + c) & 0x01;
                c = ((x + y + c) >> 1) & 0x01;

            res += (r + '0');

        }

        if( c > 0 )
            res += (c + '0');   

         std::reverse( res.begin(), res.end() );

         return res;
    }
};