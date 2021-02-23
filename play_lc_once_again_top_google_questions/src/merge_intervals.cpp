#include <merge_intervals.hpp>

namespace lc
{
	std::vector< std::vector<int> > merge( std::vector< std::vector<int>>& intervals)
	{
		std::vector< std::vector<int> > res;
		int window[256] = {-1, };
		for ( int i = 0 ; i < 256; ++i )
			window[i] = -1;

		for ( auto interval : intervals )
		{
			int start = interval[0];
			int end   = interval[1];

			for ( ; start <= end ; ++start )
				window[start] = 1; 
		}

		int start = -1;
		int end   = -1;
		for ( int i = 0; i < 256 ; ++i )
		{
			auto v = window[i];
			if ( v == 1 and start == -1 )
			{
				start = i;
			}
			else if ( v == -1 and start > -1 )
			{
				end = i-1;
				std::cout << start << " " << end << "\n";
				res.push_back({start,end});
				start = -1;
				end   = -1;
			}
		}
		return res;
	}
}

