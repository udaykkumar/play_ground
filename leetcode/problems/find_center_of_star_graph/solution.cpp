class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::unordered_map< int, int > nodeCount;
        int mc = 0;
        for ( auto e : edges ) {
            for ( auto n  : e ) {
                auto kvp = nodeCount.find(n);
                if ( kvp == nodeCount.end())
                    nodeCount.insert( std::pair(n,1) );
                else
                    nodeCount[n] += 1; 
                if ( nodeCount[n] > mc )
                    mc = n;
            }
        }
        
        return mc;
    }
};