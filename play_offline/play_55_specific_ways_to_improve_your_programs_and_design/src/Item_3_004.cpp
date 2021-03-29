#include <iostream>

class Item_3_004_Text_Block_Const
{
public:
	Item_3_004_Text_Block_Const(std::string s) :
			text_(s)
	{
	}

	~Item_3_004_Text_Block_Const()
	{
	}

	const char& operator[](const std::size_t pos) const
	{
		return text_[pos];
	}

private:
	std::string text_;

};

class Item_3_004_Text_Block_Non_Const
{
public:
	Item_3_004_Text_Block_Non_Const(std::string s) :
			text_(s)
	{
	}

	~Item_3_004_Text_Block_Non_Const()
	{
	}

	/**
	 * This throwns error here, becuase it discards qualifier
	 */
#if 0
	char& operator[] ( const std::size_t pos ) const
	{ 	return text_[ pos ]; }
	#endif

private:
	std::string text_;

};

int main(int argc, char const *argv[])
{
	Item_3_004_Text_Block_Non_Const tb(std::string("Hello"));
	//std::cout << "Non-Const Operator[] " << tb[0] << "\n"; 

	const Item_3_004_Text_Block_Const ctb(std::string("Hello"));
	std::cout << "Const Operator[] " << ctb[0] << "\n";

	return 0;
}
