class Solution {
public:
    bool isHappy(int n) {
        
        auto happy = [=]( int r ) {
            int res = 0;
            while ( r > 0 )
            {
                res += ((r%10) * (r%10));
                r   /= 10;
            }
            return res;
        };
        
        std::unordered_map<int,int> m;
        for( int x = n;; )
        {
            //std::cout << x << "\n";
            x = happy(x);
            //std::cout << x << "\n";
            if ( x == 1 )
                return true;
            m[x] ++;
            if ( m[x] > 1 )
                return false;
        }
    }
};