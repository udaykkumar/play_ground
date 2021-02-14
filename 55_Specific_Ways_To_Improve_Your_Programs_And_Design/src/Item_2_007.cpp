#include <iostream>

void f( int x )
{
	(void)x;
	return ;
}


/**
 * Check how the undesired behavior kicks in with the two different calls
 * 	CALL_WITH_MAX(++a, b);		<- a incremented twice
 * 	CALL_WITH_MAX(++a, b+10);	<- a incremented once
 *
 * bad bug ..
 * 
 */

#define CALL_WITH_MAX(a, b) 	f( (a) > (b) ? (a) : (b))
void Try_With_Macro()
{
	int a = 5, b = 0;
	std::cout << "Before CALL_WITH_MAX a = " << a << " b = " << b << "\n";

	CALL_WITH_MAX(++a, b);
	std::cout << "After Call 1 CALL_WITH_MAX a = " << a << " b = " << b << "\n";

	CALL_WITH_MAX(++a, b+10);
	std::cout << "After Call 2 CALL_WITH_MAX a = " << a << " b = " << b << "\n";

	
}

/**
 * This is a better alternative the Macro above
 *
 * inline has no performce overhead also 
 * becuase its a real function it obeys all the scope related rules
 * 
 */
template < typename T >
inline void CallWithMax( const T& a, const T& b )
{
	f( a > b ? a : b );
}


void Try_With_Inline()
{
	int a = 5, b = 0;
	std::cout << "Before CallWithMax a = " << a << " b = " << b << "\n";

	CallWithMax(++a, b);
	std::cout << "After Call 1 CallWithMax a = " << a << " b = " << b << "\n";
	CallWithMax(++a, b+10);
	std::cout << "After Call 2 CallWithMax a = " << a << " b = " << b << "\n";

}

int main(int argc, char const *argv[])
{
	std::cout << "Try_With_Macro() \n";
	Try_With_Macro();

	std::cout << "Try_With_Inline() \n";
	Try_With_Inline();
	return 0;
}