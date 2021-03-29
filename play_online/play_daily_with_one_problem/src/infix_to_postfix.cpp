#include <infix_to_postfix.hpp>
#include <cctype>
#include <stack>

namespace bira
{

    int precidence( const char ch)
    {
        if(ch == '+' || ch == '-')
        {
            return 1;              //Precedence of + or - is 1
        }
        else if(ch == '*' || ch == '/')
        {
            return 2;            //Precedence of * or / is 2
        }
        else if(ch == '^')
        {
            return 3;            //Precedence of ^ is 3
        }
        else
        {
            return 0;
        }
    }

    bool if_lesser_precidence( const char c1, const char c2 )
    {
        return precidence(c1) < precidence(c2);
    }

    std::string infix_to_post_fix( std::string &expression )
    {
        std::string         post_fix;
        std::stack<char>    stack;

        for ( auto literal : expression )
        {
            if(isalnum(literal))
                post_fix += literal;
            else if ( literal == '(' || literal == '^' )
                stack.push(literal);
            else if ( literal == ')' )
            {
                for( ; !stack.empty() && stack.top() != '('; stack.pop() )
                    post_fix += stack.top();

                if( !stack.empty() )
                    stack.pop();
            }
            else
            {
                for( ; !stack.empty() && if_lesser_precidence( literal, stack.top() ); stack.pop() )
                    post_fix += stack.top();

                stack.push(literal);
            }
        }

        for( ; !stack.empty(); stack.pop() )
            post_fix += stack.top();

        return post_fix;
    }

}


