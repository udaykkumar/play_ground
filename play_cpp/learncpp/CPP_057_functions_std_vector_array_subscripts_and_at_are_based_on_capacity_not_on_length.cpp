#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);

	std::cout << " v.size() : " << v.size() << std::endl;
	std::cout << " v.capacity() : " << v.capacity() << std::endl;
	std::cout << " v.at(1) : " << v.at(1) << std::endl;

	return 0;
}
