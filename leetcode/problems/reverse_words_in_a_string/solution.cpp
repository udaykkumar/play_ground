class Solution {
public:
    string reverseWords(string s) {
        
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
            return !std::isspace(ch);
            }));
        
       s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
            return !std::isspace(ch);
            }).base(), s.end());

        std::list < std::string > tokens;
        std::string token("");
        for ( auto c = s.begin(); c != s.end() ; )
        {
            if ( *c == ' ' )
            {
                for(  ; *c == ' ' ; c ++  ) ;
                tokens.push_front(token);
                token = "";
            }
            else
            {
                token += *c;
                c ++;
            }
        }
        
        
        if ( token.length() > 0 )
            tokens.push_front(token);
        
        token = "";
        while ( true && (tokens.size() > 0) )
        {
            token += tokens.front();
            tokens.pop_front();
            
            if( tokens.size() )
                token += " " ;
        }
            
        
        return token;
    }
};