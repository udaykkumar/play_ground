class Solution {
public:
    int busyStudent(vector<int>& s, vector<int>& e, int q) {
        
        int notdoing = 0;
        for (auto it1 = s.begin(),it2 = e.begin();
                it1 != s.end() && it2 != e.end() ;
                ++ it1, ++it2 )
        {
            if ( q >= *it1 && q <= *it2 )
                notdoing++;
        }
    
        return notdoing;
    }
};