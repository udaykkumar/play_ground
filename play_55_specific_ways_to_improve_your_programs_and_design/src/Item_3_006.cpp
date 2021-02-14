#include <iostream>

class Item_3_006_TextBlock
{
public:
	Item_3_006_TextBlock()
	{}

	~Item_3_006_TextBlock()
	{}



	const char& operator[] ( std::size_t position ) const
	{
		/**
		 * lots and lots of validations
		 * sanitations
		 * error checks
		 * etc 
		 * etc
		 * etc
		 * 
		 */
		
		return text_[ position ];
	}


	char& operator[] ( std::size_t position ) 
	{
		/**
		 * lots and lots of validations
		 * sanitations
		 * error checks
		 * etc 
		 * etc
		 * etc
		 *
		 * Simply say everything thats done above is duplicated results in
		 * bloating , compiletime, duplication etc etc etc yuckk
		 */
		return text_[ position ];
	}

private:
	std::string text_;
	
};

class Item_3_006_TextBlock_Alternative
{
public:
	Item_3_006_TextBlock_Alternative()
	{}

	~Item_3_006_TextBlock_Alternative()
	{}



	const char& operator[] ( std::size_t position ) const
	{
		/**
		 * Assuming it does these Ops
		 * 
		 * lots and lots of validations
		 * sanitations
		 * error checks
		 * etc 
		 * etc
		 * etc
		 * 
		 */
		
		return text_[ position ];
	}


	char& operator[] ( std::size_t position ) 
	{
		return const_cast< char& >(  static_cast< const Item_3_006_TextBlock_Alternative >(*this)[position] );
	}

private:
	std::string text_;
	
};

int main(int argc, char const *argv[])
{
	Item_3_006_TextBlock tb;
	Item_3_006_TextBlock_Alternative tba;

	return 0;
}

/**
 * Notes -
 * 		Declaring something as const helps compiler detect errors
 * 		Compilers only enforce bitwise constness, the program however should be using logical constness
 * 		Code duplication can be avoided by several means as above
 */