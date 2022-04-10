#include <iostream>
#include <memory>
#include <tuple>
#include <vector>

/***
  _     ___   ____  ____ _____ ____  ____                    _   _   _ _____ ___ _     ___ _____ ___ _____ ____
 | |   / _ \ / ___|/ ___| ____|  _ \/ ___|    __ _ _ __   __| | | | | |_   _|_ _| |   |_ _|_   _|_ _| ____/ ___|
 | |  | | | | |  _| |  _|  _| | |_) \___ \   / _` | '_ \ / _` | | | | | | |  | || |    | |  | |  | ||  _| \___ \
 | |__| |_| | |_| | |_| | |___|  _ < ___) | | (_| | | | | (_| | | |_| | | |  | || |___ | |  | |  | || |___ ___) |
 |_____\___/ \____|\____|_____|_| \_\____/   \__,_|_| |_|\__,_|  \___/  |_| |___|_____|___| |_| |___|_____|____/

***/

#define ENTRY                                                   \
    do {                                                        \
        std::cout << "\nENTRY " << __PRETTY_FUNCTION__ << "\n"; \
    } while (0);

#define EXIT                                                   \
    do {                                                       \
        std::cout << "\nEXIT " << __PRETTY_FUNCTION__ << "\n"; \
    } while (0);

#define BTREE_LOG std::cout << __PRETTY_FUNCTION__ << " : "

/**

  ____ _____ ____  _____ _____   ____  ____    _   _
 | __ )_   _|  _ \| ____| ____| |  _ \/ ___|  | \ | | __ _ _ __ ___   ___  ___ _ __   __ _  ___ ___
 |  _ \ | | | |_) |  _| |  _|   | | | \___ \  |  \| |/ _` | '_ ` _ \ / _ \/ __| '_ \ / _` |/ __/ _ \
 | |_) || | |  _ <| |___| |___  | |_| |___) | | |\  | (_| | | | | | |  __/\__ \ |_) | (_| | (_|  __/
 |____/ |_| |_| \_\_____|_____| |____/|____/  |_| \_|\__,_|_| |_| |_|\___||___/ .__/ \__,_|\___\___|
                                                                              |_|

**/
namespace ds {

const size_t BTree_Order { 3 };
const size_t Max_Children { BTree_Order };
const size_t Max_Keys_Per_Node { Max_Children - 1 };

/**
  ____    _____                _   _           _
 | __ )  |_   _| __ ___  ___  | \ | | ___   __| | ___
 |  _ \    | || '__/ _ \/ _ \ |  \| |/ _ \ / _` |/ _ \
 | |_) |   | || | |  __/  __/ | |\  | (_) | (_| |  __/
 |____/    |_||_|  \___|\___| |_| \_|\___/ \__,_|\___|

**/

template <typename KeyType, typename ValueType>
struct BTreeNode : std::enable_shared_from_this<BTreeNode<KeyType, ValueType>> {

    int max_keys_;
    int cur_keys_;
    bool is_leaf_;
    std::vector<KeyType> keys_;
    std::vector<std::shared_ptr<BTreeNode<KeyType, ValueType>>> childs_;

    BTreeNode()
        : max_keys_(Max_Keys_Per_Node)
        , cur_keys_(0)
        , is_leaf_(true)
        , keys_(Max_Keys_Per_Node)
        , childs_(Max_Children)
    {
    }

    std::pair<std::shared_ptr<BTreeNode<KeyType, ValueType>>, int>
    find(const KeyType& k);

    void
    put(const KeyType& k, const ValueType& v);

    std::shared_ptr<BTreeNode<KeyType, ValueType>> sptr()
    {
        return this->shared_from_this();
    }

