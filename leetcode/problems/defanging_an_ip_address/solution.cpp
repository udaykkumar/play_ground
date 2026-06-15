class Solution {
public:
    string defangIPaddr(string address) {
        std::string r("");
            for( const auto &c : address ) {
                if ( c == '.' )
                {
                    r += "[.]";
                } 
                else
                {
                    r += c;
                }
            }
        return r;
    }
};