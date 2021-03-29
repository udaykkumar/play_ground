#include<iostream>
#include<vector>

int main()
{
	std::vector<int> v;
	std::cout << " v.size() : " << v.size() << std::endl;
	std::cout << " v.capacity() : " << v.capacity() << std::endl;

	for (int i = 0; i < 10; i++)
		v.push_back(i);

	std::cout << "Vector stats after inserting 10 elements " << std::endl;
	std::cout << " v.size() : " << v.size() << std::endl;
	std::cout << " v.capacity() : " << v.capacity() << std::endl;

	v.resize(20);
	std::cout << "Vector stats after v.resize(20) " << std::endl;
	std::cout << " v.size() : " << v.size() << std::endl;
	std::cout << " v.capacity() : " << v.capacity() << std::endl;

	v.erase(v.begin() + 7);
	std::cout << "Vector stats after v.erase( v.begin() + 7) " << std::endl;
	std::cout << " v.size() : " << v.size() << std::endl;
	std::cout << " v.capacity() : " << v.capacity() << std::endl;

	v.erase(v.begin() + 2);
	std::cout << "Vector stats after v.erase( v.begin() + 2) " << std::endl;
	std::cout << " v.size() : " << v.size() << std::endl;
	std::cout << " v.capacity() : " << v.capacity() << std::endl;

	return 0;
}
