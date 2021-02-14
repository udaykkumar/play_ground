#include <Chapter_3_selection_sort.h>

int cphb::selection_sort_v1( std::vector<int> &v )
{
	int inversions = 0;
	for ( int i = 0 ; i < v.size() ; i ++ )
	{
		int minIdx = i;
		for ( int j = i+1; j < v.size(); j ++ )
		{
			if ( v[j] < v[minIdx] )
				minIdx = j;
		}

		std::swap( v[i], v[minIdx] );
		inversions ++;
	}
	return inversions;
}

