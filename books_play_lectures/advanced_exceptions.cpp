#include <iostream>
#include <vector>

namespace myexception
{
namespace errors {
static const int SUCCESS  = 0;
static const int FAILURE  = -1;
static const std::string INFINITY = "infinity : Divide by zero";
static const std::string UNDEFNIED = "undefined : Zero by Zero";
static const std::string LARGE_DENOM = "always zeor : large Denominator";
}

namespace reason {
static const std::string INFINITY = "infinity : Divide by zero";
static const std::string UNDEFNIED = "undefined : Zero by Zero";
static const std::string LARGE_DENOM = "always zeor : large Denominator";
}

struct error_handler : std::exception
{

	int ec_;
	std::string reason_;

	error_handler(const int ec, const char *reason ) :
		ec_(ec),
		reason_(reason) {

	}

	error_handler(const int ec, const std::string reason ) :
		ec_(ec),
		reason_(reason) {

	}

	~error_handler() _NOEXCEPT
	{

	}

	void details() {
		std::cout << "{ ec " << ec_ << " reason_ " << reason_ << " }\n";
	}
};
}



void sanitize(int x , int y) {
	if ( x == 0 and y == 0 )
		throw myexception::error_handler( myexception::errors::FAILURE, myexception::reason::UNDEFNIED);
	if ( y == 0 )
		throw myexception::error_handler( myexception::errors::FAILURE, myexception::reason::INFINITY);
	if ( x > 0 and x < y )
		throw myexception::error_handler( myexception::errors::FAILURE, myexception::reason::LARGE_DENOM);
}

int divide(int x, int y) {
	sanitize(x, y);
	return x / y;
}

int main(int argc, char const *argv[])
{

	try {
		std::cout << "firstset \n";
		std::cout << "divide 1/1 " << divide(1, 1) << "\n";
		std::cout << "divide 0/0 " << divide(0, 0) << "\n";
		std::cout << "divide 1/2 " << divide(1, 2) << "\n";
		std::cout << "divide 2/1 " << divide(2, 1) << "\n";
		
	} catch ( myexception::error_handler &eh ) {
		eh.details();
	}


	std::vector < std::pair<int, int> > pairs ;
			 pairs.push_back( std::make_pair(1,1) );
			 	 pairs.push_back( std::make_pair(0,0) );
			 	 	 pairs.push_back( std::make_pair(1,2) );
			 	 	 	 pairs.push_back( std::make_pair(2,1) );

	std::cout << "second set \n";
	for ( auto p : pairs ) {
		auto x = p.first;
		auto y = p.second;

		try {
			std::cout << " divide " << x << "/" << y << " " << divide(x,y) << "\n";
		} catch ( myexception::error_handler &eh ) {
		eh.details();
	}
	}
	return 0;
}