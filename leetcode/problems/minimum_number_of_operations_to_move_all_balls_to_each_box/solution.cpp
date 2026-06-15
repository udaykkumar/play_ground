class Solution {
public:
    vector<int> minOperations(string boxes) {
        std::vector< int > res(boxes.size(),0);
        
        for ( int i = 0 ; i < res.size(); ++ i )
        {
            for ( int j = 0 ; j < boxes.size() ; ++j )
            {
                if( i == j )
                    continue;
                if( boxes[j] == '1')
                    res[i] += std::abs(i-j);
            }
        }
        
        return res;
    }
    
};