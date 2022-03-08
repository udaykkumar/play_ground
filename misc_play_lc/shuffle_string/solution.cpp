class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string n(s);
        for ( size_t i = 0 ; i < indices.size(); i ++ ) {
            n[ indices[i] ] = s [ i ];
        }
        
        return n;
    }
};