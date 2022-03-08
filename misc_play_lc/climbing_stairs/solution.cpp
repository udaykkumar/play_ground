
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
