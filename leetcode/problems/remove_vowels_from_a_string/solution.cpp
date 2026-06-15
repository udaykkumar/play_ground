class Solution {
    
    
    inline bool vowel( char c )
    {
        return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
public:
    string removeVowels(string S) {
        string s;
            for (auto c : S)
                if (not vowel(c))
                    s += c;
        return s;
    }
};