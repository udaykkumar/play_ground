#include <LC_E_0006.hpp>
#include <list>
namespace lc
{
    bool isValid(std::string s)
    {
        std::list< char > stack;
        bool  isOpen[255] = {false,};

        isOpen['['] = true;
        isOpen['{'] = true;
        isOpen['('] = true;

        for( auto c : s )
        {
            if( isOpen[(size_t)c] )
                stack.push_back(c);
            else
            {
                auto top = stack.back();
                if( ((top == '[') and (c == ']')) or
                    ((top == '{') and (c == '}')) or
                    ((top == '(') and (c == ')')) )
                {
                    stack.pop_back();
                    continue;
                }

                return false;
            }
        }
        return (stack.size() == 0);
    }
}

