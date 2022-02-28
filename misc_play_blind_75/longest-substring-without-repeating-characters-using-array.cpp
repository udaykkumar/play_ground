#include <iostream>
#include <unordered_map>


/**
 * 
 *

 Given a string s, find the length of the longest substring without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

**/
class Solution {

	int vtoi_[256];

	void see( char k , int v) {
		vtoi_[size_t(k)] = v; 
	}

	bool seen( const char k ) const {
		return vtoi_[size_t(k)] != -1;
	}

	int  last_seen_index( char k )   {
		return vtoi_[size_t(k)];
	}

    void forget()  {
        for ( size_t i = 0 ; i < 256; ++i ) {
        	vtoi_[i] = -1;
        }
    }

	
public:
	int lengthOfLongestSubstring(std::string s) {
     	
     	/// default max_len is 0 for empty strings .
    	int max_len = 0, len = 0;

    	/// for every character in s
    	for ( size_t i = 0 ; i < s.size(); ) {
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


int main(int argc, char const *argv[])
{
	Solution s;
	{
		
		std::string str{ "abcabcbb" };
		std::cout << str << " " << s.lengthOfLongestSubstring(str) << "\n";
	}
	{
		std::string str{ "bbbbbb" };
		std::cout << str << " " << s.lengthOfLongestSubstring(str) << "\n";
	}
	{
		std::string str{ "pwwkew" };
		std::cout << str << " " << s.lengthOfLongestSubstring(str) << "\n";
	}

	{
		std::string str{ " " };
		std::cout << str << " " << s.lengthOfLongestSubstring(str) << "\n";
	}


	{
		std::string str{ "au" };
		std::cout << str << " " << s.lengthOfLongestSubstring(str) << "\n";
	}

	{
		std::string str{ "aub" };
		std::cout << str << " " << s.lengthOfLongestSubstring(str) << "\n";
	}
	return 0;
}