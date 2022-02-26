#include <iostream>
#include <vector>
#include <memory>

namespace ds {

    const size_t Max_AlphaBets = 26;
    struct trie {

      private:
        /// forward declaration
        struct Node;

      public:
        void insert( std::string key ) {
        	std::cout << "inserting  key " << key << "\n";
        	if ( root_ ) {

        		/// Starting from the head of the Tree
        		auto crawl = root_;

        		/// for each character in word
        		for ( auto c : key ) {

        			/// make an index of it 
        			int index = key_to_index(c);

        			/// if there is a child at the index move ahead
        			/// if not create a child and move on
        			if ( not crawl->kids_[index] )
        				crawl->kids_[index] = std::make_shared<Node>();

        			/// Crawl with the child
        			crawl = crawl->kids_[index]; 
        		}

        		/// Mark that as End of Word
        		crawl->is_EOW_ = true; 

        	} else
        		throw new std::runtime_error("Trie uninitialized");
        }

        void suggestions( std::string key ) {
        	std::cout << "suggestions for key " << key << "\n";
        	if ( root_ ) {

        		/// First time first find the node first
        		auto crawl = root_;

        		for ( auto c : key ) {

        			/// make an index of it
        			int index = key_to_index(c);

        			/// if there a child we are good
        			/// else we have a problem
        			if ( not crawl->kids_[index] ) return;

        			/// Move down the tree
        			crawl = crawl->kids_[index];
        		}

        		if ( crawl->isLastNode() ) {
        			std::cout << key << "\n";
        			return;
        		}

        		fetch_suggestions(crawl, key);
        	} else
        		throw new std::runtime_error("Trie uninitialized");
        }

        trie() : root_( std::make_shared<Node>() ) {

        }

        ~trie() {

        }

      private:

        std::shared_ptr<Node> root_;

        /// Node
        struct Node {
            std::vector< std::shared_ptr<Node> >  kids_;
            bool 							     is_EOW_;

            Node() : kids_( Max_AlphaBets ), is_EOW_( false ) {

            }

            ~Node() {

            }

            bool isLastNode() const {
                for ( auto k : kids_ )
                    if ( k ) return false;
                return true;
            }
        };


        int key_to_index( const char c ) {
        	int index = (int)c - (int)'a';
        	return index;
        }

        void fetch_suggestions( std::shared_ptr<struct Node> &n, std::string s) {

	    	if ( n->is_EOW_ ) {
	    		std::cout << "\t\t" << s << "\n";
	    	}

	    	for ( size_t i = 0 ; i < Max_AlphaBets; ++i ) {
	    		if ( n->kids_[i]){
	    			char child = 'a' + i;
	    			fetch_suggestions(n->kids_[i], s + child);
	    		}
	    	}
	    }

    };
}


int main(int argc, char const *argv[]) {

    /* code */
    ds::trie t;
    	t.insert("abcd");
    	t.insert("abcde");
    	t.insert("abcdef");
    	t.insert("abcdefg");
    	t.insert("abccdefg");

    	t.suggestions("ab");
    return 0;
}