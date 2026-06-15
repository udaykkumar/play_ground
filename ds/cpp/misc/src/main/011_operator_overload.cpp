#include <iostream>

class Animal 
{
	protected:
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

	void operator=(const dog& d)
	{
		name_ = d.name_;
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

	dog d1 = d;
	cow c1 = c;

	std::cout << " This animal called " << d1.name() << " makes " << d1.sound() << " sound \n";
	std::cout << " This animal called " << c1.name() << " makes " << c1.sound() << " sound \n";

	return 0;
}