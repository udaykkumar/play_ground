

/**
 *

Given two strings s and t of lengths m and n respectively, 
return the minimum window substring of s such that every character in t (including duplicates) 
is included in the window. 

If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

A substring is a contiguous sequence of characters within the string.

 

Example 1:

Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
Example 2:

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.
Example 3:

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 

Constraints:

m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
 

Follow up: Could you find an algorithm that runs in O(m + n) time?

 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
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

int main(int argc, char const *argv[]) {
    
    {
        Solution so;
        std::string s = "ADOBECODEBANC";
        std::string t = "ABC";

	    std::cout << s << " " << t << " " << so.minWindow(s,t) << "\n";
    }

    {
        Solution so;
	    std::string s = "a";
        std::string t = "a";

	    std::cout << s << " " << t << " " << so.minWindow(s,t) << "\n";
    }

    {
        Solution so;
	    std::string s = "a";
        std::string t = "aa";

	    std::cout << s << " " << t << " " << so.minWindow(s,t) << "\n";
    }

    return 0;
}