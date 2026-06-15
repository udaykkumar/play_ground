class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        
        for ( int l = 1 ; l <= arr.size(); l += 2 )
        {
            for ( int i = 0 ; i < arr.size() ; i ++)
            {
                int subsum = 0;
                int k = i;
                for (  ; (k < l+i) && k < (arr.size()) ; ++k )
                    subsum += arr[k];
                
                if ( k == l+i)
                    sum += subsum;
            }
        }
        
        return sum;
    }
};