#ifndef __QUEENS_HPP_INCLUDED__
#define __QUEENS_HPP_INCLUDED__
#include <curses.h>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

namespace ml
{
	const char QUEEN = '0';
	struct queens
	{
		typedef boost::numeric::ublas::matrix<char> board_t;
		board_t cboard;
		size_t moves;
		size_t r_;
		size_t c_;
		
		queens() : cboard(8,8), moves(0), r_(0), c_(0) {
			for( size_t i = 0 ;i < 8; i ++ )
				for( size_t j = 0 ; j < 8; j ++ )
					cboard(i,j) = '.';
		}

		~queens() { usleep(1000000); getch(); }

		bool solve(size_t queen = 0, size_t r = 0, size_t c = 0);

	private:
		void show();
		std::pair<size_t, size_t> 	nextCell() const;
		bool 						if_okay(size_t row, size_t col) const;
	};
}
#endif