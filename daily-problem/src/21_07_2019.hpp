#ifndef __21_07_2019_HPP_INCLUDED__
#define __21_07_2019_HPP_INCLUDED__

namespace daily_interview
{
	struct bst
	{

	private:
		struct node
		{
			int 		 value_;
			struct node *left_;
			struct node *right_;

			node(const int x):
				value_(x), left_(nullptr), right_(nullptr) {}


			int get() 
			{ 
				return value_ ; 
			}

			struct node*&  left() 
			{ 
				return left_ ; 
			}

			struct node*&  right() 
			{ 
				return right_ ; 
			}
		};


	struct node* root_;


	void  add(node *&r, const int x);	
	void show(node* r);

	public:
		bst() :
			root_(nullptr){};

		void add(const int x);	
		void show();

		int  floor(int x);
		int  ceil(int x);
		
		
		node*& root() { return root_; }
	};
}
#endif