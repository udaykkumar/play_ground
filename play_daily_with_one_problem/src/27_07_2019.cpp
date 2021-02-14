/*
Hi, here's your problem today. This problem was recently asked by Google:

Given a mathematical expression with just single digits, plus signs, negative
signs, and brackets, evaluate the expression. Assume the expression is properly
formed.

Example:

Input: - ( 3 + ( 2 - 1 ) )
Output: -4

Here's the function signature:


def eval(expression):
  # Fill this in.

print eval('- (3 + ( 2 - 1 ) )')
# -4


*/

#include <27_07_2019.hpp>
#include <stack>
namespace daily_interview
{

	int precedence(char op)
	{ 
    	if(op == '+'||op == '-') 
    		return 1; 

    	if(op == '*'||op == '/') 
    		return 2; 

    	return 0; 
	}

	int operate( int v1, int v2, char op )
	{
		switch(op)
		{
			case '+': return v1 + v2;
			case '-': return v1 - v2;
			case '*': return v1 * v2;
			case '/': return v1 / v2;
		}
        return 0;
	}


	int eval(std::string exp)
	{
		std::stack<int>  value_stack;
		std::stack<char> operator_stack;

		for( auto token : exp )
		{
			if( std::isspace(token) )
				continue;

			if( std::isdigit(token) )
			{
				value_stack.push( token - '0' );
				continue;
			}

			if( token == '(' )
			{
				operator_stack.push(token);
				continue;
			}

			if( token == ')' )
			{
				while( operator_stack.empty() == false &&  operator_stack.top() != '(' )
				{
					int v2 = value_stack.top(); value_stack.pop();
					int v1 = value_stack.top(); value_stack.pop();
					char op= operator_stack.top(); operator_stack.pop();

					value_stack.push( operate( v1, v2, op ));
				}

				operator_stack.pop();
				continue;
			}

			/* at this point its an operator */
			while( operator_stack.empty() == false && precedence(operator_stack.top()) >= precedence(token) )
			{
				int v2 = value_stack.top(); value_stack.pop(); 
                int v1 = value_stack.top(); value_stack.pop(); 
                char op= operator_stack.top(); operator_stack.pop();
                
                value_stack.push( operate( v1, v2, op ));
            } 
			operator_stack.push(token); 
		}

		while( operator_stack.empty() == false )
		{ 
			if( value_stack.size() < 2 )
				break;

        	int v2 = value_stack.top(); value_stack.pop(); 
            int v1 = value_stack.top(); value_stack.pop(); 
            char op= operator_stack.top(); operator_stack.pop();
                
            value_stack.push( operate( v1, v2, op ));
        } 

        if (operator_stack.empty())
        {
        	return value_stack.top();
        }

        return ( operator_stack.top() == '-' ) ? -value_stack.top() : value_stack.top();
         
   }
}

