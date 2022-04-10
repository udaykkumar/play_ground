#include <iostream>
#include <memory>
#include <queue>
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

#define BTREE_LOG_DEBUG std::cout << __PRETTY_FUNCTION__ << " : "
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

    std::shared_ptr<BTreeNode<KeyType, ValueType>> split();

    bool is_full() const
    {
        return cur_keys_ == max_keys_;
    }
};

template <typename KeyType, typename ValueType>
std::shared_ptr<BTreeNode<KeyType, ValueType>>
BTreeNode<KeyType, ValueType>::split()
{
    ENTRY;
    BTREE_LOG_DEBUG << (*this);

    /// Lets spin up a left node instance first blindly
    auto ln = std::make_shared<BTreeNode<KeyType, ValueType>>();
    auto parent = std::make_shared<BTreeNode<KeyType, ValueType>>();

    /// This is just the same instance as that of our current node *this
    ln->is_leaf_ = is_leaf_;

    /// Now get the mid this is easy
    auto mid { max_keys_ / 2 };
    auto mid_key { keys_[mid] };

    /// we copy everything from 0 -> mid all keys and children to the left node
    for (int i = 0; i < mid; ++i) {
        ln->keys_[i] = keys_[i];
        ln->childs_[i] = childs_[i];
    }
    /// also we make sure to copy mid child
    ln->childs_[mid] = childs_[mid];

    /// Now everythin from mid+1 to max_keys_ we slide them to
    /// 0 and above
    for (int i = mid + 1; i < max_keys_; i++) {
        keys_[i - (mid + 1)] = keys_[i];
        childs_[i - (mid + 1)] = childs_[i];
        keys_[i] = 0;
        childs_[i] = nullptr;
    }
    /// also we make sure to do this for last child
    childs_[Max_Children - 1] = nullptr;

    /// Update the current keys and childs values appropriately
    ln->cur_keys_ = mid;
    cur_keys_ = max_keys_ - (mid + 1);

    /// this to make a parent and ask him to adopt left and current

    parent->is_leaf_ = false;

    /// If Parent has keys ... unlikely .. but if it does
    /// make sure to find an appropriate place to insert this
    int i = parent->cur_keys_;
    while (i > 0 and parent->keys_[i - 1] > mid_key) {
        parent->keys_[i] = parent->keys_[i - 1];
        i--;
    }
    /// insert appropriately
    parent->keys_[i] = mid_key;
    int j = parent->cur_keys_ + 1;
    while (j > i) {
        parent->childs_[j + 1] = parent->childs_[j];
        j--;
    }

    /// Adoption time
    parent->childs_[j] = ln;
    parent->childs_[j + 1] = sptr();
    parent->cur_keys_++;
#if 0
#endif
    EXIT;
    /// and this is now going to be out node
    return parent;
}

template <typename KeyType, typename ValueType>
void BTreeNode<KeyType, ValueType>::put(const KeyType& k, const ValueType& v)
{
    BTREE_LOG_DEBUG << (*this) << "\n";
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
    int idx { cur_keys_ - 1 };

    while (idx >= 0 and k < keys_.at(idx)) {
        --idx;
    }

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
    os << " { max_keys_ : " << bnode.max_keys_;
    os << "} , { cur_keys_ : " << bnode.cur_keys_;
    os << "} , { is_leaf_ : " << bnode.is_leaf_;
    os << "} , { keys : ";
    for (size_t index = 0; index < bnode.keys_.size(); ++index) {
        os << "{ " << index << ", " << bnode.keys_.at(index) << " } ";
    }

    os << "} , { childs : ";
    for (size_t index = 0; index < bnode.childs_.size(); ++index) {
        os << "{ " << index << ", " << bnode.childs_.at(index).get() << " } ";
    }

    os << "} ";
    return os;
}

template <typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& os, std::shared_ptr<BTreeNode<KeyType, ValueType>> const& bnode)
{
    std::queue<std::shared_ptr<BTreeNode<KeyType, ValueType>>> qu;
    qu.push(bnode);
    while (not qu.empty()) {
        int count = qu.size();
        os << "||";
        while (count > 0) {
            auto top = qu.front();
            os << *top << "\n";
            qu.pop();
            for ( auto c : top->childs_ ) {
              if ( c ) {
                qu.push(c);
              }
            }
            os << "||";
            count--;
        }
        os << "\n";
    }
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
    BTREE_LOG_DEBUG <<  " put [ " << k << "," << v << " ] \n";
    if (not m_root) {
        BTREE_LOG_DEBUG << " root not initialized \n";
        EXIT;
        return;
    }

    auto fn = m_root->find(k);
    if (not fn.first) {
        std::cout << "Null .. ? \n";
        EXIT;
        return;
    }

    auto &n = fn.first;
    auto idx = fn.second;
    BTREE_LOG_DEBUG <<  " find returns " << n.get() << " " << idx << "\n";
    if (n->is_full()) {
        BTREE_LOG_DEBUG << " max keys reached " << n.get() << "\n";
        BTREE_LOG_DEBUG << " Adjust n.get() " << n.get() << " this "  << this << " mroot " << m_root.get() << "\n";

        m_root= n->split();
        BTREE_LOG_DEBUG << " Adjusted n.get() " << n.get() << " this "  << this << " mroot " << m_root.get() << "\n";
    } else if (idx >= 0) {
        BTREE_LOG_DEBUG << " this key exists " << n.get() << "\n";
    } else {
        BTREE_LOG_DEBUG << " there is room " << n.get() << "\n";
        n->put(k, v);
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
    BTREE_LOG_DEBUG << (*this) << " Exists [ " << k << " ] \n";
    return false;
}

template <typename KeyType, typename ValueType>
void BTree<KeyType, ValueType>::show()
{
    BTREE_LOG << "\n"  << m_root << "\n";
}

template <typename KeyType, typename ValueType>
std::ostream& operator<<(std::ostream& os, BTree<KeyType, ValueType> const& bt)
{
    os << "{ ";
    os << " BTree : " << &bt;
    os << " }";
    return os;
}

} // namespace ds
