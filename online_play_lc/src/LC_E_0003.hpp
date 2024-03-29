//https://leetcode.com/problems/palindrome-number/
/*

 Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

 Example 1:

 Input: 121
 Output: true
 Example 2:

 Input: -121
 Output: false
 Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 Example 3:

 Input: 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

 */
#ifndef __LC_E_0003_HPP_INCLUDED__
#define __LC_E_0003_HPP_INCLUDED__

namespace lc
{
bool isPalindrome(int x);
bool isPalindrome_Method_2(int x);
bool isPalindrome_Method_3_2_Years_Ago(int x);
}

#endif
