#include <iostream>

inline unsigned long long nsum(unsigned int n)
{
	return n * ( n + 1) / 2;
}

inline unsigned long long nsum(unsigned int n, unsigned int limit)
{
	return n * nsum(limit/n);
}

int main(int argc, char const *argv[])
{
	unsigned int limit = 150;
	unsigned long long sum = nsum(5, limit) + nsum(3, limit) - nsum(15,limit);
	std::cout << "limit " << limit << " sum " << sum << std::endl; 
	return 0;
}