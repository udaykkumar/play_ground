class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        std::unordered_map< std::string, int > tMap = {
            std::pair< std::string, int >(  "type" , 0 ),
            std::pair< std::string, int >(  "color" , 1 ),
            std::pair< std::string, int >(  "name" , 2 )
        };
        
        int count = 0;
        for ( auto v : items )
        {
            if( v[ tMap[ruleKey] ] == ruleValue )
                count ++;
        }
        return count;
    }
};