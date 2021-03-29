#include <insert_interval.hpp>

namespace lc
{
std::vector<std::vector<int>> insert(std::vector<std::vector<int>> &intervals,
		std::vector<int> &newInterval)
{

	std::vector<std::vector<int> > res;

	auto compare = [](const std::vector<int> x, std::vector<int> y) -> int 
	{
		return 0;
	};

	for (auto interval : intervals)
	{
		std::cout << "I am Here " << compare(interval, newInterval) << "\n";
	}
	return (res);
}
}

