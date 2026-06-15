class Solution {
public:
    int numberOfSteps (int num) {
        int steps = 0;
        for ( ; num ; ++ steps )
        {
            if( num&0x01 )
            {
                num -= 1;
            }
            else
            {
                num >>= 1;
            }
        }
        
        return steps;
    }
};