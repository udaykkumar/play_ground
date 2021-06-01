#include <iostream>

int add(int a, int b)
{
	return a + b;
}

/*
 * This below definition is illegal
 * because the declaration of function is ambiguous
 * functions are essentially evaluated based on return type
 */

// Thus this won't compile unless we do #if 0 ... #endif
#if 0
double add( int a, int b )
{
    return a+b;
}
#endif

int main()
{
	return (0);
}
