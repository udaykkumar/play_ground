#include <iostream>

class Animal 
{
	private:
		std::string name_;

	public:

		Animal( std::string name ) :
			name_(name)
		{

		}
		
		void GiveName( std::string name ) 
		{
			name_ = name;
		}

		std::string name() const
		{
			return name_;
		}
};

int main(int argc, char const *argv[])
{
	Animal dog("Bob");
	std::cout << dog.name() << std::endl ;
		dog.GiveName("Alice");
	std::cout << dog.name()  << std::endl ;
	return 0;
}