#include "btree.hxx"
#include <iostream>

int main(int argc, const char *argv[])
{
    ds::BTree t;
    t.put(1, 1);
    t.put(2, 2);
    t.put(3, 3);
    t.get(1);
    return 0;
}
