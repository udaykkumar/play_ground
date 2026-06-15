class Solution {

    bool is_vowel( char c )
    {
        return (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u');
    }
    
public:
    int maxVowels(string s, int k) {
        if (s.length() < k)
            return 0;
        
        int vowels = 0;
        for ( int i = 0 ; i < k; i++ )
            if( is_vowel(s[i]) )
                vowels++;
       
        if ( s.size() == k )
            return vowels;
        
        int max_vowels = vowels;
        for ( int i = k ; i < s.size() ;++i  )
        {
            if ( is_vowel( s[i-k]) )
                vowels --;
            if ( is_vowel(s[i]) ) 
                vowels ++;
            
            if (max_vowels < vowels ) 
                max_vowels = vowels;
        }
        
        return max_vowels;
    }
};