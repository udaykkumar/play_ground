class Solution {
public:
    int isPrefixOfWord(string sentence, string sw) {
        
        std::istringstream iss( sentence );
        int index = 0;
        for ( std::string s; std::getline(iss, s, ' '); index ++ ) 
        {
            if( s.compare(0, sw.size(), sw) == 0 )
                return index+1;
        }
        return -1;
    }
};