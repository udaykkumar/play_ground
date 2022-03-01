

/**
 *

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

 **/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    int climbStairs(int n) {
    	/// This cant be the case but its okay to keep it
    	if ( n < 0 ) return 0;

    	/// if there are no stairs or atleast 1 stair
    	/// the minimum step is 1
    	if ( n == 0 or n == 1 ) return 1;
    	if ( n == 2 ) 			return 2;

    	/// the number steps need to reach n is
    	/// total number of steps needed to reach n-1 + 
    	/// total number of steps needed to reach n-2  ... weird ??
    	/// f(n) = f(n-1) + f(n-2) ... that sounds like a fibonacci

    	//return climbStairs(n-1) + climbStairs(n-2);


    	/// My First C/C++ Program may be
    	int f1 = 1, f2 = 2, f = 0;
    	for ( int i = 3 ; i <= n ; ++i ) {
    			f = f1+f2;
    			f1 = f2;
    			f2 = f;
    	}
    	return f;
	}
};


int main(int argc, char const *argv[]) {
    
    {
        Solution s;
       	std::cout << s.climbStairs(2) << std::endl;
    }

    {
        Solution s;
       	std::cout << s.climbStairs(3) << std::endl;
    }
    {
        Solution s;
       	std::cout << s.climbStairs(4) << std::endl;
    }

    {
        Solution s;
       	std::cout << s.climbStairs(25) << std::endl;
    }

    {
        Solution s;
       	std::cout << s.climbStairs(45) << std::endl;
    }
    
    return 0;
}