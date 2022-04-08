#pragma once
#include <iostream>
#include <memory>
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
class BTreeNode {
public:
    explicit BTreeNode(const KeyType &k, const ValueType &v)
        : m_key(k)
				, m_val(v)
				, m_left(nullptr)
				, m_right(nullptr)
				, m_next(nullptr)
        , m_is_leaf(true)
    {
    }

    void put(const KeyType& k, const ValueType& v)
		{

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
        return 0;
    }

    void show()
		{
			
		}

private:
    KeyType m_key;
    ValueType m_val;
    std::unique_ptr<BTreeNode<KeyType, ValueType>> m_left;
    std::unique_ptr<BTreeNode<KeyType, ValueType>> m_right;
    std::unique_ptr<BTreeNode<KeyType, ValueType>> m_next;
		bool m_is_leaf;
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
    std::cout << "root " << m_root
              << " nchilds " << m_root->n_childs()
              << " nkeys   " << m_root->n_keys() << "\n";
    m_root->put(k, v);
    m_root->show();
}

template <typename KeyType, typename ValueType>
ValueType&& BTree<KeyType, ValueType>::get(const KeyType& k)
{
    std::cout << "root " << m_root
              << " nchilds " << m_root->n_childs()
              << " nkeys   " << m_root->n_keys() << "\n";
    return m_root->get(k);
}

} // namespace ds
