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
    
    void recurse( Node *root, vector<int> &v ) {
        if( root )
        {
            for( auto c : root->children )
                recurse( c , v);
            
            v.push_back(root->val);
        }
    }
    
public:
    vector<int> postorder(Node* root) {
        vector<int> r;
        recurse(root, r);
        return r;
    }
};