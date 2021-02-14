#include <iostream>

namespace shifts {
	struct integers {
        int x_;
        int xSize_;
        integers(int x): x_(x){ 
            for( xSize_ = 0; x > 0 ; x /= 10) 
                xSize_ ++;
        };
        int operator<<( int i ) ;
        int operator>>( int i ) ;
    };
};

std::ostream& operator<<( std::ostream &os, const shifts::integers &i ) {
    os << i.x_ ;
    return os;
}


int shifts::integers::operator>>(int i) {
    while(i --> 0 ){ x_ /= 10; }
    return x_;
}

int shifts::integers::operator<<(int i) {
    int t = 1;
    while(i ++< xSize_ ){ t *= 10; }
    return x_%t;
}

int main() {
	shifts::integers i(12345);
    std::cout << i << " << 1 " << (i << 1) << std::endl;
    std::cout << i << " >> 1 " << (i >> 1) << std::endl;
    return 0;	
}
