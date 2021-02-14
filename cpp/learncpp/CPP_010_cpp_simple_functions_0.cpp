/*
 * https://www.learncpp.com/cpp-tutorial/71-function-parameters-and-arguments/
 */

#include <iostream>

void simple_function(  )
{
    std::cout << "Hello Function" << std::endl;
}

int main()
{
    std::cout << "Calling Function simple_function from main()" << std::endl;
    simple_function();
    return (0);
}
