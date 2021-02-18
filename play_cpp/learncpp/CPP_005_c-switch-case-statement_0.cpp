/*
 * https://practice.geeksforgeeks.org/problems/c-switch-case-statement/0
 */

#include <iostream>

int main(int ac, char **av)
{
    std::cout << "Skipping " << av[0] << "\n";
    return 0;
    int T;
    for( std::cin >> T; T > 0 ; T -- )
    {
        int x;
            std::cin >> x;
            switch( x )
            {
                case 1:
                    std::cout << "one";
                    break;
                case 2:
                    std::cout << "two";
                    break;
                case 3:
                    std::cout << "three";
                    break;
                case 4:
                    std::cout << "four";
                    break;
                case 5:
                    std::cout << "five";
                    break;
                case 6:
                    std::cout << "six";
                    break;
                case 7:
                    std::cout << "seven";
                    break;
                case 8:
                    std::cout << "eight";
                    break;
                case 9:
                    std::cout << "nine";
                    break;
                case 10:
                    std::cout << "ten";
                    break;
                default:
                    std::cout << "not in range";
                    break;
            }

            std::cout << std::endl;
    }

    return (0);
}
