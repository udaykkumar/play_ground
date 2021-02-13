#include <iostream>

// Function pointer to a function
// that takes no parameters
// but returns int
//int (*fcnPtr)();


// Const function pointer
// int (* const fcnPtr)();


/* Both these functions below exhibit a similar behavior as
 * that of the pointer above */

int return5()
{
    return 5;
}

int return10()
{
    return 10;
}


int main()
{
    int (*fcnPtr)();

    fcnPtr = return5;
    std::cout << "Calling fcnPtr() explicit dereference" << ( *fcnPtr )() << std::endl;
    std::cout << "Calling fcnPtr() implicit dereference" << fcnPtr() << std::endl;

    fcnPtr = return10;
    std::cout << "Calling fcnPtr() explicit dereference" << (*fcnPtr)() << std::endl;
    std::cout << "Calling fcnPtr() implicit dereference" << fcnPtr() << std::endl;

    return (0);
}
