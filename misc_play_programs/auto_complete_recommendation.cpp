#include <iostream>
#include <memory>
#include <vector>

const size_t Max_AlphaBets{26};

/// for a dictionay recommendation
/// we probably need a trie so we create one
struct Trie {

    /// This is a typical trie node representation
    struct Node {
        std::vector< std::shared_ptr<struct Node> >  childs_;
        bool 						  				 is_EOW_;

        Node() : childs_( Max_AlphaBets ),
            is_EOW_( false ) {
          }

        bool isLastNode( ) const {
	    	for ( size_t i = 0 ; i < Max_AlphaBets; ++i ) {
	    		if ( childs_[i] ) return false;
	    	}
	    	return true;
	    }
    };



    Trie() : root_( std::make_shared<Node>() ) {
    }

    ~Trie() {
        /// We do not need to do much here
    }

    void insert(const std::string key) {
    	if ( root_ ) {
			auto crawl = root_;
    		for ( auto k : key ) {
    			int index = to_index(k);
    			if ( not crawl->childs_[index] )
    				crawl->childs_[index] = std::make_shared<Node>();
    			crawl = crawl->childs_[index];
    		}
    		crawl->is_EOW_ = true;
    	} else 
    		throw std::runtime_error("Trie not initialized");
    }


    void show_autocomplete_recommendations( std::string key ) {

    	auto crawl = root_;
    	for ( auto k : key ) {
    		int index = to_index(k);
    		if ( !crawl->childs_[index] )
    			return;
    		crawl = crawl->childs_[index];
    	}

    	/// This crawl is now at the end
    	if ( crawl->isLastNode() ) {
    		std::cout << key << "\n";
    		return;
    	}

    	/// fetch suggestions
    	fetch_suggestions( crawl, key );
    	return;

    }

  private:
    std::shared_ptr<struct Node> root_;

    int to_index( const char c ) const {
    	int index =  (int)c - (int)'a';
    	if ( index < 0 or index >= int(Max_AlphaBets) ) 
    		new std::runtime_error("Index oor");
    	return index;
    }

    
    void fetch_suggestions( std::shared_ptr<struct Node> &n, std::string s) {

    	if ( n->is_EOW_ ) {
    		std::cout << "\t\t" << s << "\n";
    	}

    	for ( size_t i = 0 ; i < Max_AlphaBets; ++i ) {
    		if ( n->childs_[i]){
    			char child = 'a' + i;
    			fetch_suggestions(n->childs_[i], s + child);
    		}
    	}
    }

};


int main(int argc, char const *argv[]) {
    Trie t;
    	t.insert("alice");

    	t.insert("ali");
    	t.insert("alibaker");
    	t.insert("alternate");
    	t.insert("aaa");
   
   	std::cout << "fetching suggestions for a : \n";
    t.show_autocomplete_recommendations("a");
    std::cout << "fetching suggestions for al : \n";
    t.show_autocomplete_recommendations("al");
    std::cout << "fetching suggestions for ali : \n";
    t.show_autocomplete_recommendations("ali");
    return 0;
}