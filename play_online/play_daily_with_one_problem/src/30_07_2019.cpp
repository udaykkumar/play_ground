/*
Hi, here's your problem today. This problem was recently asked by Amazon:

You are given a 2D array of characters, and a target string. Return whether or
not the word target word exists in the matrix. Unlike a standard word search,
the word must be either going left-to-right, or top-to-bottom in the matrix.

Example:


[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]


Given this matrix, and the target word FOAM, you should return true, as it can
be found going up-to-down in the first column.

Here's the function signature:


def word_search(matrix, word):
  # Fill this in.

matrix = [
  ['F', 'A', 'C', 'I'],
  ['O', 'B', 'Q', 'P'],
  ['A', 'N', 'O', 'B'],
  ['M', 'A', 'S', 'S']]
print word_search(matrix, 'FOAM')
# True


*/
#include <30_07_2019.hpp>

namespace daily_interview
{
	bool word_search( char matrix[][1024], int M, int N, int i, int j, char *word, size_t word_len )
	{
		if( word_len == 0 || word == NULL )
			return true;
		
		if( i == M || j == N )
			return false;

		if( matrix[i+1][j] == *word )
		{
			return word_search( matrix, M, N, i+1, j, word+1, word_len-1);
		}
		else if( matrix[i][j+1] == *word )
		{
			return word_search( matrix, M, N, i, j+1, word+1, word_len-1);
		}
		
		return false;
	}

	bool word_search( char matrix[][1024], int M, int N, char *word, size_t word_len )
	{
		for( int i = 0; i < M; i ++ )
		{	
			for( int j = 0; j < N; j ++)
			{
				if( matrix[i][j] == *word )	
				{
					if( word_search( matrix, M, N, i, j, word+1, word_len-1) == true )
							return true;
				}
			}
		}	
		
		return false;
	}
}

