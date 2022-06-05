#include <iostream>
using namespace std;
int main()
{
    char* ptr;
    ptr = new (nothrow) char[128];
    if (ptr == 0) {
        // error assigning memory. Take measures.
        return 0;
    }
    strcpy(ptr, "Something");
    cout << ptr;
    return 0;
}
