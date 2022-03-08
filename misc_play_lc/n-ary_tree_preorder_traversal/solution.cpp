/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void recurse( Node *r, vector<int> &v )
    {
        if ( r )
        {
            v.push_back( r->val );
            for( auto c : r->children )
                recurse( c, v);
        }
    }
    
public:
    vector<int> preorder(Node* root) {
        vector<int> r;
        recurse( root, r);
        return r;
    }
};