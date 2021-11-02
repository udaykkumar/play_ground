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


template < typename T >
class AnimalTemplate
{
	private:
		T animal_;

	public:
		AnimalTemplate(T animal) : 
			animal_(animal)
		{

		}

		AnimalTemplate(std::string s) :
			animal_(s)
		{

		}

		void do_something()
		{
			std::cout << " This animal called " << animal_.name() 
				<< " makes " << animal_.sound() << " sound \n";
		}
};

int main()
{
	dog d("Alice");
	cow c("Bob");
	
	AnimalTemplate<dog> tdog(d);
	AnimalTemplate<cow> tcow(c);

	tdog.do_something();
	tcow.do_something();

	AnimalTemplate<dog> dg("Doggie");
	AnimalTemplate<cow> cw("Cowie");
	dg.do_something();
	cw.do_something();

	AnimalTemplate<dog>("Big Doggie").do_something();
	AnimalTemplate<cow>("Big Cowie").do_something();

	return 0;
}