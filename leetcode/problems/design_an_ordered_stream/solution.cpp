class OrderedStream {
    vector< string > res;
    int eos;
    
public:
    OrderedStream(int n) {
        res.resize(n+1);
        eos = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        res[idKey-1] = value;
       
        if ( res[eos].empty() )
            return {};
        vector<string> ret;
        while ( !res[eos].empty() and eos < res.size() )
            ret.push_back(res[eos++]);
        return ret;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */