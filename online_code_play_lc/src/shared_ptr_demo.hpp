#ifndef __shared_ptr_demo_HPP_INCLUDED__
#define __shared_ptr_demo_HPP_INCLUDED__

#include <iostream>
#include <memory>
#include <vector>

namespace daily_interview
{
struct shared
{
private:
	std::weak_ptr<std::vector<int> > sptr_;

public:

	shared();
	std::weak_ptr<std::vector<int> >& get();
	void put(int x);
	size_t size() const;

	// Equivalent to Show
	friend std::ostream& operator <<(std::ostream &out, shared &s)
	{
		if (auto sp = s.get().lock())
		{
			for (auto v : *sp)
				out << " " << v;
			out << std::endl;
		}
		return out;
	}
};
}

#endif
