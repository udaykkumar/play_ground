class Solution {
    
    int Closes( std::string s )
    {
        int i = 0;
        for ( auto c : s )
        {
            if ( c == ')' )
                i++;
        }
        return i;
    }
   
    int Opens( std::string s )
    {
        int i = 0;
        for ( auto c : s )
        {
            if ( c == '(' )
                i++;
        }
        return i;
    }
    
public:
    
    void
    recurse ( int n, std::vector< std::string > &res, std::string p )
    {
        int opens =  Opens( p );
        int closes= Closes( p );
        
        if ( closes > opens or opens > n or closes > n )
            return;
        
        if ( opens == n and closes == n )
            res.emplace_back(p);
        
        recurse( n, res, p + "(");
        recurse( n, res, p + ")");
    }
    
    
    vector<string> generateParenthesis(int n) { 
        std::vector<string> res;
        //if ( n == 1 )
        //    return td::vector<string>();
        std::string p("(");
        recurse( n, res, p );
        return res;
    }
};