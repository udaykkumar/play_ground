class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0U;
        for ( int i = 0  ; i < (sizeof(x) * 8) ; n >>= 1 ) {
        	x = ( x << 1 ) | (n & 0x01U);
            i++;
        }
        return x;
    }
};
