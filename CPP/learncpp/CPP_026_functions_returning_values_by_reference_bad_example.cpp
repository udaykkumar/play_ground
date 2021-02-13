#include <iostream>
#include <array>

int& returnByReference(  int x )
{
    int a = x + 1;
    return a;
}

int main()
{

    std::cout << "Now because the above function returns a refernce to a local variable  Not the best of Ideas" << std::endl;
    // this may work but bad Idea
    //int x = returnByReference(5);
    //std::cout << x << std::endl;

    return 0;
}
