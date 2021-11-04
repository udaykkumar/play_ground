#pragma once

namespace ds
{

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///
	///
	///	THERE IS SOME BUG -
	/// 	Valgrind may be a good option 
	///
	/// terminate called after throwing an instance of 'std::out_of_range'
	///  what():  vector::_M_range_check: __n (which is 18446744073709551610) >= this->size() (which is 10)
	///
	///
	///
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
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
	
		/// everytime create a vector of 10 queues representing
		/// for each index from 0 - 9
		/// Count also be a one for a-z or A-Z or whatever it is
		std::vector< std::queue<int> * > digarr( 10 , new std::queue<int>() );
			
		/// Iterate though the width of largest element
		for ( int r = 1; (largest / r) > 0 ; r *= 10 )
		{
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
