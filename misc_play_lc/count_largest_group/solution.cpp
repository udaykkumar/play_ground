class Solution {
public:
    int countLargestGroup(int n) {
        
        std::vector<int> group(40, 0);
        
        for ( int i = 1; i <= n ; i ++ )
        {
            int sum = 0;
            for ( int x = i ;  x > 0 ; x /= 10 )
            {
                sum += (x%10);
            }
            group[sum] += 1;
        }
        
        std::sort( group.begin(), group.end(), std::greater() );
        int max = group[ 0 ];
        int count = 0;
        for ( auto g : group )
        {
            if ( g != max )
                return count;
            count ++;
        }
        return 0;
    }
};