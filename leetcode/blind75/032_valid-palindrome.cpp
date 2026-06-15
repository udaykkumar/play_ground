

/**
 *
A phrase is a palindrome if, after converting all uppercase letters
 into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 

Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
Accepted
1,157,015
Submissions
2,821,802

 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
class Solution {
public:
    bool isPalindrome(std::string s) {
        
        int start = 0;
        int end   = s.size()-1;
        while( start < end ) {
        	auto sc{ s[start] };
        	auto ec{ s[end]   };

        	/// small and equal at both ends .. keeep going
        	if ( std::tolower(sc) == std::tolower(ec)) {
        		start ++;
        		end --;
        	} else if( not std::isalnum(sc) ) {
        		/// its probably not a  a character
        		start ++;
        	} else if ( not std::isalnum(ec)) {
        		/// its probably not a  a character
        		end --;
        	} else {
        		/// its a char but not equal throwup
        		return false;
        	}

        }
		return true;

    }
};

int main(int argc, char const *argv[]) {
    
    {
        Solution so;
        std::string s = "A man, a plan, a canal: Panama";
         std::cout << s << " " << so.isPalindrome(s) << "\n";
	   
    }
  
    {
        Solution so;
        std::string s = "race a car";
 		std::cout << s << " " << so.isPalindrome(s) << "\n";
    }

    {
        Solution so;
        std::string s = " ";
 		std::cout << s << " " << so.isPalindrome(s) << "\n";
    }

    return 0;
}