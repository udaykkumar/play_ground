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

		virtual std::string sound() = 0;
		
		void GiveName( std::string name ) 
		{
			name_ = name;
		}

		std::string name() const
		{
			return name_;
		}
};


class dog : 
	public Animal
{
	public:
		dog(std::string name) :
			Animal(name)
		{

		}

	std::string sound() 
	{
		return "Woof-Woof";
	}
};

class cow : 
	public Animal
{
	public:
		cow(std::string name) :
			Animal(name)
		{

		}

	std::string sound() 
	{
		return "Mooo";
	}
};

int main()
{
	dog d("Alice");
	cow c("Bob");
	std::cout << " This animal called " << d.name() << " makes " << d.sound() << " sound \n";
	std::cout << " This animal called " << c.name() << " makes " << c.sound() << " sound \n";
	return 0;
}