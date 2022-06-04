#include <iostream>


class X{

private:
int m;

public:
	X(int i = 0) : m{i} {

	}

	int mf(int i) {
		int old = m; m = i; 
		return old;
	}

};

int user(X var, X *ptr)
{
	int x = var.mf(7);		// access using . (dot)
	int y = ptr->mf(9); // access using arrow
	//int z = var.m;          // error: cannot access private member
}


int main(int argc, char const *argv[])
{
	X var{7}; // a variable of type X, initialized to 7
	return 0;
}