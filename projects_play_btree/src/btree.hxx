#pragma once
#include <memory>

namespace ds {

template <typename KeyType = int, typename ValueType = int>
struct BTreeNode;

template <typename KeyType = int, typename ValueType = int>
class BTree {
private:
    int count_;
    std::shared_ptr<BTreeNode<KeyType, ValueType>> m_root;

public:
    BTree()
        : m_root(std::make_shared<BTreeNode<KeyType, ValueType>>())
    {
    }
    ~BTree() { }

    void put(const KeyType& k, const ValueType& v);
    ValueType&& get(const KeyType& t);
    bool exists(const KeyType& k);
};
} // namespace ds

#include "btree_impl.hxx"
