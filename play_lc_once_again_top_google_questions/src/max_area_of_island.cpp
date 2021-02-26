#include <max_area_of_island.hpp>

namespace lc
{
	int row = 0;
	int col = 0;

	bool not_in_limits( int i, int j )
	{
		return ( i < 0 or i >= row or j < 0 or j >= col );
	}

	int dfs( std::vector< std::vector< int > > g, int i, int j)
	{
		if(not_in_limits(i,j))
			return 0;

		if( g[i][j] == 0 )
			return 0;

		return 1 + dfs(g, i-1, j) + dfs(g, i+1, j) + dfs(g, i, j-1) + dfs( g, i, j+1 );
	}
	
	int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
	{
		int row = grid.size();
		int col = grid[0].size();
		std::cout << " row " << row << " col " << col << "\n";
		int ma = 0;
		for ( int i = 0 ; i < grid.size() ; ++i ) {
			for ( int j = 0 ; j < grid.size() ; ++j ) {
				ma = std::max( ma, dfs(grid, i, j));
			}
		}
		return ma;
	}

	
}

