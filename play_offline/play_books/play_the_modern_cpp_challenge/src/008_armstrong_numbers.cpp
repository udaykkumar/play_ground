#include <iostream>

#define CUBE(x) (x*x*x)

bool is_armstrong_number( uint32_t n )
{
	uint32_t s = 0;
	for ( uint32_t n1{n} ; n1 > 0 ; n1 /= 10 )
	{
		auto r{n1%10};
			s += CUBE(r);
	}

	return (s == n);
}

int main(int argc, char const *argv[])
{
	for( uint32_t min{100}, max(1000); min < max  ; ++min ) {
		//std::cout << min << std::endl;
		if ( is_armstrong_number(min) ) {
			std::cout << min << std::endl;
		}
	}
	return 0;
}