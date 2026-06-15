#include <iostream>

// Forward Declaration
int normalFunction(int a, int b);
int defaultArgument(int a, int b = 10);

// This is Okay with Forward Declaration
int normalFunction(int a, int b)
{
	return a + b;
}

// This is a compilation error
#if 0
int defaultArgument( int a, int b = 10 )
#else
/* This is Okay again */
int defaultArgument(int a, int b)
#endif
{
	return a + b;
}

int main()
{
	std::cout << normalFunction(2, 3) << std::endl;
	std::cout << defaultArgument(2) << std::endl;
	return (0);
}
