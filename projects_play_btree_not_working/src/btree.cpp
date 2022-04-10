#include "btree.hxx"
#include <iostream>

void test_put_1()
{
    ENTRY;
    ds::BTree t;
    t.put(1, 1);
    t.show();
    EXIT;
}

void test_put_1_twice()
{
    ENTRY;
    ds::BTree t;
    t.put(1, 1);
    t.put(1, 1);
    t.show();
    EXIT;
}

void test_put_2_keys()
{
    ENTRY;
    ds::BTree t;
    t.put(1, 1);
    t.put(2, 2);
    t.show();
    EXIT;
}

void test_put_x_keys(int x)
{
    ENTRY;
    std::cout << "X  =  " << x << "\n";
    ds::BTree t;
    for (int i = 1; i <= x; ++i) {
        t.put(i, i);
        t.show();
    }
    t.show();
    EXIT;
}

int main(int argc, const char* argv[])
{
#if 0
    test_put_1();
    test_put_1_twice();
    test_put_2_keys();
#endif
    test_put_x_keys(10);

    return 0;
}
