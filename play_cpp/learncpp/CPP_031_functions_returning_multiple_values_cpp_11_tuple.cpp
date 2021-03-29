#include <tuple>
#include <iostream>

std::tuple<int, double> returnTuple()
{
	return std::make_tuple(1, 2);
}

std::tuple<int, int, double, char, int> returnMultiTuple()
{
	return std::make_tuple(1, 2, 4.2, 'E', 100);
}
int main()
{
	std::tuple<int, double> intTuple = returnTuple();
	std::cout << "intTuple 1st Element " << std::get<0>(intTuple)
			<< " 2nd Element " << std::get<1>(intTuple) << std::endl;

	std::tuple<int, int, double, char, int> multuTuple = returnMultiTuple();
	std::cout << "intTuple 1st Element " << std::get<0>(multuTuple)
			<< std::endl;
	std::cout << "intTuple 2nd Element " << std::get<1>(multuTuple)
			<< std::endl;
	std::cout << "intTuple 3rd Element " << std::get<2>(multuTuple)
			<< std::endl;
	std::cout << "intTuple 4th Element " << std::get<3>(multuTuple)
			<< std::endl;
	std::cout << "intTuple 5th Element " << std::get<4>(multuTuple)
			<< std::endl;
	return 0;
}
