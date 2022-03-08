class Solution {
public:
    bool buddyStrings(string A, string B) {
        if ( A.length() != B.length() )
            return false;
        
        size_t unqiA = unordered_set<char>(A.begin(), A.end()).size();
        if (A == B && unqiA < B.length()) 
            return true;
        
        size_t n = A.length();
        std::vector< size_t > indeces;
        for ( size_t i = 0 ; (i < n) && (indeces.size() < 3) ; i ++ )
        {
            if ( A[i] != B[i] )
                indeces.push_back( i );
        }
        
       
        return ( indeces.size() == 2 &&
            A[ indeces[0] ] == B[ indeces[1] ] &&
             A[ indeces[1] ] == B[ indeces[0]] );
    }
};