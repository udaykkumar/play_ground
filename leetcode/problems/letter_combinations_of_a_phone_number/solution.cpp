class Solution {
    
    std::unordered_map<char, string > map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}    
        };
    
    void recurse(string digits,
                int i,
                string r,
                std::vector<string> &rvector)
    {
       if ( i == digits.size() )
       {
           rvector.push_back(r);
           return;
       }
        
      string mapVal = map[ digits[i] ];
      for ( size_t idx = 0 ; idx < mapVal.length() ; ++idx )   
          recurse ( digits, i+1,  r + mapVal[idx], rvector );
   }
    
public:
    vector<string> letterCombinations(string digits) {
        if ( digits.size() == 0 )
            return {};
        std::vector<string> r;
        recurse(digits, 0, "", r );
        return r;
    }
};