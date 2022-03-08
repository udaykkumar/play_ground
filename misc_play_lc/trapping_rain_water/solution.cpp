class Solution {
public:
    int trap(vector<int>& h) {
        if ( h.size() == 0 )
            return 0;
        int size = h.size();
        std::vector<int> rv(size,0);
            rv[ size-1] = h[size-1];
        for ( int i = size-2; i >= 0 ; --i )
            rv[i] = std::max( rv[i+1], h[i]);
        
        std::vector<int> lv(size,0);
            lv[0] = h[0];
        for ( int i = 1 ; i < size ; ++i )
            lv[i] = std::max( lv[i-1], h[i]);
        
        int total_trapped = 0;
        for ( int i = 1 ; i < size-1; ++i )
            total_trapped += std::min(lv[i], rv[i]) - h[i];
        
        return total_trapped;
    }
};