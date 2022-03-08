class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for ( ; left <= right;  left ++  )
        {
            bool yes = true;
            for ( int x = left; x > 0 ; x /= 10 )
            {
                int r = x%10;
                if ( r == 0 || left%r != 0 )
                {
                    yes = false;
                    break;
                }
            }
            
            if ( yes )
                res.push_back(left);
        }
        
        return res;
    }
};