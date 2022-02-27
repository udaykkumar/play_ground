/***
 * 
 Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.

**/

#include <iostream>
#include <unordered_map>

class Solution {

	std::unordered_map < int , std::string > cache;

	std::string palindrome(std::string &s, int left, int right ) {

		int key =  left * 10000 + right;

		if ( cache.find(key) != cache.end() ) {
			return cache[key];
		}

		while ( (left >= 0) and (right < int(s.size())) and s[left] == s[right] )  {
			left --;
			right ++;
		}

		left =  ( left == -1 ) ? 0 : left + 1;
		right = ( right == int(s.size()) ) ? s.size()-1 : right-1;

		cache[key] = s.substr(left, right);
		return cache[key];
	}

	std::string find_even_palindrome(std::string &s, int mid) {
		int left = mid-1;
		int right = mid;
		return palindrome(s, left, right);
	}

	std::string find_odd_palindrome(std::string &s, int mid) {
		int left = mid-1;
		int right = mid+1;

		return palindrome(s, left, right);
	}

public:
    std::string longestPalindrome(std::string s) {
    	
    	std::string p = "";
    	for ( int i = 0 ; i < int(s.size()) ; ++i ) {
    		std::string lp = find_even_palindrome(s, i);
    		if ( lp.size() > p.size() )
    			p = lp;

    		std::string rp = find_odd_palindrome(s,i);
    		if ( rp.size() > p.size() )
    			p = rp;
    	}
        return p;
    }
};

int main(int argc, char const *argv[])
{
	{
		Solution s;
		std::string str{"babad"};
		std::cout << str << " " << s.longestPalindrome(str) << "\n";
	}
	{
		Solution s;
		std::string str{"cbbd"};
		std::cout << str << " " << s.longestPalindrome(str) << "\n";
	}
	{
		Solution s;
		std::string str{"aptitutit"};
		std::cout << str << " " << s.longestPalindrome(str) << "\n";
	}
	{
		Solution s;
		std::string str{"gooogler"};
		std::cout << str << " " << s.longestPalindrome(str) << "\n";
	}
	{
		Solution s;
		std::string str{"googoog"};
		std::cout << str << " " << s.longestPalindrome(str) << "\n";
	}
	return 0;
}