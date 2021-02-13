/*
Hi, here's your problem today. This problem was recently asked by Uber:

Imagine you are building a compiler. Before running any code, the compiler must check that the parentheses in the program are balanced. Every opening bracket must have a corresponding closing bracket. We can approximate this using strings. 

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. 
An input string is valid if:
- Open brackets are closed by the same type of brackets.
- Open brackets are closed in the correct order.
- Note that an empty string is also considered valid.

Input: "((()))"
Output: True

Input: "[()]{}"
Output: True

Input: "({[)]"
Output: False

 */
#include <14_07_2019.hpp>

bool bracket_sequence::is_open_bracket(const char c)
{
    return (c == '(' || c == '{' || c == '[');
}

bool bracket_sequence::is_stack_empty()
{
    return (stack.size() == 0);
}

bool bracket_sequence::is_matching_pair(const char current)
{
    const char stack_top = stack.back();
    const bool retVal = ((stack_top == '(' && current == ')') ||
                         (stack_top == '{' && current == '}') ||
                         (stack_top == '[' && current == ']'));
    stack.pop_back();
    return retVal;
}

bool bracket_sequence::is_valid()
{
    for (auto s : sequence)
    {
        if (is_open_bracket(s))
        {
            stack.push_back(s);
        }
        else
        {
            if (is_stack_empty())
                return false;
            if (!is_matching_pair(s))
                return false;
        }
    }
    return true;
}
