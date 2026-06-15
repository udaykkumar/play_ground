class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int time = 0;
        for ( int i = 1; i < p.size() ; ++i )
        {
            time += std::max( std::abs(p[i-1][0] - p[i][0]),
                             std::abs(p[i-1][1] - p[i][1]));
        }
        return time;
    }
};