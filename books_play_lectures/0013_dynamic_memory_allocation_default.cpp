#include <iostream>
using namespace std;
int main()
{
    char* ptr = new char[128];
    strcpy(ptr, "Something");
    cout << ptr;
    return 0;
}
