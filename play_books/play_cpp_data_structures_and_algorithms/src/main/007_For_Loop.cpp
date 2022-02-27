#include <iostream>
#include <cstdlib>
#include <ctime>
#include "utils.hpp"



int main()
{
    /// loop ten times
    for (int i=0; i < 10; ++i)
         std::cout << utils::get_random_int(0, 100) << " ";
    std::cout << "\n";

    return 0;
}