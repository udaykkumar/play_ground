

/**
 *
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

Accepted
1,131,429
Submissions
1,852,915

 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if ( s.size() != t.size() ) return false;
        if ( s.size() == 0 ) return true;

        std::unordered_map< int, int > vmap;
        for ( auto c : s ) {
        	vmap[c] ++;
        }

     	for ( auto c : t ) {
        	vmap[c] --;
        }
          
         for( auto kvp : vmap ) {
           if ( kvp.second > 0 )
               return false;
       }

        return true;
    }
};

int main(int argc, char const *argv[]) {
    
    {
        Solution so;
        std::string s = "anagram";
        std::string t = "nagaram";
        std::cout << s << " " << t << so.isAnagram(s,t) << "\n";
	   
    }

	{
        Solution so;
        std::string s = "rat";
        std::string t = "car";
        std::cout << s << " " << t << so.isAnagram(s,t) << "\n";
	   
    }
    return 0;
}