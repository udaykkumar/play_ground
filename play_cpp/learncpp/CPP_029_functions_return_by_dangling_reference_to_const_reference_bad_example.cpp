#include <iostream>

// const int& returnByReference()
// {
//     // The scope of this literal will go away as soon as the function ends
//     // and we are returning a reference of this
//     // hmmm, thats a a very bad thing to do
//     //
//     // Compiler shoud warn us -Wreturn-local-addr
//     return 5;
// }

int main()
{
	// This is really bad
	//
	//const int &ref = returnByReference();

	return 0;

}
