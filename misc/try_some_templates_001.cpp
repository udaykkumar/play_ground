#include <iostream>


// A template helper used to select A or B based on a condition.
template<bool cond, typename A, typename B>
struct if_{
  typedef A type;
};

template<typename A, typename B>
struct if_<false, A, B> {
  typedef B type;
};


int main(int argc, char const *argv[])
{
	typedef typename if_< true, int, char >::type int_type;
	typedef typename if_< false, int, char >::type char_type;

	int_type i = 5;
	char_type c = 'a';


	 
	return 0;
}