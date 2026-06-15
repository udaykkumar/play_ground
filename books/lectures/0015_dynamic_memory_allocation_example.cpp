// Examples for Dynamic memory allocation

#include <iostream>
using namespace std;
int main()
{

    int i;
    int* p;

    //cout << "How many numbers would you like to type? ";

    // cin >> i;
    i = 5;
    p = new (nothrow) int[i];
    if (p == 0)
        cout << "Error: memory could not be allocated";
    else {
        for (int n = 0; n < i; n++) {
            //cout << "Enter number: ";
            //cin >> p[n];
            p[n] = n + 1;
        }
        cout << "You have entered: ";
        for (int n = 0; n < i; n ++)
            cout << p[n] << ",";
        delete[] p;
    }

    return 0;
}
