
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
    		if ( is_open(c) ) {
    			st.push(c);
    		} else {
    			if ( st.empty() ) 
    				return false;
    			
    			if ( not is_open( st.top() ) )
    				return false;

    			if ( (st.top() == '(' and c == ')') or 
    				 (st.top() == '{' and c == '}') or 
    				 (st.top() == '[' and c == ']'))
    			{
    				st.pop();
    			} else {
    				return false;
    			}
    		}
    	}

        return st.empty();
    }
};