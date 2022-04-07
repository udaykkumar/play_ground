#pragma once
#include <vector>
#include <memory>

namespace ds{

	template<typename KeyType, typename ValueType>
	class BTreeNode {

	public:
		BTreeNode() {

		}

		void put(const KeyType &k, const ValueType &v) {

		}

		ValueType&& get( const KeyType &k ) {
			ValueType v(1);
			return std::move(v); 
		}

	private:
		std::vector< std::unique_ptr<BTreeNode<KeyType, ValueType>> > 	m_childs;
		std::vector< KeyType > 					  						m_keys;
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
		m_root->put(k,v);
	}


	template< typename KeyType, typename ValueType>
	ValueType&& BTree<KeyType, ValueType>::get(const KeyType &k) {
		return m_root->get(k);
	}

 
}
