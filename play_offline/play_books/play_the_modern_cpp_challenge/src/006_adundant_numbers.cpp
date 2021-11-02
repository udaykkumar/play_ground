#include <iostream>

void print_abundancy_if( uint32_t n ) 
{
	uint32_t abundancy = 1;
	for ( uint32_t i = 2; (i * i) < n ; ++i ) {
		if ( n%i == 0 ) {
			if ( i == (n/i) ) 
				abundancy += i;
			else
				abundancy += (i + n/i);
		}
	}

	if ( abundancy > n ) {
		std::cout << n << " " << abundancy << std::endl;
	}
}


int main(int argc, char const *argv[])
{
	uint32_t limit {1234};
	for (uint32_t i{0}; i < limit; ++i)
		print_abundancy_if(i);
	return 0;
}