#include <iostream>

int gcd( int x, int y )
{
	if ( x < y )
		return gcd(y,x);

	if ( x == y )
		return x;

	if ( x%y == 0 )
		return y;

	return gcd(x%y , y);
}



int generate_random_number(int min, int max)
{
    /// static used for efficiency,
    /// so we only calculate this value once
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    /// evenly distribute the random number
    /// across our range
    return min + static_cast<int>(
        (max - min + 1) * (std::rand() * fraction));
}


int main(int argc, char const *argv[])
{
	int min = 1, max = 10;
	
	std::cout << " x \t y \t \n"; 
	for (int i = 0; i < 100; ++i)
	{
		int x = generate_random_number(min, max);
		int y = generate_random_number(min, max);
	
		std::cout << x << "\t" << y << "\t" << gcd(x, y) << std::endl; 
	}
	return 0;
}