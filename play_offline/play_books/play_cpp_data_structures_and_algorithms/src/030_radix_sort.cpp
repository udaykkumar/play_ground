#include <iostream>
#include <queue>
#include <memory>
#include "utils.hpp"

namespace ds
{

	void radix_sort( int array[], int size)
	{
		/// if zero size array nothing to do
		if ( size == 0 )
			return;

		/// Get the largest element in the array
		int largest = array[0];
		{
			for ( int i = 0 ; i < size ; ++i )
				largest = std::max( largest, array[i] );
		}
	

		/// Iterate though the width of largest element
		for ( int r = 1; (largest / r) > 0 ; r *= 10 )
		{

			/// everytime create a vector of 10 queues representing
			/// for each index from 0 - 9
			/// Count also be a one for a-z or A-Z or whatever it is

			std::vector< std::shared_ptr< std::queue<int> >  > digarr( 10 , std::make_shared< std::queue<int> >() );
			
			/// construct the Queues based on the index
			for ( int i = 0 ; i < size ; ++i )
				digarr.at(  ( array[i] / r ) % 10  )->emplace( array[i] );
				
			///	re-construct the array based on Queue
			{
				int index = 0;
				for ( auto q : digarr ) {
					for ( ; not q->empty() ; q->pop() ) {
						array[ index ++ ] = q->front();
					}
				}
			}

			/// repeat till we process the largest element width times
		}
	}
}

int main(int argc, char const *argv[])
{
	std::cout << "radix_sort " << std::endl;
	std::function< void(int [], int ) > f = ds::radix_sort;
	
	utils::just_a_simple_sort(f);
	utils::just_a_simple_sort_multiple(f);
	utils::huge_sort_ascending(f, 1000000);
	utils::huge_sort_descending(f,1000000);
	return 0;
}