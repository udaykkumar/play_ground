#pragma once
#include <memory>

namespace ds {

template <typename KeyType = int, typename ValueType = int>
class BTreeNode;

template <typename KeyType = int, typename ValueType = int>
class BTree {
private:
    int count_;
    std::unique_ptr<BTreeNode<KeyType, ValueType>> m_root;

public:
    BTree() { }
    ~BTree() { }

    void put(const KeyType& t, const ValueType& v);
    ValueType&& get(const KeyType& t);
};
} // namespace ds

#include "btree_impl.hxx"
