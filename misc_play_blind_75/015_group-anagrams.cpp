

/**
 *

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.


 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
    
    std::unordered_map< std::string, std::vector< std::string> > anagramTracker_;

    bool exists( std::string &k ) {
        return anagramTracker_.find(k) != anagramTracker_.end();
    }

    void append( std::string &k, std::string &v) {
        anagramTracker_[k].emplace_back(v);
    }

    void add(std::string &k, std::string &v) {
        anagramTracker_[k] = std::vector<std::string>{v};
    }

    const std::unordered_map< std::string, std::vector< std::string> > &hash() {
        return anagramTracker_;
    }


public:
    std::vector< std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
        std::vector< std::vector<std::string> > res;
        for ( auto s : strs ) {
            auto ostring(s);
            std::sort( s.begin(), s.end() );
            if ( exists(s) ) {
                append(s, ostring);
            } else {
                add(s, ostring);
            }
        }

        for ( auto kvp : hash() ) {
            res.emplace_back(kvp.second);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    
    {
        Solution s;
        std::vector<std::string>  strs{  "eat","tea","tan","ate","nat","bat" };

        auto res = s.groupAnagrams(strs);
        for ( auto r : res ) {
            for ( auto ri : r ) {
                std::cout << ri << " " ;
            }
            std::cout << std::endl;
        }
    }

    {
        Solution s;
        std::vector<std::string>  strs{  "" };

        auto res = s.groupAnagrams(strs);
        for ( auto r : res ) {
            for ( auto ri : r ) {
                std::cout << ri << " " ;
            }
            std::cout << std::endl;
        }
    }

    {
        Solution s;
        std::vector<std::string>  strs{  "a" };

        auto res = s.groupAnagrams(strs);
        for ( auto r : res ) {
            for ( auto ri : r ) {
                std::cout << ri << " " ;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}