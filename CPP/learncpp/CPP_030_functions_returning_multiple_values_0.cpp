#include <iostream>

struct foo
{
    int x_;
    int y_;
    int z_;
};

foo returnFoo()
{
    foo f;

        f.x_ = 1;
        f.y_ = 2;
        f.z_ = 3;

    return f;
}

int main()
{
    foo x = returnFoo();
    std::cout << "x.x_ = " << x.x_ << " x.y = " << x.y_ << " x.z = " << x.z_ << std::endl;
    return 0;
}
