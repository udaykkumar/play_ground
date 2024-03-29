//https://leetcode.com/problems/reverse-integer/
/*
 Given a 32-bit signed integer, reverse digits of an integer.

 Example 1:

 Input: 123
 Output: 321
 Example 2:

 Input: -123
 Output: -321
 Example 3:

 Input: 120
 Output: 21
 Note:
 Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: 
 [−2^31,  2^31 − 1]. 
 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 */

#ifndef __LC_E_0002_HPP_INCLUDED__
#define __LC_E_0002_HPP_INCLUDED__
#include <iostream>

namespace lc
{
int reverse(int x);

int reverse_Method_2(int x);
}

#endif
