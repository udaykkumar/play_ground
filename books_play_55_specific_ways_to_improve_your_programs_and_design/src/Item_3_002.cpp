#include <iostream>
#include <vector>

/**
 * STL Iterators are based on pointers so an iterator is a lot like T* pointer
 * 
 * Declaring an iterator const is like declaring a pointer const, 
 * means iterator is not allowed to point to something else, but things it points to may be modified
 * ( const pointer, non-const data )
 *
 * If you want an iterator that points to something that can't be modified you want a const_iterator
 * 
 */

int main(int argc, char const *argv[])
{
	std::vector<int> vec
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	const std::vector<int>::iterator iter = vec.begin();
	*iter = 10; // This is Okay 

	//	++iter ; // wont work

	std::vector<int>::const_iterator citer = vec.begin();
	//*citer = 10; // Nope
	++citer; // Perfectly fine goes to next location
	return 0;
}
