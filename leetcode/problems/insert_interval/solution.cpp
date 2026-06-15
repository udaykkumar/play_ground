class Solution {
    std::vector < std::vector<int>> merge( std::vector< std::vector<int> >& intervals) {
        
        const size_t start = 0;
        const size_t end   = 1;

        std::vector < std::vector<int>> res;
            if ( int(intervals.size()) == 0 ) {
                return res;
            }
            
            std::sort ( intervals.begin(), intervals.end(), []( const std::vector<int> &x, const std::vector<int> &y ) {
                return x[0] < y[0];
            });


            res.emplace_back( intervals[0] );

            for ( int i = 1 ; i < int(intervals.size()) ; ++i ) {
                if ( intervals[i][start] <= res[res.size()-1][end] ) {
                    res[ res.size() - 1 ][end] = std::max ( intervals[i][end], res[res.size()-1][end]);
                } else {
                    res.emplace_back(intervals[i]);
                }
            }
        return res;
    }

public:
    std::vector< std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
        return merge(intervals);
    }

};