    bool is_full() const
    {
        return cur_keys_ == max_keys_;
    }
};

template <typename KeyType, typename ValueType>
void
BTreeNode<KeyType, ValueType>::put(const KeyType& k, const ValueType& v)
{
    BTREE_LOG << (*this) << "\n";
    if (is_leaf_) {
        int i = cur_keys_;
        while (i > 0 and keys_[i - 1] > k) {
            keys_[i] = keys_[i - 1];
            --i;
        }

        keys_[i] = k;
        cur_keys_++;
        EXIT;
        return;
    }
    return;
}

template <typename KeyType, typename ValueType>
std::pair<std::shared_ptr<BTreeNode<KeyType, ValueType>>, int>
BTreeNode<KeyType, ValueType>::find(const KeyType& k)
{
    BTREE_LOG << (*this) << "\n";
    int idx { cur_keys_ - 1 };

    while (idx >= 0 and k < keys_.at(idx)) {
        --idx;
    }

    BTREE_LOG << (*this) << " search " << k << " idx " << idx << "\n";
    if (idx >= 0 and k == keys_.at(idx)) {
        return std::make_pair(sptr(), idx);
    }

    if (is_leaf_ or idx == max_keys_ or idx < 0) {
        return std::make_pair(sptr(), -1);
    }

    return childs_.at(idx + 1)->find(k);
}

template <typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& os, BTreeNode<KeyType, ValueType> const& bnode)
{
    os << "{ BTreeNode : " << &bnode;
    os << " {  max_keys_ : " << bnode.max_keys_;
    os << "} , { cur_keys_ : " << bnode.cur_keys_;
    os << "} , { is_leaf_ : " << bnode.is_leaf_;
    os << "} , { keys : ";
    for (int index = 0; index < bnode.keys_.size(); ++index) {
        os << "{ " << index << ", " << bnode.keys_.at(index) << " } ";
    }

    os << "} , { childs : ";
    for (int index = 0; index < bnode.childs_.size(); ++index) {
        os << "{ " << index << ", " << bnode.childs_.at(index).get() << " } ";
    }

    os << "} ";
    return os;
}

/**
  ____ _____ ____  _____ _____
 | __ )_   _|  _ \| ____| ____|
 |  _ \ | | | |_) |  _| |  _|
 | |_) || | |  _ <| |___| |___
 |____/ |_| |_| \_\_____|_____|

**/

template <typename KeyType, typename ValueType>
void BTree<KeyType, ValueType>::put(const KeyType& k, const ValueType& v)
{
    ENTRY;
    BTREE_LOG << (*this) << " put [ " << k << "," << v << " ] \n";
    if (not m_root) {
        BTREE_LOG << (*this) << " root not initialized \n";
        EXIT;
        return;
    }

    auto fn = m_root->find(k);
    if (not fn.first) {
        std::cout << "Null .. ? \n";
        EXIT;
        return;
    }

    auto n = fn.first;
    auto idx = fn.second;
    BTREE_LOG << (*this) << " " << (*n) << " find returns " << n.get() << " " << idx << "\n";
    if (n->is_full()) {
        BTREE_LOG << (*this) << " max keys reached " << n.get() << "\n";
        BTREE_LOG << (*this) << " Adjust " << n.get() << "\n";
    } else if (idx >= 0) {
        BTREE_LOG << (*this) << " this key exists " << n.get() << "\n";
    } else {
        BTREE_LOG << (*this) << " there is room " << n.get() << "\n";
        n->put(k,v);
    }

    EXIT;
    return;
}

template <typename KeyType, typename ValueType>
ValueType&& BTree<KeyType, ValueType>::get(const KeyType& k)
{
    return 0;
}

template <typename KeyType, typename ValueType>
bool BTree<KeyType, ValueType>::exists(const KeyType& k)
{
    BTREE_LOG << (*this) << " Exists [ " << k << " ] \n";
    return false;
}

template <typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& os, BTree<KeyType, ValueType> const& bt)
{
    os << "{ BTree : " << &bt;
    os << "}";
    return os;
}

} // namespace ds
