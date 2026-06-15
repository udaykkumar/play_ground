class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        std::unordered_map<int, int> degrees;
        int max_degree = 0;
        for ( auto n : nums ) 
        {
            degrees[n] ++;
            if ( max_degree < degrees[n] )
                max_degree = degrees[n];
        }
        
        std::vector<int> matches;
        for ( auto items : degrees )
        {
            if ( items.second == max_degree )
                matches.push_back(items.first);
        }
        
        int min_length = nums.size();
        for ( auto n : matches )
        {
            int first = 0;
            int last  = nums.size()-1;
            while( nums[first] != n )
                first ++;
            
            while( nums[last] != n )
                last --;
            
            //auto last  = std::find( nums.rbegin(), nums.rend(), n);
            
            int  length = last - first + 1;
            if( length < min_length )
                min_length = length;
        }
        
        return min_length;
        
    }
};