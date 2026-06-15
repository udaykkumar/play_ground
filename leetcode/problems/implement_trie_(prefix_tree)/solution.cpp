class Trie {
    
    static const int MaxKids = 26;
    
    struct Node {
        bool is_eow_;
        struct Node *kids_[MaxKids];
    };
    
    int ctoi( char c )
    {
        return c - 'a';
    }
    
    struct Node *trhead_;
public:
    Trie() : trhead_( new Node() ) {
        
    }
    
    void insert(string word) {
        auto crawl = trhead_;
        for ( auto c : word ) {
            int index = ctoi(c);
            if ( not crawl->kids_[index] ) {
                crawl->kids_[index] = new Node();
            }
            crawl = crawl->kids_[index];
        }
        crawl->is_eow_ = true;
    }
    
    bool search(string word) {
        auto crawl = trhead_;
        for ( auto c : word ) {
            int index = ctoi(c);
            if ( not crawl->kids_[index] ) 
                return false;
            crawl = crawl->kids_[index];
        }
        return crawl->is_eow_ ;
    }
    
    bool startsWith(string prefix) {
        auto crawl = trhead_;
        for ( auto c : prefix ) {
            int index = ctoi(c);
            if ( not crawl->kids_[index] ) 
                return false;
            crawl = crawl->kids_[index];
        }
        
        if ( crawl->is_eow_ ) {
            return true;  // its starts and ends .. so technically true
        }
        
        for( int i = 0; i < MaxKids; ++i ) {
            if( crawl->kids_[i] ) {
                return true; // there lies atleast one kid with valid startswith
            }
        }
        return false ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */