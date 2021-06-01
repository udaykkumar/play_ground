//https://leetcode.com/problems/longest-common-prefix/
/*
 Write a function to find the longest common prefix string amongst an array of strings.

 If there is no common prefix, return an empty string "".

 Example 1:

 Input: ["flower","flow","flight"]
 Output: "fl"
 Example 2:

 Input: ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
 Note:

 All given inputs are in lowercase letters a-z.

 */
#ifndef __LC_E_0005_HPP_INCLUDED__
#define __LC_E_0005_HPP_INCLUDED__
#include <iostream>
#include <vector>
namespace lc
{
std::string longestCommonPrefix(std::vector<std::string> &strs);
}

#endif
