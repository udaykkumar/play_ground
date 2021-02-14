#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace math {
    struct hugeNos {
        std::vector<int> no_;
        int nSize_;

        hugeNos(){ nSize_ = 0; }

        hugeNos(int x){ 
            for( ; x > 0; x /= 10 ) { no_.push_back( x%10 ); }
            nSize_ = no_.size();
        }

        hugeNos( const hugeNos &x ) {
            for( auto e: x.no_ ) { no_.push_back(e); }
            nSize_ = x.nSize_;
        }

        hugeNos operator+( hugeNos x ){
            hugeNos s = hugeNos();

            std::vector<int> &a = x.no_;
            std::vector<int> &b = no_  ;

            size_t i = 0, sum = 0, carry = 0;
            size_t minSize = ( a.size() < b.size() ) ? a.size() : b.size();

            /* Keep Calculating the sum of individual digits untill one of them exhausts */
            for( ; i < minSize; i ++ ) {
                sum    = a[i] + b[i] + carry;
                carry  = sum / 10;
                sum    = sum % 10;
                s.no_.push_back(sum);
            }

            /* b Exhausted */
            for( ; i < a.size(); i ++ ) {
                sum = a[i] + carry;
                carry  = sum / 10;
                sum    = sum % 10;
                s.no_.push_back(sum);
            }

            /* a Exhausted */
            for( ; i < b.size(); i ++ ) {
                sum = b[i] + carry;
                carry  = sum / 10;
                sum    = sum % 10;
                s.no_.push_back(sum);
            }

            /* Never Ever forget carry */
            if( carry > 0 )
                s.no_.push_back(carry);

            return s;
        }
    };
};



std::ostream& operator<<( std::ostream &os, const std::vector<int> &v ) {
    for( auto ve : v ) { os << ve; }
    return os;
}

std::ostream& operator<<( std::ostream &os, const math::hugeNos &n ) {
    std::vector<int> x = n.no_;
    std::reverse( x.begin(), x.end() );
    os << x;
    return os;
}



int main( ) {

    math::hugeNos n1(1);
    math::hugeNos n2(1);
    int i = 0;
    while( i++ < 1000 ) {
        math::hugeNos n3 = n1 + n2;
                      std::cout << i << "   " << n3 << " " << std::endl;;
                      n1 = n2;
                      n2 = n3;
    }

    return 0;
}
