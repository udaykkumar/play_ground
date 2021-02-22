#include <moving_average.hpp>

namespace lc
{
	moving_average::moving_average(int sz)
	{
		max_size_ = sz;
		sum_ = 0;
	}

	double moving_average::next(int v)
	{
		// There is no room
		if ( window().size() == max_size_ )
		{
			// remove the last one 
			sum_ -= window().back();

			// make room
			window().pop_back();
		}

		window().push_front(v);
		sum_  +=  v; // new element

		return window().size() ? (sum_ / window().size()) : 0;
	}
}

