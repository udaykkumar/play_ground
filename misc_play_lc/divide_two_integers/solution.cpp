class Solution {
public:
    int divide(int dividend, int divisor) {
        bool is_negative = false ;
        if ( (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ){
            is_negative = true;
        }
            
        long dd = dividend;
        long dv = divisor;
        if( dd < 0 )
            dd = -dd;
        if( dv < 0 )
            dv = -dv;
        
        
        long i = dd;
        long res = 0;
        if ( dv == 1 )
            res = i;
        else 
        {
            for ( ; i >= dv ; ++res )
                i = i - dv;
        }
        
        
        if( is_negative ){
            if ( -res < -2147483648l )
                    return -2147483648;
        } else {
            if ( res > 2147483647 )
                return 2147483647;
        }
            
        return  is_negative ? -res : res;
    }
};