#pragma once

#include <iostream>

namespace ds
{
	class list
	{
		private:
			int  count_;
			int *items_;


		public:
			list();
			~list();
		
			int  	get(int index);
        	void 	insert(int index, int val);
       	 	int 	search(int val);
        	void 	remove(int index);
        	int 	count() const;
	};
}
