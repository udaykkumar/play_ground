#include "btree.hxx"
#include <iostream>

void test_put_1()
{
    ds::BTree t;
    t.put(1, 1);
}

void test_put_1_twice()
{
    ds::BTree t;
    t.put(1, 1);
    t.put(1, 1);
}


int main(int argc, const char* argv[])
{
    test_put_1();
    test_put_1_twice();
    return 0;
}
