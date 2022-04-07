#include <iostream>
#include <memory>
#include <vector>

/// A btree is a combination of
/// keys and children based on WIKI
/**
         According to Knuth's definition, a B-tree of order m is a tree which
 satisfies the following properties:[7]

        Every node has at most m children.
        Every internal node except the root has at least ⌈m/2⌉ children.
        Every non-leaf node has at least two children.
        All leaves appear on the same level and carry no information.
        A non-leaf node with k children contains k−1 keys.
        Each internal node's keys act as separation values which divide its
 subtrees. For example, if an internal node has 3 child nodes (or subtrees) then
 it must have 2 keys: a1 and a2. All values in the leftmost subtree will be less
 than a1, all values in the middle subtree will be between a1 and a2, and all
 values in the rightmost subtree will be greater than a2.

 **/

struct btree_node;
struct btree;
typedef int order_t;
typedef int key_t;
typedef std::shared_ptr<btree_node> btree_node_ptr_t;

struct btree_node {
  order_t m_order;
  std::vector<btree_node_ptr_t> m_childs; /// K Childs
  std::vector<key_t> m_keys;              /// K-1 keys
  bool m_is_leaf;

  btree_node(order_t order)
      : m_order(order), m_childs(order), m_keys(order - 1), m_is_leaf(true) {}

  int max_allowed_elements;
};

struct btree {

private:
  btree_node_ptr_t m_root_node;

public:
  btree(order_t order = 3) : m_root_node(std::make_shared<btree_node>(order)) {}

  void insert(key_t k) {}
};

int main(int argc, char const *argv[]) {
  std::cout << argv[0] << "\n";

  btree b;
  return 0;
}
