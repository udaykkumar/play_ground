class Solution {

	int vtoi_[256];

	void see( char k , int v) {
		vtoi_[k] = v; 
	}

	bool seen( const char k ) const {
		return vtoi_[k] != -1;
	}

	int  last_seen_index( char k )   {
		return vtoi_[k];
	}

    void forget()  {
        for ( int i = 0 ; i < 256; ++i ) {
        	vtoi_[i] = -1;
        }
    }

	
public:
	int lengthOfLongestSubstring(std::string s) {
     	
     	forget();
     	
     	/// default max_len is 0 for empty strings .
    	int max_len = 0, len = 0;

    	/// for every character in s
    	for ( int i = 0 ; i < s.size(); ) {
    		auto c{ s[i] } ;

    		/// if we have seen it, see and move on to next 
    		if ( not seen(c) ) {
                see( c, i ); ++i ; ++len; continue;
            } 

            /// and max is max of previously calculated length
    		max_len = std::max(max_len, len );
              
            // start with next character and reset everything before start
            i = last_seen_index(c) + 1; len = 0 ; forget(); 
            
        }
        return  std::max(max_len, len);
    }
};