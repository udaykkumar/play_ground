class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        int last_char = s.size()-1;
        while( last_char >= 0 && s.at(last_char) == ' ' )
            -- last_char;

        for ( int res = last_char; 
                  res >= 0 and s.at(res) != ' '; 
                  res --, size ++  );
        return size;
    }
};