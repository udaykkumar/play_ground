class Solution {
public:
    int minSteps(string s, string t) {
        std::unordered_map< char, int > smap;
            for ( auto c : s ) {
                smap[c] += 1;
            }
        
        std::unordered_map< char, int > tmap;
            for ( auto c : t ) {
                tmap[c] += 1;
            }
        
        int changes = 0;
        for ( char x = 'a' ; x <= 'z' ; x ++ ) {
            int sv = 0, tv = 0;
            if ( smap.find(x) != smap.end()) {
                sv = smap[x];
            }
            
            if ( tmap.find(x) != tmap.end() ) {
                tv = tmap[x];
            }
            
            //std::cout << "SV " << sv << " " << tv << " tv " << std::abs(sv-tv) << "\n";
            changes += std::abs(sv-tv);
        }   
        
        return changes;
    }
};