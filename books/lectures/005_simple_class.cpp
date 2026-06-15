
#include <iostream>

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
    Rect rect;
    rect.set(3, 4);
    std::cout << "area: " << rect.area();
    return 0;
}
