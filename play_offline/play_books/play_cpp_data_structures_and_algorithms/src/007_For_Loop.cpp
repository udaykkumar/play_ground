#include <iostream>
#include <cstdlib>
#include <ctime>



int GenerateRandomNumber(int min, int max)
{
    /// static used for efficiency,
    /// so we only calculate this value once
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);

    /// evenly distribute the random number
    /// across our range
    return min + static_cast<int>(
        (max - min + 1) * (std::rand() * fraction));
}

int main()
{
    /// set initial seed value to system clock
    std::srand(static_cast<unsigned int>(time(0)));

    /// loop ten times
    for (int i=0; i < 10; ++i)
    {
        std::cout << GenerateRandomNumber(0, 100) << " ";
    }
    std::cout << "\n";

    return 0;
}