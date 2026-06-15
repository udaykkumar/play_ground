/* example: one class, two objects */
#include <iostream>

using namespace std;
class Rect {
    int x, y;

public:
    void set(int, int);
    int area()
    {
        return (x * y);
    }
};

void Rect::set(int a, int b)
{
    x = a;
    y = b;
}

int main()
{
    Rect rect, rectb;
    rect.set(3, 4);
    rectb.set(5, 6);
    cout << "rect area: " << rect.area() << endl;
    cout << "rectb area: " << rectb.area() << endl;
    return 0;
}
