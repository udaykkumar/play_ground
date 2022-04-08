#pragma once
#include <vector>
#include <memory>
#include <iostream>

#define ENTRY do { std::cout << __PRETTY_FUNCTION__ << "\n"; } while(0);

namespace ds{
	const size_t BTree_Order{ 3 };
	const size_t Max_Children{ BTree_Order };

	template<typename KeyType, typename ValueType>
	class BTreeNode {

	public:
		BTreeNode() : m_childs(Max_Children),
					  m_keys(Max_Children-1),
					  m_is_leaf(true) {
		}

		void put(const KeyType &k, const ValueType &v) {
			/// if the number of keys is 0 just put one and return
			if ( m_keys.size() == 0 ) {
				m_keys.emplace(k);
				return;
			}

		}

		ValueType&& get( const KeyType &k ) {
			ValueType v(1);
			return std::move(v);
		}

		const size_t n_childs() {
			return m_childs.size();
		}

		const size_t n_keys() {
			return m_keys.size();
		}

	private:
		std::vector< std::unique_ptr<BTreeNode<KeyType, ValueType>> > 	m_childs;
		std::vector< KeyType > m_keys;

		bool m_is_leaf;
	};



	template< typename KeyType, typename ValueType>
	BTree<KeyType, ValueType>::BTree() {
		m_root = std::make_unique< BTreeNode<KeyType, ValueType> >();
	}

	template< typename KeyType, typename ValueType>
	BTree<KeyType, ValueType>::~BTree() {
	}

	template< typename KeyType, typename ValueType>
	void BTree<KeyType, ValueType>::put(const KeyType &k, const ValueType &v) {
		std::cout << "root " << m_root << " nchilds " << m_root->n_childs() << "\n";
		m_root->put(k,v);
	}


	template< typename KeyType, typename ValueType>
	ValueType&& BTree<KeyType, ValueType>::get(const KeyType &k) {
		std::cout << "root " << m_root << " nchilds " << m_root->n_childs() << "\n";
		return m_root->get(k);
	}


}
