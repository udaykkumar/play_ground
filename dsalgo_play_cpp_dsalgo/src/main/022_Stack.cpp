#include "022_Stack.hpp"

#include <vector>

int main(int argc, char const *argv[])
{
	ds::stack<int> s;

	for (int i = 0; i < 10; ++i)
	{
		s.push(i);
		std::cout << "top " << s.top()  << std::endl;
	}

	while ( not s.is_empty() )
	{
		std::cout << "top " << s.top() << std::endl;
		s.pop();
	}

	std::vector < std::string > paranthesis = {
		"{{{{}}}}",
		"{()}",
		"[{()}]",
		"[()",
		"((()))]"
	};

	for ( auto p : paranthesis )
		std::cout << p << " " << validate_paranthesis(p) << std::endl;
	
	return 0;
}