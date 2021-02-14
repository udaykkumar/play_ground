#include <iostream>

struct bad_add
{
	int x_;
		bad_add(int x) : x_(x) {}
		~bad_add() {}

	struct bad_add operator+ ( const struct bad_add& lhs )
	{
		return this->x_ + lhs.x_ ;
	}
};



struct good_add
{
	int x_;
		good_add(int x) : x_(x) {}
		~good_add() {}

	const struct good_add operator+ ( const struct good_add& lhs )
	{
		return this->x_ + lhs.x_ ;
	}
};

int main(int argc, char const *argv[])
{
	struct bad_add ba(1), bb(2);
	struct bad_add b = ba + bb ;

	// This is a bad expression, compiler should have caught it
	// but nope .. it doesn't
	(ba + bb) = b;

	struct good_add ga(1), gb(2);
	struct good_add g = ga + gb;

	// This raises an error and that is obviously a good catch
	//(ga + gb) = g;
	
	return 0;
}