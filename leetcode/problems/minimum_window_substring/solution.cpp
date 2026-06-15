class Solution {


	int index_map_[128];

	void make_index_map( std::string t ) {
		for ( int i = 0 ; i < 128 ; ++i ) 
			index_map_[i] = 0;
		

		for ( auto c : t ) {
			index_map_[size_t(c)] += 1;
		}
	}

	bool target_char(char c) {
		return (index_map_[size_t(c)] > 0);
	}

	void see(char c) {
		(index_map_[size_t(c)] ++);
	}

	void unsee(char c) {
		(index_map_[size_t(c)] --);
	}


public:
    std::string minWindow(std::string s, std::string t) {
    	
    	/// This acts as INT_MAX for us
    	const int LargeVal = int(s.size()+1);

    	/// Lets fist Create a map of every character in t 
    	/// and index
    	make_index_map(t);
    	
    	
    	int target_size = int(t.size());
    	int min_start = 0, min_length = LargeVal;

    	for ( int start = 0, end = 0 ; end < int(s.size()) ; ) {
    		auto ec = s.at(end);

    		if ( target_char(ec) ) {
    			target_size --; /// We found one so target size reduces 
    		}

    		unsee(ec);
    		// Move on to next 
    		end += 1;

    		/// if target_size == 0 means we found some window
    		while (target_size == 0) {

    			int len = end - start;
    			if( len < min_length ) {
    				min_length = len;
    				min_start = start; 
    			}

    			auto sc = s.at(start);

    			/// Now that the map is clean .. because we did unsee
    			/// see it again .. must find that character again to complete the se
    			see(sc);

    			if ( target_char(sc) )
    				target_size++;

    			start++;
    		}
     	}

     	if( min_length != LargeVal )
     		return s.substr(min_start, min_length);

        return "";
    }
};