//https://leetcode.com/problems/add-binary/#ifndef __LC_E_0016_HPP_INCLUDED__
/**
 67. Add Binary
 Easy

 1404

 244

 Add to List

 Share
 Given two binary strings, return their sum (also a binary string).

 The input strings are both non-empty and contains only characters 1 or 0.

 Example 1:

 Input: a = "11", b = "1"
 Output: "100"
 Example 2:

 Input: a = "1010", b = "1011"
 Output: "10101"
 **/
#ifndef __LC_E_0016_HPP_INCLUDED__
#define __LC_E_0016_HPP_INCLUDED__

#include <iostream>

namespace lc
{
std::string addBinary(std::string a, std::string b);
std::string addBinary_Method_2(std::string a, std::string b);
}

#endif
