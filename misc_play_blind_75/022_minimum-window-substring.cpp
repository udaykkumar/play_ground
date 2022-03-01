

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

	bool seen(char c) {
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
    	
    	/// Lets fist Create a map of every character in t 
    	/// and index
    	make_index_map(t);
    	
    	//ADOBECODEBANC , ABC

    	int target_size = t.size();
    	int min_start = 0, min_length = int(s.size());

    	for ( int start = 0, end = 0 ; end < int(s.size()) ; ) {
    		auto ec = s.at(end);

    		if ( seen(ec) ) {
    			target_size --; /// We found one so target size reduces 
    			unsee(ec);
    		}


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

    			/// restart again because the target is reset again
    			target_size++;
    			start ++;
    		}
     	}

     	if( min_length != int(s.size()) )
     		return s.substr(min_start, min_length);

        return "";
    }
};

int main(int argc, char const *argv[]) {
    
    {
        Solution s;
	    std::cout << s.minWindow( "ADOBECODEBANC" , "ABC") << "\n";
    }

    {
        Solution s;
	    std::cout << s.minWindow( "a" , "a") << "\n";
    }

    {
        Solution s;
	    std::cout << s.minWindow( "a" , "aa") << "\n";
    }

    return 0;
}