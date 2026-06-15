class Solution {
public:
    double average(vector<int>& salary) {
        double s = 0;
        sort( salary.begin(), salary.end() );
        
        for( int i = 1; i < salary.size()-1 ; ++i )
            s += salary[i];
        
        return s/(salary.size()-2);
    }
};