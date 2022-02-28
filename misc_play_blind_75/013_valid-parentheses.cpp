/**
 Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
**/
#include <iostream>
#include <stack>

class Solution {

	bool is_open( char c ) {
		return c == '(' or c == '{' or c == '[';
	}

	bool is_closed( char c ) {
		return c == ')' or c == '}' or c == ']';
	}

public:
    bool isValid(std::string s) {
        
        std::stack<char> st;

    	for ( auto c : s ) {

    		/// any open brace must go into stack
    		if ( is_open(c) ) {
    			st.push(c);
    		} else {

    			/// On a close brace stack cant be emtpy
    			if ( st.empty() ) 
    				return false;

    			/// stack top must compensate with c
    			if ( (st.top() == '(' and c == ')') or 
    				 (st.top() == '{' and c == '}') or 
    				 (st.top() == '[' and c == ']'))
    			{
    				st.pop();
    			} else {

    				/// if it doesn't its a failure
    				return false;
    			}
    		}
    	}

    	/// by the end of processing stack must be 
    	/// empty
        return st.empty();
    }
};

int main(int argc, char const *argv[])
{
	{
		Solution s;
		std::string str{"()"};
		std::cout << " str " << str << " " << s.isValid(str) << "\n";
	}
	{
		Solution s;
		std::string str{"()[]{}"};
		std::cout << " str " << str << " " << s.isValid(str) << "\n";
	}
	{
		Solution s;
		std::string str{"(]"};
		std::cout << " str " << str << " " << s.isValid(str) << "\n";
	}

	{
		Solution s;
		std::string str{"("};
		std::cout << " str " << str << " " << s.isValid(str) << "\n";
	}

	{
		Solution s;
		std::string str{"]"};
		std::cout << " str " << str << " " << s.isValid(str) << "\n";
	}

	return 0;
}