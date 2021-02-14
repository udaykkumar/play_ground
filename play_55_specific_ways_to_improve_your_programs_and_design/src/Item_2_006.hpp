#ifndef __ITEM_2_006_HPP_INCLUDED__
#define __ITEM_2_006_HPP_INCLUDED__

#include <iostream>

class Item_2_006_Logger_Example
{
public:
	Item_2_006_Logger_Example()
	{
		std::cout << "IN : Item_2_006_Logger_Example()\n" ;
	}

	~Item_2_006_Logger_Example()
	{
		std::cout << "IN : ~Item_2_006_Logger_Example()\n" ;
	}
	
	/* Expose them */
	int level() const { return LogLevel_; }
private:
	static const int LogLevel_;
};
#endif
