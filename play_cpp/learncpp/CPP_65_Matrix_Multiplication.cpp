#include <iostream>
#include <vector>

struct matrix
{
	int rows_;
	int cols_;
	std::vector< std::vector<int> > m;
	
	matrix( int r, int c ) :
		rows_(r),
		cols_(c)
	{
		for ( int i = 0 ; i < r ; i ++ )
		{
			m.emplace_back( std::vector<int>(c /* Size */, 0 /* Value*/ ));
		}
	}

	std::vector< std::vector<int> >& get()
	{
		return m;
	}

	int rows() { return rows_; } const
	int cols() { return cols_; } const


	matrix operator*(matrix &m1)
	{
		if ( not compatible_for_multiplication(m1) )
			throw std::runtime_error("Boom");

		int m = this->rows();
		int p = m1.cols();
		int n = this->cols();

		matrix prod( m, p );
		for ( int r = 0 ; r < m ; r ++ )
		{
			for ( int c = 0 ; c < p; c++ )
			{
				
				for ( int i = 0 ; i < n ; ++i ) 
				{
					prod.get()[r][c] += this->get()[r][n] * m1.get()[n][c];
				}
			}
		}


		std::cout << "This \n";
		this->show();
		std::cout << "m1\n";
		m1.show();
		return prod;
	}

	void show()
	{
		for ( int r = 0 ; r < rows_; ++r )
		{
			for ( int c = 0 ; c < cols_; ++c  )
				std::cout << m[r][c] << " ";
			std::cout << std::endl;
		}
	}

private:
	bool compatible_for_multiplication( matrix &m )
	{
		return this->rows() == m.cols();
	}
};


int main(int argc, char const *argv[])
{
	int Rows = 2, Cols = 2;
	
	matrix m1(Rows, Cols);
		for ( int r = 0, x = 0 ; r < Rows; ++r )
			for ( int c = 0 ; c < Cols; ++c )
				m1.get()[r][c] = x++;
	m1.show();

	matrix m2(Rows, Cols);
		for ( int r = 0, x = 0 ; r < Rows; ++r )
			for ( int c = 0 ; c < Cols; ++c )
				m2.get()[r][c] = x++;
	m2.show();
	
	matrix m = m1 * m2;
	m.show();
	return 0;
}