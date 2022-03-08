class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        if ( gain.size() == 0 )
            return 0;
        int sum = gain[0];
        int max_sum = sum;
        for ( int i = 1; i < gain.size(); ++i )
        {
            sum += gain[i];
            max_sum = std::max( max_sum, sum );
        }    
        
        return max_sum < 0 ? 0 : max_sum;
    }
};