class Solution {
public:
    int minPartitions(string n) {
       int max = 0;
        for ( auto i : n )
            max = std::max( max, i-'0');
        return max;
    }
};