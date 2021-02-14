#include <queens.hpp>

namespace ml
{
	std::pair<size_t, size_t> queens::nextCell() const
	{
		for( size_t idx = 0; idx < 8; idx ++ ){
			for( size_t jdx = 0; jdx < 8; jdx ++ ){
				if( cboard(idx,jdx) == '.' ){
					return std::make_pair(idx, jdx);
				}
			}
		}

		throw new std::exception();
	}

	bool queens::if_okay(size_t row, size_t col) const
	{
		if( cboard(row, col) == QUEEN) {
			return false;
		}

		for( auto it : cboard.begin2() + col ) {
			if( it == QUEEN )
				return false;
		}

		for( size_t r(row), c(col); ; r--, c-- ){
			if( cboard(r,c) == QUEEN )
				return false;
			if( r == 0 || c == 0 )
				break;
		}

		for( size_t r(row), c(col); r < 8 && c < 8 ; r++, c++ ){
			if( cboard(r,c) == QUEEN )
				return false;
		}

		return true;
	}

	bool queens::solve(size_t q, size_t r, size_t c)
	{
		moves++;
		show();
		usleep(100000);

	
		for( r = 0; r < 8 ; r ++ )
		{
			for( c = 0; c < 8 ; c ++ )
			{
				if( if_okay( r, c ) )
				{
					cboard( r, c ) = QUEEN;
					if(solve(q, 0, 0 ))
						return true;

					cboard( r, c ) = 0;
				}	
			}
		}

		return true;
	}

	void queens::show()
	{
		// Lets now show Queens progress
		return;
		std::stringstream ss;
		ss <<"Board : "<< moves << "( " << r_ << " , " << c_ << " )" << "\n" ;
		for( size_t idx = 0; idx < 8 ; idx ++ ) {
			for( size_t jdx = 0; jdx < 8 ; jdx ++ ) {
				ss << " " << cboard(idx, jdx) << " ";
			}
			ss << "\n";
		}
		std::string string = ss.str();
		mvprintw(25, 25, string.c_str());
    	refresh();
	}
}