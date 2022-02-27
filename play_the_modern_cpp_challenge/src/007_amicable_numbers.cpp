#include <iostream>
#include <vector>
#include <unordered_map>



uint32_t sum_proper_divisors( uint32_t n ) 
{
	uint32_t s = 1;
	for ( uint32_t d = 2 ; (d * d) <  n ; ++d ) 
	{
		if ( (n%d) == 0 ) 
		{	
			/// d divides n cleanly
			if ( d == (n/d) ) 
				s += d;
			else 
				s += d + n/d;
		}
	}

	return s;
}


int main(int argc, char const *argv[])
{
	constexpr uint32_t limit { 1000000 };
	
	/// Keep track of number of divisors with n
	std::unordered_map< uint32_t, uint32_t > amicable_map;

	
	for ( uint32_t  n{0} ; n < limit ; ++n ) {

		/// Get sum of proper divisors
		auto sprop_divisors { sum_proper_divisors(n) };
		//std::cout << n << " " << sprop_divisors << std::endl;
		/// update Map accordingly
		if ( sprop_divisors == 1 ) 
			continue;
		amicable_map.insert( std::make_pair(n, sprop_divisors) );
	}

	/// loop through the map ignoring single l.secondue lists
	for ( auto l : amicable_map ) {
		
		/// both l.first and l.secondue are part of the map
		if ( amicable_map.find(l.second) == amicable_map.end() ) 
			continue;

		/// they can't be equal
		if ( l.first == l.second )
			continue;

		/// Still not amicable
		if ( amicable_map.at(l.first) == l.second and amicable_map.at(l.second) == l.first ) 
		{
			/// If they are amicable, print and reset
			std::cout << l.first << " " << l.second << std::endl;
			
			/// avoid printing the reverse
			amicable_map[l.first]  = 1;
			amicable_map[l.second] = 1;
		}		
	}

	return 0;
}