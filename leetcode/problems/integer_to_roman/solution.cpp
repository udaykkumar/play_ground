class Solution {
    std::vector< std::pair<int, char *> > romanNumerals= { 
                                               {1000, "M"}, {900, "CM"}, 
                                               { 500, "D"}, {400, "CD"},  
                                               { 100, "C"}, { 90, "XC"},  
                                               {  50, "L"}, { 40, "XL"},  
                                               {  10, "X"}, {  9, "IX"},   
                                               {   5, "V"}, {  4, "IV"},   
                                               {   1, "I"}   
                                            };
                                               
                                                
public:
    string intToRoman(int num) {
        std::string res;
        for( auto it = romanNumerals.begin(); (num != 0) && (it != romanNumerals.end()); ) {
            if( num >= it->first ) {
                num -= it->first;
                res += it->second;
            } else {
                ++it;
            }
        }
        return res;
    }
};