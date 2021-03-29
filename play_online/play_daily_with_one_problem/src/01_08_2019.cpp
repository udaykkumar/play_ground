/*
Hi, here's your problem today. This problem was recently asked by Microsoft:

You 2 integers n and m representing an n by m grid, determine the number of ways you can get from the top-left to the bottom-right of the matrix y going only right or down.

Example:
n = 2, m = 2

This should return 2, since the only possible routes are:
Right, down
Down, right.

Here's the signature:

def num_ways(n, m):
  # Fill this in.

print num_ways(2, 2)
# 2

*/
#include <01_08_2019.hpp>

namespace daily_interview
{
    size_t num_ways( size_t **matrix, const size_t m, const size_t n, size_t r, size_t c )
    {
        if( r >= m || c >= n )
            return 0;

        if( r == m-1 && c == n-1 )
            return 1;

        return num_ways(matrix, m, n, r + 1, c) + num_ways(matrix, m, n, r, c + 1);
    }

    size_t num_ways(const size_t i, const size_t j)
    {
        size_t **matrix = new size_t*[i];
        for( size_t idx = 0; idx < i; idx ++ ) 
        {
            matrix[idx] = new size_t[j];
            for( size_t jdx = 0; jdx < j; jdx ++ ) {
                matrix[idx][jdx] = 0;
            }
        }

        int ways =  num_ways(matrix, i, j, (size_t)0, (size_t)0);

        for( size_t idx = 0; idx < i; idx ++ ) 
            delete matrix[idx];
        delete [] matrix;

        return ways;
    }

    size_t num_ways_better(const size_t i, const size_t j)
    {
        if( i == 1 || j == 1 )
            return 1;

        return num_ways_better(i-1, j) + num_ways_better(i, j-1);
    }

    size_t num_ways_even_better(const size_t i, const size_t j)
    {
        int c[i][j];

        for( size_t idx = 0 ; idx < i ; idx ++ )
            c[idx][0] = 1;

        for( size_t idx = 0 ; idx < i ; idx ++ )
            c[0][idx] = 1;

        for (size_t idx = 1; idx < i; idx ++) 
            for (size_t jdx = 1; jdx < j; jdx++) 
              c[idx][jdx] = c[idx - 1][jdx] + c[idx][jdx - 1];
        
        return c[i-1][j-1];
    }
}

