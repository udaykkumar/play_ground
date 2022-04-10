#include "btree.hxx"
#include <iostream>

void test_put_1()
{
    ENTRY;
    ds::BTree t;
    t.put(1, 1);
    EXIT;
}

void test_put_1_twice()
{
    ENTRY;
    ds::BTree t;
    t.put(1, 1);
    t.put(1, 1);
    EXIT;
}

void test_put_2_keys()
{
    ENTRY;
    ds::BTree t;
    t.put(1, 1);
    t.put(2, 2);
    EXIT;
}

void test_put_10_keys()
{
    ENTRY;
    ds::BTree t;
    t.put(1, 1);
    t.put(2, 2);
    t.put(3, 2);
    t.put(4, 2);
    EXIT;
}

int main(int argc, const char* argv[])
{
#if 1
    test_put_1();
    test_put_1_twice();
    test_put_2_keys();
#endif
    test_put_10_keys();
    return 0;
}
