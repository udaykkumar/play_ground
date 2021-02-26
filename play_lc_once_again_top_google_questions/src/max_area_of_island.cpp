#include <max_area_of_island.hpp>

namespace lc
{
	int dfs( std::vector< std::vector< int > > g, int i, int j)
	{
		if( i < 0 or i > g.size() or j < 0 or j > g.size() )
			return 0;

		if( g[i][j] == 0 )
			return 0;

		return 1 + dfs(g, i-1, j) + dfs(g, i+1, j) + dfs(g, i, j-1) + dfs( g, i, j+1 );
	}
	
	int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
	{
		int ma = 0;
		for ( int i = 0 ; i < grid.size() ; ++i )
			for ( int j = 0 ; j < grid.size() ; ++j )
				ma = std::max( ma, dfs(grid, i, j))
		return s;
	}

	
}

