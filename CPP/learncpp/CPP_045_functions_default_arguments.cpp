#include <iostream>

int defaultArgument(int x, int y = 10 )
{
    return x + y;
}

int main()
{
    std::cout << "default argument call with single argument " << std::endl;
    std::cout << "defaultArgument(5) : " << defaultArgument(5) << std::endl;

    std::cout << "default argument call with all arguments " << std::endl;
    std::cout << "defaultArgument(5,6) : " << defaultArgument(5,6) << std::endl;

    return (0);
}
