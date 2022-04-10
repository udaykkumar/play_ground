#include <iostream>
#include <memory>
#include <tuple>
#include <vector>

#define ENTRY                                     \
    do {                                          \
        std::cout << __PRETTY_FUNCTION__ << "\n"; \
    } while (0);

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
    find(const KeyType& k)
    {
        int idx { cur_keys_ - 1 };

        while (idx >= 0 and k < keys_.at(idx)) {
            --idx;
        }

        std::cout << " search " << k << " idx " << idx << " keys_ \n"; // <<  keys_.at(idx) << "\n";
        if (idx >= 0 and k == keys_.at(idx)) {
            return std::make_pair(sptr(), idx);
        }

        if (is_leaf_ or idx == max_keys_ or idx < 0) {
            return std::make_pair(sptr(), -1);
        }

        return childs_.at(idx + 1)->find(k);
    }

    std::shared_ptr<BTreeNode<KeyType, ValueType>> sptr()
    {
        return this->shared_from_this();
    }
};

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
    std::cout << __PRETTY_FUNCTION__ << " put [ " << k << "," << v << " ] \n";
    if (not m_root) {
        std::cout << __PRETTY_FUNCTION__ << " root not initialized \n";
        return;
    }

    auto fn = m_root->find(k);
    if (not fn.first) {
        std::cout << "Null .. ? \n";
        return;
    }

    auto n = fn.first;
    auto idx = fn.second;
    std::cout << " find returns " << n.get() << " " << idx << "\n";
    if (idx == n->max_keys_) {
        std::cout << " max keys reached " << n.get() << "\n";
    } else if ( idx >= 0 ) {
      std::cout << " this key exists " << n.get() << "\n";
    }else {
        std::cout << " there is room " << n.get() << "\n";
        if (n->is_leaf_) {
            std::cout << " its a leaf lets put some " << n.get() << "\n";
            {
              int i = n->cur_keys_;
              while (i > 0 and  n->keys_[i-1] > k ) {
                n->keys_[i] = n->keys_[i-1];
                --i;
              }

              n->keys_[i] = k;
              n->cur_keys_ ++;
              return;
            }
        }
    }

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
    std::cout << __PRETTY_FUNCTION__ << " Exists [ " << k << " ] \n";
    return false;
}

} // namespace ds
