// Examples for default as well as parameterised constructor.

#include <iostream>
using namespace std;
class sample {
    int a, b;

public:
    sample() // Default constructor
    {
    }

    sample(int i, int j) // Parameterised constructor
    {
        a = i;
        b = j;
    }

    void display()
    {
        cout << a << " \t " << b << endl;
    }
};

int main()
{
    sample o1; // it calis the default constructor
    o1.display();

    sample o2(10, 30); // it calls the parameterized constructor
    o2.display();

    return 0;
}
