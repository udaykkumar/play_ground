#include "Item_2_006.hpp"

const int Item_2_006_Logger_Example::LogLevel_ = 5;
int main(int argc, char const *argv[])
{
	/**
	 *	At this point any instanciation of Item_2_006_Logger_Example object
	 *	without declaring the LogLevel_ is going to cause a linker error
	 *
	 *  on the other hand this statement 
	 *  	Item_2_006_Logger_Example::LogLevel_ = 5;
	 *  within main will cause error again.. hence the one above
	 *  
	 */
	
	Item_2_006_Logger_Example le;
	std::cout << "LogLeve : "<< le.level() << "\n";
	return 0;
}