#include <iostream>
using namespace std;
class test1;

class test {
    int i;

public:
    test()
    {
        i = 10;
    }
    void display(test1&);
};

class test1 {
    int j;

public:
    test1()
    {
        j = 20;
    }
    friend void test::display(test1&); // member fun of class test is
};

void test::display(test1& t)
{
    cout << t.j << "\t" << i << endl;
}

int main()
{
    test t;
    test1 t1;
    t.display(t1);
}
