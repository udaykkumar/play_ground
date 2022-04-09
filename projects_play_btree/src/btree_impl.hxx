#include <iostream>
#include <memory>
#include <vector>

#define ENTRY                                     \
    do {                                          \
        std::cout << __PRETTY_FUNCTION__ << "\n"; \
    } while (0);

namespace ds {

const size_t BTree_Order { 8 };
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
class BTreeNodeList {
public:
    explicit BTreeNodeList(const KeyType& k, const ValueType& v)
        : m_key(k)
        , m_val(v)
        , m_left(nullptr)
        , m_right(nullptr)
        , m_next(nullptr)
    {
    }

    void put(const KeyType& k, const ValueType& v)
    {
        std::cout << "Add another "
                  << " [ " << k << " , " << v << " ] ";

        if (not m_next) {
            m_next = std::make_shared<BTreeNodeList<KeyType, ValueType>>(k, v);
            return;
        }
    }

    ValueType&& get(const KeyType& k)
    {
        ValueType v(1);
        return std::move(v);
    }

    const KeyType& key() const
    {
        return m_key;
    }

    const ValueType& value() const
    {
        return m_val;
    }

    std::shared_ptr<BTreeNodeList<KeyType, ValueType>>& next()
    {
        return m_next;
    }

    void show()
    {
        std::cout << " Keys ";
        std::cout << "  [ " << key() << " , " << value() << " ] ";
        for (auto crawl = m_next; crawl; crawl = crawl->next()) {
            std::cout << "  [ " << crawl->key() << " , " << crawl->value() << " ] ";
        }
        std::cout << "\n";
    }

private:
    KeyType m_key;
    ValueType m_val;
    std::shared_ptr<BTreeNodeList<KeyType, ValueType>> m_left;
    std::shared_ptr<BTreeNodeList<KeyType, ValueType>> m_right;
    std::shared_ptr<BTreeNodeList<KeyType, ValueType>> m_next;
    std::shared_ptr<BTreeNodeList<KeyType, ValueType>> m_prev;
};

template <typename KeyType, typename ValueType>
class BTreeNode {
public:
    explicit BTreeNode(const KeyType& k, const ValueType& v)
        : m_btree_nodes(std::make_unique<BTreeNodeList<KeyType, ValueType>>(k, v))
        , m_is_leaf(true)
    {
        ++m_no_of_keys;
    }

    void put(const KeyType& k, const ValueType& v)
    {
        if (!m_btree_nodes) {
            std::cout << " This is not even initialized and we should not be here\n";
            return;
        }

        /// There is room for this node to accomodate keys
        if (m_no_of_keys < Max_Keys_Per_Node) {
            m_btree_nodes->put(k, v);
        } else {
            std::cout << " We may need some magic here !!";
        }

        ++m_no_of_keys;
        m_btree_nodes->show();
    }

    ValueType&& get(const KeyType& k)
    {
        ValueType v(1);
        return std::move(v);
    }

    const size_t n_childs()
    {
        return 0;
    }

    const size_t n_keys()
    {
        return m_no_of_keys;
    }

    void show()
    {
        if (not m_btree_nodes) {
            std::cout << "Empty !!\n";
            return;
        }

        std::cout << " No of Keys " << m_no_of_keys << " isLeaf " << m_is_leaf;
        m_btree_nodes->show();
    }

private:
    std::unique_ptr<BTreeNodeList<KeyType, ValueType>> m_btree_nodes;
    bool m_is_leaf;
    size_t m_no_of_keys;
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
    if (!m_root) {
        m_root = std::make_unique<BTreeNode<KeyType, ValueType>>(k, v);
        return;
    }
    std::cout << "root " << m_root.get() << " nchilds " << m_root->n_childs() << " nkeys   " << m_root->n_keys() << "\n";
    m_root->put(k, v);
    m_root->show();
}

template <typename KeyType, typename ValueType>
ValueType&& BTree<KeyType, ValueType>::get(const KeyType& k)
{
    std::cout << "root " << m_root.get() << " nchilds " << m_root->n_childs() << " nkeys   " << m_root->n_keys() << "\n";
    return m_root->get(k);
}

} // namespace ds
