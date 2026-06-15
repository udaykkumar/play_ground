#include <iostream>
#include <cstdlib>
#include <cstring>

class Item_3_005_CText_Block_Err
{
public:
	Item_3_005_CText_Block_Err()
	{
	}

	~Item_3_005_CText_Block_Err()
	{
	}

	std::size_t length() const
	{
		if (!lengthIsValid_)
		{
			// we are not supposed to do that
			//txtLength_ = std::strlen( text_ );  // Error

			// This is wrong because of bitwise constantness
			//lengthIsValid_ = true;	 // Error
		}

		return txtLength_;
	}

private:
	//char *text_;
	std::size_t txtLength_;
	bool lengthIsValid_;

};

class Item_3_005_CText_Block_Alternative
{
public:
	Item_3_005_CText_Block_Alternative()
	{
	}

	~Item_3_005_CText_Block_Alternative()
	{
	}

	std::size_t length() const
	{
		if (!lengthIsValid_)
		{
			// we can not do this thanks to mutable 
			txtLength_ = std::strlen(text_);
			lengthIsValid_ = true;
		}

		return txtLength_;
	}

private:
	char *text_;
	mutable std::size_t txtLength_;
	mutable bool lengthIsValid_;

};

int main(int argc, char const *argv[])
{
	Item_3_005_CText_Block_Err ctb;
	Item_3_005_CText_Block_Alternative ctba;
	return 0;
}
