#include <iostream>

int add(int x)
{
    return x + 10;
}

int add(int x, int y = 10)
{
    return x + y;
}

int main()
{
    /* This is Okay */
    std::cout << add(2,3) << std::endl;

    /* Trouble */
#if 0
    std::cout << add(2) << std::endl;
#endif
    return (0);
}
