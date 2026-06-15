#include <iostream>
#include "Item_2_005.hpp"

/** 
 * If you refer to the hpp file 
 * Players_ is not defined just declared as static and private
 *
 * now this is an impl.. and as long as the member is not dependent
 * like Players_ is --- see the Turns_ member which is eventhough static
 * is a need for scores_ --- we can initialize and define it here 
 *
 * how ever that is not the the case with Turns_ 
 *
 * any attempt to accesse these 
 * 	GamePlayer_Item2_005::Players_ or 
 * 	GamePlayer_Item2_005::Turns_ from within main or a function scope
 * will alert compiler to throw error
 *
 */
const int GamePlayer_Item2_005::Players_ = 7;

int main(int argc, char const *argv[])
{
	GamePlayer_Item2_005 gp;
	std::cout << gp.turns() << "\n";
	std::cout << gp.players() << "\n";
	return 0;
}
