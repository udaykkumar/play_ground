class Solution {
    
    std::string accumulate( vector<string> &s )
    {
        std::string x;
            for ( auto w : s )
                x += w;
        return x;
    }
    
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        auto s1 = accumulate(word1);
        auto s2 = accumulate(word2);
        return s1 == s2;
    }
};