#ifndef __17_07_2019_HPP_INCLUDED__
#define __17_07_2019_HPP_INCLUDED__

#include <vector>

namespace daily_bira
{
struct dose
{
	std::vector<int> list_;

	dose(std::vector<int> &v) :
			list_(v)
	{
	}

	void sort();
	std::vector<int>& get()
	{
		return list_;
	}
};
}
#endif
