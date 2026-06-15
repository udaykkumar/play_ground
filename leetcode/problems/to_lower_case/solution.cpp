class Solution {
public:
    string toLowerCase(string str) {
        string s;
            for ( auto c : str )
                s += std::tolower(c);
        return s;
    }
};