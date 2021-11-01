#include "019_DoubleLinkedList.hpp"

namespace ds
{
	template <typename T>
	class DoubleNode
	{
		private:
			T 		value_;
			DoubleNode<T> *next_;

		public:
			DoubleNode( T v ) :
				value_(v),
				next_(nullptr)
			{

			}

			~DoubleNode( )
			{

			}

			DoubleNode<T>* & next() {
				return next_;
			}

			T value() {
				return value_;
			}
	};
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}