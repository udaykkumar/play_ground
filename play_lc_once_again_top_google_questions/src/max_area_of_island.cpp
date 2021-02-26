#include <max_area_of_island.hpp>

namespace lc
{
	int row = 0;
	int col = 0;

	bool not_in_limits( int i, int j )
	{
		return ( i < 0 || i >= row || j < 0 || j >= col );
	}

	int dfs( std::vector< std::vector< int > > g, int i, int j)
	{
		if(not_in_limits(i,j) or g[i][j] == 0 )
		{
			std::cout << "Skip this [" << i << "," << j << "] => " ;
			std::cout << ( not_in_limits(i,j) ? "Unknown" : g[i][j] ) << "\n";
			return 0;
		}

		g[i][j] = 0; // Key here is this one 

		return 1 + dfs(g, i-1, j) + dfs(g, i+1, j) + dfs(g, i, j-1) + dfs( g, i, j+1 );
	}
	
	int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
	{
		row = grid.size();
		col = grid[0].size();
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

