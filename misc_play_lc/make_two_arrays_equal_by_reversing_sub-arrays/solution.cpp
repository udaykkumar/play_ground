class Solution {
public:
    bool canBeEqual(vector<int>& t, vector<int>& a) {
        std::sort( t.begin(), t.end() );
        std::sort( a.begin(), a.end() );
        for( int i = 0 ; i < t.size() ; i ++ )
        {
            if( t[i] != a[i] )
                return false;
        }
        return true;
    }
};