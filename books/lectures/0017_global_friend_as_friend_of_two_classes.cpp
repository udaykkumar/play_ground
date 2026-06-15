// Example to make global friend function as friend of two class

#include <iostream>
using namespace std;
class depart; // Forward declaration
class arriv {
    int train_no;
    float time;
    bool status;

public:
    arriv(int n, float t, bool s = 1)
    {
        train_no = n;
        time = t;
        status = s;
    }

    friend void screen(arriv&, depart&);
};

class depart {
    int train_no;
    float time;
    bool status;

public:
    depart(int n, float t, bool s = 0)
    {
        train_no = n;
        time = t;
        status = s;
    }
    friend void screen(arriv&, depart&);
};

void screen(arriv& a, depart& b)
{
    if (a.status)
        cout << a.train_no << " " << a.time << endl;
    else
      cout << b.train_no << " " << b.time << endl;
}
int main()
{
    arriv ex(6789, 4.42, 1);
    depart fa(1002, 6.23, 0);
    screen(ex, fa);
}
