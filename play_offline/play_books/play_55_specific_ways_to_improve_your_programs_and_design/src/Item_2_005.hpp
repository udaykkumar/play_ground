#ifndef __ITEM_2_005_HPP_INCLUDED__
#define __ITEM_2_005_HPP_INCLUDED__

class GamePlayer_Item2_005
{
public:
	GamePlayer_Item2_005()
	{
	}
	~GamePlayer_Item2_005()
	{
	}

	/**
	 * Now this function is needed to expose the Turns_ outside
	 * because these members are private there is no way
	 * one can access these from within a scope, be in even main, which again is a scope
	 * the onlything that can be done is initialize or read from a global scope
	 * see cpp file for how it is done.
	 * 
	 * @return [description]
	 */
	int turns() const
	{
		return Turns_;
	}
	int players() const
	{
		return Players_;
	}

private:

	static const int Players_;

	/**
	 * Turns_ needs definition because scores_ is dependent on this
	 * we can not do it the the way we did for Players_ 
	 * see cpp file for more details
	 *
	 * There is however a way to handle this case .. that is by using 
	 * 	"Enum Hack" technique
	 */
	static const int Turns_ = 5;
	int scores_[Turns_];
};

#endif
