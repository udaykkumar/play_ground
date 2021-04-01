#ifndef __23_07_2019_HPP_INCLUDED__
#define __23_07_2019_HPP_INCLUDED__
#include <stack>
namespace daily_interview
{
struct stack
{
private:
	std::stack<std::pair<int, int> > stack_;
	std::stack<std::pair<int, int> >& root()
	{
		return stack_;
	}

	std::pair<int, int> peek();

public:
	stack()
	{
	}

	void push(const int x);
	int pop();
	int max();
};
}

#endif
