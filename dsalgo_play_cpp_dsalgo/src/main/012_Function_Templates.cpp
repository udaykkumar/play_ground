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


template < typename T >
void do_something_with_the_animal(T& theAnimal)
{
	std::cout << " This animal called " << theAnimal.name() 
				<< " makes " << theAnimal.sound() << " sound \n";
}


int main()
{
	dog d("Alice");
	cow c("Bob");
	
	do_something_with_the_animal(d);
	do_something_with_the_animal(c);

	return 0;
}