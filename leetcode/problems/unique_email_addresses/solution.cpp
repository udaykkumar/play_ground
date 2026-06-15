class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        std::set<std::string> u;
        for( auto email : emails ) {
            auto name  = email.substr(0, email.find("@"));
            auto domain = email.substr(name.size()+1, email.size() - name.size());
            std::string n;
            for ( auto c : name )
            {
                if ( c == '.' )
                    continue;
                if ( c == '+' )
                    break;
                n += c;
            }
            
            auto k = "N "+ n + " D "+ domain;
            u.insert(k);
        }
        
        return u.size();
            
    }
};