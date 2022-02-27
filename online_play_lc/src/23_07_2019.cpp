/*
 Hi, here's your problem today. This problem was recently asked by Twitter:

 Implement a class for a stack that supports all the regular functions (push,
 pop) and an additional function of max() which returns the maximum element in
 the stack (return None if the stack is empty). Each method should run in
 constant time.


 class MaxStack:
 def __init__(self):
 # Fill this in.

 def push(self, val):
 # Fill this in.

 def pop(self):
 # Fill this in.

 def max(self):
 # Fill this in.

 s = MaxStack()
 s.push(1)
 s.push(2)
 s.push(3)
 s.push(2)
 print s.max()
 # 3
 s.pop()
 s.pop()
 print s.max()
 # 2


 1,1
 2,2

 */
#include <23_07_2019.hpp>

namespace daily_interview
{
std::pair<int, int> stack::peek()
{
	return root().top();
}

void stack::push(const int x)
{
	if (root().empty())
	{
		root().push(std::make_pair(x, x));
		return;
	}

	auto max = peek().second;
	if (max > x)
	{
		root().push(std::make_pair(x, max));
	}
	else
	{
		root().push(std::make_pair(x, x));
	}
}

int stack::pop()
{
	int t = root().top().first;
	root().pop();
	return t;
}

int stack::max()
{
	return peek().second;
}
}
