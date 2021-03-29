#include <tuple>
#include <iostream>

std::tuple<int, double> returnTuple()
{
	return std::make_tuple(1, 2);
}

int main()
{
	auto [a, b] = returnTuple();
	std::cout << "intTuple 1st Element " << a << " 2nd Element " << b
			<< std::endl;

	return 0;
}
