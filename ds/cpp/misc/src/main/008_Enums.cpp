#include <iostream>
#include <cstdlib>
#include <ctime>

#include "utils.hpp"

enum CardSuite {  Club, Diamond, Heart, Spade };

enum CardElement  { One, Two, Three, Four,
					Five, Six, Seven, Eight,
					Nine, Ten, Jack, Queen,
					King, Ace };

std::string SuiteString( CardSuite  s )
{
	switch(s) {
		case Club: return "Club";
		case Diamond: return "Diamond";
		case Heart: return "Heart";
		case Spade: return "Spade";
	}
	return "None";
}

std::string ElementString( CardElement  s )
{
	switch(s) {
		case One: return "One";
		case Two: return "Two";
		case Three: return "Three";
		case Four: return "Four";
		case Five: return "Five";
		case Six: return "Six";
		case Seven: return "Seven";
		case Eight: return "Eight";
		case Nine: return "Nine";
		case Ten: return "Ten";
		case Jack: return "Jack";
		case Queen: return "Queen";
		case King: return "King";
		case Ace: return "Ace";
	}
	return "None";
}



int main()
{

	CardSuite cs = static_cast<CardSuite>(utils::get_random_int(0,3));
	CardElement ce = static_cast<CardElement>(utils::get_random_int(0,12));

	std::cout << " Chosen Card is " 
			  << ElementString(ce) << " of " 
			  << SuiteString(cs) << std::endl;

	return 0; 
}