#include <merge_intervals.hpp>
#include <algorithm>
namespace lc
{
std::vector<std::vector<int> > merge(std::vector<std::vector<int> > &intervals)
{
	std::sort(intervals.begin(), intervals.end());
	if (intervals.size() == 0 or intervals.size() == 1)
		return intervals;

	std::vector<std::vector<int> > res;
	int start = intervals[0][0];
	int end = intervals[0][1];
	for (size_t i = 1; i < intervals.size(); ++i)
	{
		int s = intervals[i][0];
		int e = intervals[i][1];
		if (end < s)
		{
			res.push_back(
			{ start, end });
			start = s;
		}
		end = (end > e) ? end : e;
	}
	res.push_back(
	{ start, end });
	return res;
}
}

