#include <merge_intervals.hpp>

namespace lc
{
	std::vector< std::vector<int> > merge( std::vector< std::vector<int> >& intervals)
	{
		if ( intervals.size() == 0 or  intervals.size() == 1 )
			return intervals;

		std::vector< std::vector<int> > res;
		int start = intervals[0][0];
		int end   = intervals[0][1];
		for ( int i = 1 ; i < intervals.size() ; ++i )
		{
			int s = intervals[i][0];
			if ( end < s )
			{
				res.push_back({start,end});
				start = s;
			}	
			end = intervals[i][1];
		}
		res.push_back({start,end});
		return res;
	}
}

