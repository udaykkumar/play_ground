#include <iostream>

/* This is Okay */
int defaultArgument(int x = 10, int y = 0, int z = 0)
{
	return x + y + x;
}

/* This is Not */
#if 0
int defaultArgument(int x = 10, int y, int z )
{
    return x + y + x;
}
#endif

int main()
{
	std::cout << defaultArgument() << std::endl;
	return (0);
}
