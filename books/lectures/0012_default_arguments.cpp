// Examples that illustrates Default arguments:
#include <iostream>
using namespace std;

void show(char = '*', int = 60);

int main()
{

    show('+', 40); // prints + 40 times
    show('+'); // prints '+' 60 times
    show(); // prints '*' 60 times

    return 0;
}

void show(char a, int b)
{
    for (int i = 0; i < b; ++i)
        cout << a;
    cout << endl ;
}
