#include <iostream>
using namespace std;

// Declaration of the function to be made as friend for
int AddToFriend(int x);

class abc {
    int private_data;
    friend int AddToFriend(int x);

public:
    abc()
    {
        private_data = 5;
    }
};

int AddToFriend(int x)
{
    abc var1;
    return var1.private_data + x;
}

int main()
{
    cout << "Added Result for this C++ tutorial: " << AddToFriend(4) << endl;
    return 0;
}
