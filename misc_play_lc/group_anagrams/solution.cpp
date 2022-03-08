class Solution {
    
    std::unordered_map< std::string, std::vector< std::string> > anagramTracker_;

    bool exists( std::string &k ) {
        return anagramTracker_.find(k) != anagramTracker_.end();
    }

    void append( std::string &k, std::string &v) {
        anagramTracker_[k].emplace_back(v);
    }

    void add(std::string &k, std::string &v) {
        anagramTracker_[k] = std::vector<std::string>{v};
    }

    const std::unordered_map< std::string, std::vector< std::string> > &hash() {
        return anagramTracker_;
    }


public:
    std::vector< std::vector<std::string> > groupAnagrams(std::vector<std::string>& strs) {
        std::vector< std::vector<std::string> > res;
        for ( auto s : strs ) {
            auto ostring(s);
            std::sort( s.begin(), s.end() );
            if ( exists(s) ) {
                append(s, ostring);
            } else {
                add(s, ostring);
            }
        }

        for ( auto kvp : hash() ) {
            res.emplace_back(kvp.second);
        }
        return res;
    }
};