#include <sudoku.hpp>
#include <vector>


namespace ml{


	void sudoku::show()
	{
        // Lets not show this 
        return;
		std::stringstream ss;
		ss <<"Matrix : Moves ( "<< moves << " ) \n" ;
		for( size_t idx = 0; idx < 9 ; idx ++ ) {
			for( size_t jdx = 0; jdx < 9 ; jdx ++ ) {
				ss << " " << board(idx, jdx) << " ";
			}
			ss << "\n";
		}
		std::string string = ss.str();
		mvprintw(25, 25, string.c_str());
    	refresh();
    	
    }

    bool sudoku::if_row(const size_t n, const size_t row) const
    {
    	for( auto it : (board.begin1() + row) )
			if( it == n )
				return false;
		return true;
    }

    bool sudoku::if_col(const size_t n, const size_t col) const
    {
    	for( auto it : (board.begin2() + col) )
			if( it == n )
				return false;

		return true;
    }

    bool sudoku::if_box(const size_t n, const size_t row, const size_t col) const
    {
    	size_t br = row - row%3;
		size_t bc = col - col%3;
		for (size_t r = 0; r < 3; ++r )  
			for (size_t c = 0; c < 3; ++c )  
				if (board( r + br, c + bc)  == n )  
					return false;  			
		
     	return true;
    }

	bool sudoku::is_safe_put (const size_t n, const size_t row, const size_t col ) const
	{
		if( !if_row(n, row)  || 
			!if_col(n, col)  || 
			!if_box(n, row, col) )
			return false;
		return true;
	}

	std::pair<size_t, size_t> sudoku::empty_cell()
	{
		size_t i = 0, j = 0;
		for( i = 0; i < 9 ; i ++ )
			for( j = 0; j < 9; j ++ )
				if( board(i,j) == 0 )
					return std::make_pair(i,j);
				

		throw new std::exception() ;
	}

	
	bool sudoku::solve()
	{
		moves++;
		show();
		if( moves%100 == 0 )
		{
    		usleep(100000);
    	}

		try
		{
			std::pair<size_t, size_t> cell = empty_cell();
			for( size_t i = 1; i <= 9; i ++ )
			{
				if( is_safe_put( i, cell.first, cell.second ) )
				{
					board( cell.first, cell.second ) = i;

					if( solve() )
						return true;

					board( cell.first, cell.second ) = 0;
				}
			}
		}
		catch( ... )
		{
			/* Means we are done*/
			return true;
		}
		
		return false;
	}

}