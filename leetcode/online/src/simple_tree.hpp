#ifndef __TREE_HPP_INCLUDED__
#define __TREE_HPP_INCLUDED__

namespace bira
{
template<typename valueType>
struct leaf
{
private:
	valueType v_;
	struct leaf<valueType> *left_, *right_;

public:
	leaf(const valueType v) :
			v_(v), left_(nullptr), right_(nullptr)
	{
	}

	valueType& get() const
	{
		return v_;
	}

	struct leaf<valueType>* left()
	{
		return left_;
	}
	struct leaf<valueType>* right()
	{
		return right_;
	}

};

template<typename valueType>
struct tree
{
	typedef struct leaf<valueType> nodeType_t;

private:
	nodeType_t *root_;
	nodeType_t*& root()
	{
		return root_;
	}

public:
	void add(const valueType v)
	{
		/* hmmm ..*/
	}

	bool exists(const valueType v)
	{

	}

	void show()
	{

	}

};
}

#endif
