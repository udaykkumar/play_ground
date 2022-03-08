class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::map<int,int> m;
        for ( auto i : arr ) {
            m[i] += 1;
        }
        std::vector<int> v;
        std::set<int>    s;
        for ( auto p : m )
        {
            cout << p.second << " ";
            v.push_back(p.second);
            s.insert(p.second);
        }
        
        cout << v.size() << " " << s.size() ;
        return v.size() == s.size();
    }
};