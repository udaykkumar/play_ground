/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if ( node == nullptr ) return node;
        
        /// No one to visit ..
        if ( node->neighbors.size() == 0 ) {
            return new Node(node->val);
        }
        
        std::unordered_map< Node *, Node * > memo;
        
        std::function< Node*(Node *) > clone = [&](Node *node) -> Node* {
            if ( node == nullptr ) return node;
            auto *cp = new Node( node->val) ;
            memo[node] = cp;
            for ( auto n : node->neighbors ) {
                if ( memo.find(n) != memo.end() ) {
                    cp->neighbors.emplace_back( memo[n] );
                } else {
                  cp->neighbors.emplace_back( clone(n) );
                 }
            }
            
            return cp;
        } ;
        return clone(node);
     }
};