#ifndef __SUDOKU_HPP_INCLUDED__
#define __SUDOKU_HPP_INCLUDED__
#include <iostream>
#include <curses.h>
#include <unistd.h>

#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>


namespace ml{

	struct sudoku {

		typedef boost::numeric::ublas::matrix<size_t> board_t;
		board_t board;
		size_t moves;


	public:
		sudoku( const std::vector<size_t>& problem ): board(9,9), moves(0)
		{
			auto it = problem.begin();
			for( unsigned int i = 0; i < board.size1() ; ++ i )
				for( unsigned int j = 0; j < board.size2() && it != problem.end() ; ++ j , ++it ) 
					board(i,j) = *it;
		}


		sudoku( ):board(9,9), moves(0)
		{
			for( unsigned int i = 0; i < board.size1() ; ++ i )
				for( unsigned int j = 0; j < board.size2() ; ++ j ) 
					board(i,j) = 0;
		}

		~sudoku()
		{
			usleep(1000000);
		}
		
		bool solve();
		

	private:

		bool 						is_safe_put(const size_t n, const size_t row, const size_t col ) const;
		std::pair<size_t, size_t> 	empty_cell();
		void 						show();
		bool 						if_row(const size_t n, const size_t row) const;
		bool 						if_col(const size_t n, const size_t col) const;
		bool 						if_box(const size_t n, const size_t row, const size_t col) const;
	};
}
#endif