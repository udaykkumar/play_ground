#include "btree.hxx"
#include <iostream>

int main(int argc, const char* argv[])
{

    ds::BTree t;
    t.put(1, 1);
    t.put(2, 2);
    t.put(3, 3);
    t.put(4, 4);
    t.put(5, 5);
    t.put(6, 6);
    t.put(7, 7);
    t.put(8, 8);
    t.get(1);
    return 0;
}
