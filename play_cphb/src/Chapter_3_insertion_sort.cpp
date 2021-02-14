#include <Chapter_3_insertion_sort.h>

int cphb::insertion_sort_v1( std::vector<int> &v )
{
	int inversions = 0;
	for ( int i = 0 ; i < v.size()-1 ; i ++ )
	{
		for ( int j = i+1; j > 0; j -- )
		{
			if ( v[j] <= v[j-1] ) 
			{
				std::swap(v[j], v[j-1]);
				inversions++;
			}
		}
	}
	return inversions;
}

int cphb::insertion_sort_v2( std::vector<int> &v )
{
	int inversions = 0;
	for ( int i = 0 ; i < v.size()-1 ; i ++ )
	{
		for ( int j = i+1; j > 0; j -- )
		{
			if ( v[j] <= v[j-1] ) 
			{
				std::swap(v[j], v[j-1]);
				inversions++;
			}
			else
			{
				break;
			}
		}
	}
	return inversions;
}