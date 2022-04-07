#include "btree.hxx"
#include <iostream>

int main(int argc, char const *argv[]) {
        ds::BTree t;
        for ( int i = 0 ; i < 10; ++i ) {
                t.put(i,i);
        }

        for ( int i = 0; i < 10; ++i ) {
                t.get(i);
        }
        return 0;
}
