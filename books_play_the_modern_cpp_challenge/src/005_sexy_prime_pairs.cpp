#include <iostream>
#include <vector>

typedef std::pair < uint32_t, uint32_t > sexy_pair_t;
typedef std::vector < sexy_pair_t >      list_sexy_pair_t;

list_sexy_pair_t primes( uint32_t x )
{
	list_sexy_pair_t  sexypairs;
	{
		auto *seive = new bool[x+1];

		for ( uint32_t i{3}, prev{2}, cur{2}; 
				i < x ; ++i ) {

			if ( seive[i] ) continue;

			cur = i;
			if ( cur - prev == 6 ) 
				sexypairs.emplace_back( cur, prev ) ;
			prev = cur;
			
			for ( uint32_t j = i+i ; j < x ; j += i ) 
				seive[j] = true;
		}

		delete[] seive;
	}
	return sexypairs;
}


int main(int argc, char const *argv[])
{
	uint32_t limit{1025};
	for ( auto p : primes(limit) ) 
	{
		std::cout << "( " << p.first 
					<< ", " << p.second << " ), " ;
	}
	std::cout << std::endl;
	
	return 0;
}