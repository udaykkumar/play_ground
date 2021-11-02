#include "021_Stack.hpp"
#include <vector>
namespace ds
{
	template < typename T >
	class Node 
	{
		private:
			T value_;
			std::shared_ptr< Node<T> > next_;

		public:
			Node(T val) :
				value_(val)
			{

			}

			~Node()
			{

			} 

			std::shared_ptr< Node<T> > &next() { return next_;  }
			T 							value(){ return value_; }
		
	};

	template < typename T >
	stack<T>::stack() :
		count_(0)
	{

	}

	template < typename T >
	stack<T>::~stack()
	{
		
	}

	template < typename T >
	bool stack<T>::is_empty() const
	{
		return ( count_ == 0 );
	}
	
	template < typename T >
	T    stack<T>::top()
	{
		if ( is_empty() )
			return -1;

		return top_->value();
	}
	
	template < typename T >
	void stack<T>::push(T val)
	{
		auto n = std::make_shared<Node<T>>(val);
		n->next() = top_;
		top_ = n;

		count_ += 1;
	}
	
	template < typename T >
	void stack<T>::pop()
	{
		if ( is_empty() )
			return;
		top_ = top_->next();
		count_ -= 1;
	}
}

bool is_match( char op, char cl )
{
	switch (op)
	{
		case '{': return cl == '}';
		case '(': return cl == ')';
		case '[': return cl == ']';
	}
	return false;
}

bool is_open(char c)
{
	return (c == '(' or c == '{' or c == '[');
}

bool validate_paranthesis( std::string expression )
{
	ds::stack< char > stk;

	/// loop through all the paranthesis
	for ( auto c : expression ) {

		/// if its Open just put into stack and move on
		if ( is_open(c) ) {
			stk.push(c);
			continue;
		}
		
		/// Closed bracket .. if there is a match its still valid
		/// move on to next
		if ( is_match( stk.top(), c )) {
			stk.pop();
			continue;
		}
		
		/// we are here means its a problem
		return false;
	}

	/// its only true we have nothing left 
	if ( stk.is_empty() ) {
		return true;
	}

	return false;
}


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