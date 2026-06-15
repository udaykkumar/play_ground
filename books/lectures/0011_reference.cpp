#include<iostream>

using namespace std;
void swap(int& i, int& j)
{

    int tmp = i;
    i = j;
    j = tmp;

    cout << "x=" << i << endl
         << "y =" << j;
}
int main()
{
    int x = 10, y = 20;
    swap(x, y);
    cout << "x=" << x << endl
         << "y =" << y;

    return 0;
}
