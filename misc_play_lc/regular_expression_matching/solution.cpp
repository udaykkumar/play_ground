class Solution {
public:
    bool isMatch(string s, string p) {
        
        // Empty patten and empty string
        // Makes a valid match
        if ( p.empty() )
            return s.empty();
        
        //
        // Okay pattern is not empty 
        // 
        // if string is not empty and
        //
        // Match 
        //  first element for pattern with .. 
        //          first element of string or 
        //          with '.' <- matches a single character
        //              
        // 
        
        bool firstMatch = (not s.empty()) and
                          ((p[0] == s[0]) or (p[0] == '.'));
        
        
        // Now at this point we matched the first element
        // Now the first element matches
        
        //  if the pattern size is >= 2 and p[1] == '*'
        //      We can try matching the pattern for the string recursively
        //      by advancing the pattern 2 steps
        //      if that fails
        //      we advance the string by one and continue matching
        // Else
        //      advance both string and pattern and do things recursively
        //
        if ( p.size() >= 2 and p[1] == '*' )
            return (isMatch(s, p.substr(2, p.size()))) or
                    ( firstMatch and isMatch(s.substr(1, s.size()), p));
        else
            return firstMatch and isMatch(s.substr(1, s.size()), p.substr(1, p.size()));
        
    }
};