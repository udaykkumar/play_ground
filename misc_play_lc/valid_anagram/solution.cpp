class Solution {
public:
    bool isAnagram(string s, string t) {
        if ( s.size() != t.size() ) return false;
        if ( s.size() == 0 ) return true;

        std::unordered_map< int, int > vmap;
        for ( auto c : s ) {
        	vmap[c] ++;
        }

     	for ( auto c : t ) {
        	vmap[c] --;
        }
          
       for( auto kvp : vmap ) {
           if ( kvp.second > 0 )
               return false;
       }

        return true;
    }
};