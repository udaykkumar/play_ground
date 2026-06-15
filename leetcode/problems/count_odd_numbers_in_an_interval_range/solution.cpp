class Solution {
public:
    int countOdds(int low, int high) {
        int odds = 0;
        for ( ; low <= high ; low ++)
            odds += ( low & 0x01 );
        
        return odds;
    }
};