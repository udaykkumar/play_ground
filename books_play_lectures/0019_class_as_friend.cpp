
#include <iostream>
using namespace std;
#include <iostream>

class one; // forward Declaration
class two {
    int c;

public:
    two()
    {
        c = 20;
    }
    void show(one&);
    void add(one&);
    friend class one;
};

class one {
    int x;

public:
    int disp()
    {
        cout << "value of X in class one :" << x << endl;
        return 0;
    }
    friend class two;
    int set_val()
    {
        x = 10;
        return 0;
    }
};

void two::show(one& o2)
{
    cout << "value of X in through show fun in two :" << o2.x << "\t"
         << " c = " << c << endl;
    o2.disp();
}

void two::add(one& o1)
{
    o1.x = c;
}

int main()
{
    one o1;
    o1.set_val();
    two t1;
    t1.add(o1);
    t1.show(o1);
    return 0;
}
