class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        std::vector< int > res( A.size() );
        int i = 0 , j = A.size()-1;
        for( auto x : A )
        {
            if ( x%2 )
                res[j--] = x;
            else
                res[i++] = x;
        }
        
        return res;
    }
};