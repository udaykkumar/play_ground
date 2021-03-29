#include <max_area_of_island.hpp>

namespace lc
{
	int ROW = 0;
	int COL = 0;

	int dfs( std::vector< std::vector< int > > &g, int i, int j)
	{
		if( i < 0 or i >= ROW or j < 0 or j >= COL or g[i][j] == 0 )
			return 0;
		
		g[i][j] = 0; // Key here is this one 

		return 1 + dfs(g, i-1, j) + dfs(g, i+1, j) + dfs(g, i, j-1) + dfs( g, i, j+1 );
	}
	
	int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
	{
		ROW = grid.size();
		COL = grid[0].size();
		int ma = 0;
		for ( int i = 0 ; i < ROW ; ++i ) {
			for ( int j = 0 ; j < COL ; ++j ) {
				if ( grid[i][j] ) {
					ma = std::max( ma, dfs(grid, i, j));
				}
			}
		}
		return ma;
	}

	
}

