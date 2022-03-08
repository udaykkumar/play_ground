class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        std::vector<int> r;
        for( auto x : A )
            r.push_back( x*x );
        std::sort( r.begin(), r.end() );
        return r;
    }
};