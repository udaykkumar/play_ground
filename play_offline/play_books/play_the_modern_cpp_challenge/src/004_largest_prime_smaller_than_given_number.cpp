#include <iostream>


int is_prime(int x)
{
	/// Both 2 and 3 are primes
	if ( x <= 3 ) return x > 1 ;
	
	/// divide by 2 or 3 qualifies as non prime
	if ( x % 2 == 0 || x % 3 == 0  ) return false;

	/// this is a magical loop :-) 
	/// we can safely jump by 6 because of the above 
	/// conditions
	for (int i = 5; i * i < x; i += 6 )
	{
		if ( x % i == 0 || x % ( i + 2) == 0 )
		{
			return false;
		}
	}

	/// We are here means we have a Qualified prime
	return true;
}


int largest_prime(int x)
{
	for ( ; x > 2 ; --x )
	{
		if ( x%2 == 0 ) continue;
		if ( is_prime(x) ) return x;
	}

	return 2; // at the end this is going to be 2
}

int main(int argc, char const *argv[])
{
	int x;
	std::cin >> x;
	std::cout << "largest prime smaller than " << x << " is : "
				<< largest_prime(x) << std::endl;
	return 0;
}