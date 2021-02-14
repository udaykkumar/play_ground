#include<iostream>
#include<vector>

// Just for fun - lets typedef this 

typedef std::vector<int> intStack_t;

std::ostream& operator<<( std::ostream& os, const intStack_t& v ) 
{
    for( auto i: v ) { os << i << "<-"; }
    os << "Top";
    os << std::endl << "( Capacity " << v.capacity() << " , " << " Length " << v.size() << ")";
    return os;
}


int main()
{
    intStack_t iStack;

        std::cout << iStack << std::endl;

        iStack.push_back(3);
        std::cout << iStack << std::endl;

        iStack.push_back(4);
        std::cout << iStack << std::endl;

        iStack.push_back(1);
        std::cout << iStack << std::endl;

        std::cout << "Top -> " << iStack.back() << std::endl;

        iStack.pop_back();
        std::cout << iStack << std::endl;

        iStack.pop_back();
        std::cout << iStack << std::endl;

        iStack.pop_back();
        std::cout << iStack << std::endl;

	return 0;
}
