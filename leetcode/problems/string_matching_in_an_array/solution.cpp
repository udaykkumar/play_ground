class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        auto cmp = [] (const std::string &s1, const std::string &s2) -> bool {
            return s2.size() > s1.size();  
        };
        std::sort( words.begin(), words.end(), cmp );

        //for( auto w : words ) { std::cout << w << "\n"; }
        
        std::vector<std::string> res;
        for( int i = 0 ; i < words.size(); ++i ) 
        {
            for( int j = i + 1 ; j < words.size() ; j ++ ) 
            {
                if( words.at(j).find(words.at(i)) != std::string::npos )
                {
                    res.push_back(words.at(i));
                    break;
                }
            }
        }
        return res;
    }
};