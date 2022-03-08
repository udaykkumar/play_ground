class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
       
        // Just getrid of unnecessary things first
        if( nums.size() < 4 )
            return std::vector< std::vector<int> >() ;
        
        std::unordered_set< std::string > tracker;
        
        // we first sort the array first just for fun
        std::sort( nums.begin(), nums.end() );
        
        // This is the result
        std::vector< std::vector<int> > res;
        
        
        // Lets just torture the program
        // and do some crazy stuff
        for ( int i = 0 ; i < nums.size()-3 ; ++i )
        {
            int a = nums[i];
            for ( int j = i+1 ; j < nums.size()-2; ++j )
            {
                int b = nums[j];
                for ( int k = j+1; k < nums.size() -1; ++k )
                {
                    int c = nums[k];
                    for ( int l = k+1; l < nums.size(); ++l )
                    {
                        int d = nums[l];
                        if ( a + b + c + d == target )
                        {
                            std::string k= std::string(  std::to_string(a) + "-" +
                                            std::to_string(b) + "-" +
                                            std::to_string(c) + "-" +
                                            std::to_string(d) );
                            if ( tracker.find( k ) == tracker.end() )
                            {
                                res.emplace_back( std::vector<int>{ a, b, c, d } );
                                tracker.insert(k);
                            }    
                        }
                    }
                }
            }
        }
        
        return res;
    }
};