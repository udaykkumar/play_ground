class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int map[255] = {0,};
         for ( const auto c : S ) {
             map [ c ] += 1;
         }
        
        int stones = 0;
         for ( const auto c : J ) {
             stones += map[c];
         }   
      
        return stones;
    }
};