#include <iostream>
#include <vector>

std::vector<uint32_t> prime_factors( uint32_t n ) 
{
	std::vector< uint32_t > res;
	{
		bool *seive = new bool[n];
		
		for ( uint32_t i{2}; i < n ; ++ i ) 
		{
			/// already visited and marked non prime
			if ( seive[i] ) continue;

			if ( (n % i) == 0 )
				res.emplace_back(i);
			
			seive[i] = true;

			for ( auto j{i+i} ; j < n ; j += i )
				seive[j] = true;	
		}
	}
	return res;
}

int main(int argc, char const *argv[])
{
	uint32_t n{1521123};
	for ( auto f : prime_factors(n) ) {
		std::cout << f << std::endl;
	}
	return 0;
}